#include "signal_handler.hpp"

// SIGNALHANDLER::INIT ---------------------------------------------------------
// THIS FUNCTION WILL BE CALLED TO INITIALIZE THE FUNCTION.
// IT CREATES THE FIRST SEARCHENGINE, SETS THE HIGHLIGHT COLOR FOR THE RESULTS
// AND THE STYLE VERSION POSITION WHICH IS DISPLAYED ABOVE THE VERSE
// -----------------------------------------------------------------------------

void SignalHandler::init(Libre::Widgets * w) {

	// ------------------------------------------
	// CREATE THE SEARCH ENGINE FOR THE
	// FIRST TEXT_VIEW WITH SCHACHTER AS SOUCE
	// ------------------------------------------


	LOG("-- Init SignalHandler");

	this->widgets = w;

	SourceHandler source_handler;
	source_handler.set_names_path(HOME(this->widgets->settings.get_attribute("namesfile", "file")));


	this->widgets->package_manager.mtx.lock();
	this->widgets->package_manager.header_string = _("Init SearchEngine");
	this->widgets->package_manager.info_string = _("Load File");
	this->widgets->package_manager.mtx.unlock();
	this->widgets->package_manager.update_text.emit();

	if (this->settings.get_attribute("startupfile", "file").empty()) {
		this->settings.set("startupfile", "file", this->widgets->package_manager.get_sources().front());
	}

	this->widgets->search_engine.push_back(
		SearchEngine(this->widgets->package_manager.get_source_path(this->settings.get_attribute("startupfile", "file")))
	);

	// ------------------------------------------
	// GET HIGHLIGHT COLOR FROM THE CSS FILE
	// HAVE TO CONVERT RGB FLOATING POINT
	// COLOR (FOR EXAMPLE: rgb(0.1, 1, 0.4))
	// TO HEX COLOR (#BD8188)
	// ------------------------------------------

	this->widgets->package_manager.mtx.lock();
	this->widgets->package_manager.info_string = _("Fetch mark color");
	this->widgets->package_manager.mtx.unlock();
	this->widgets->package_manager.update_text.emit();

	Gdk::RGBA rgba;
	this->widgets->style.style->lookup_color("theme_highlight_color", rgba);

	std::string r, g, b;

	std::stringstream stream;
	stream << std::hex << static_cast<int>(rgba.get_red() * 255);
	r = stream.str();
	if (r.length() < 2) { r = "0" + r; }
	stream.str("");

	// ------------------------------------------
	// DO THE SAME THING WITH GREEN AS WITH RED
	// ------------------------------------------

	stream << std::hex << static_cast<int>(rgba.get_green() * 255);
	g += stream.str();
	if (g.length() < 2) { g = "0" + g; }
	stream.str("");

	// ------------------------------------------
	// DO THE SAME THING WITH GREEN AS WITH BLUE
	// ------------------------------------------

	stream << std::hex << static_cast<int>(rgba.get_blue() * 255);
	b += stream.str();
	if (b.length() < 2) { b = "0" + b; }

	// ------------------------------------------
	// SET STYLES FOR THE MARK AND HEADER
	// ------------------------------------------

	this->mark_argument = "<span font_weight=\"bold\" underline=\"single\" underline_color=\"#" + r + g + b + "\">$&</span>";
	this->header_argument = "<span font_weight=\"ultralight\">$&</span>";

	// ------------------------------------------
	// PASS THE STYLES TO THE SEARCHENGINE
	// ------------------------------------------

	this->widgets->search_engine[0].set_mark_argument(this->mark_argument);
}

// SIGNAL_HANDLER::SEARCH_REQUEST ----------------------------------------------
// THIS FUNCTION IS CALLED AFTER EVERY KEYPRESS WHEN THE SEARCH_ENTRY IS FOCUSED
// THE PRESSED KEY IS PASSED AS	A GdkEventKey. FIRST IT CHECKES IF THE ENTER KEY
// IS PRESSED, THEN IT WILL DISABLE ALL WIDGETS WHICH COULD INTERRUPT THE SEARCH
// PROCESS, SET THE REPLACE_ID TO -1 AND CREATE A THREAD WHICH EXECUTES THE
// DO_SEARCH FUNCTION (AS IN framework.cpp).
// -----------------------------------------------------------------------------

gboolean SignalHandler::search_request(GdkEventKey * event) {
	LOG("--> \"search_request\" emmited");
	// ------------------------------------------
	// IF ENTER IS PRESSED (KEYCODE: 65293)
	// ------------------------------------------

	if (event->keyval == 65293) {

		if (this->widgets->main.search_entry->get_text() == "") {
			this->widgets->main.text_view->show_information();
			this->widgets->main.text_view->clear();
			this->widgets->search_engine[0].set_search_argument("");
			return false;
		}

		this->trigger_search(this->widgets->main.search_entry->get_text());

	} else if (event->keyval == 65307) {
		this->widgets->main.text_view->grab_focus();
		this->widgets->main.search_entry->set_position(-1);
	}

	return false;
}

// SIGNALHANDLER::SOUCE_CHANGED ------------------------------------------------
// THIS FUNCTION IS CALLED AFTER A COMBOBOX, WHICH SETS DISPLAYED SOURCE OF THE
// TEXT_VIEW, HAS CHANGED. AS IN THE SEARCH_REQUEST FUNCTION THIS FUNCTION WILL
// NOT EXECUTE THE REPLACING PROCESS IT WILL ONLY CREATES A THREAD WHICH DOES IT
// -----------------------------------------------------------------------------

void SignalHandler::source_changed(Gtk::ComboBoxText * b) {

	LOG("--> \"source_changed\" emmited");

	// ------------------------------------------
	// FIRST WE WILL DISABLE ALL WIDGETS WHICH
	// COULD INTERRUPT THE REPLACING PROCESS
	// SAME AS IN THE SEARCH_REQUEST FUNCTION
	// ------------------------------------------

	for (int i = 0; i < this->widgets->main.combo_boxes.size(); i++) {
		this->widgets->main.combo_boxes[i]->set_button_sensitivity(Gtk::SENSITIVITY_OFF);
		this->widgets->main.close_buttons[i]->set_sensitive(false);
	}

	this->widgets->main.text_view->grab_focus();

	this->widgets->main.add_button->set_sensitive(false);

	this->widgets->main.search_entry->set_sensitive(false);
	this->widgets->main.history_button->set_sensitive(false);
	this->widgets->ui.action_group->set_sensitive(false);

	// ------------------------------------------
	// THE REPLACE_ID WILL BE SET TO THE SPECIFIC
	// INDEX TO REPLACE ONLY ONE TEXT_BUFFER
	// THIS WAY IS MORE EFFICIENT
	// ------------------------------------------

	this->widgets->processing.replace_id = 0;

	for (;this->widgets->processing.replace_id < this->widgets->main.combo_boxes.size(); this->widgets->processing.replace_id++) {
		// ------------------------------------------
		// IF B IS THE SAME AS THE COMBOBOX AT INDEX
		// REPLACE_ID.
		// ------------------------------------------
		if (b == this->widgets->main.combo_boxes[this->widgets->processing.replace_id]) {
			break;
		}
	}
	// ------------------------------------------
	// CREATE A PROCESS_THREAD WHICH CALLES THE
	// DO_REPLACEMENT FUNCTION
	// ------------------------------------------

	this->widgets->processing.process_thread = Glib::Thread::create(sigc::mem_fun(*this, &SignalHandler::do_replacement), true);
	LOG("--> \"do_replacement\" emmited");
}

// SIGNALHANDLER::SET_TEXT -----------------------------------------------------
// THIS FUNCTION SET THE TEXT_BUFFER THIS FUNCTION IS CALLED FROM A DISPATCHER
// THAT MEANS THIS FUNCTION IS EXECUTED BY THE GUI-THREAD BECAUSE ELSE IT WOULD
// DAMAGE THE MEMORY OF THE GUI DATA IS STORED AND THE PROGRAM CRASHES
// -----------------------------------------------------------------------------

void SignalHandler::set_text() {
	// ------------------------------------------
	// IF THE REPLACE_ID IS -1 IT WILL UPDATE
	// EVERY TEXT_BUFFER ELSE IT JUST UPDATES
	// A SPECIFIC TEXT_BUFFER
	// ------------------------------------------

	this->widgets->processing.process_mutex.lock();

	if (this->widgets->processing.replace_id == -1) {
		this->widgets->main.text_view->add_verse(
			this->widgets->processing.found_position,
			this->widgets->processing.found_verses
		);
	} else {
		this->widgets->main.text_view->replace_verse(
			this->widgets->processing.found_position,
			this->widgets->processing.replace_id,
			this->widgets->processing.found_verses.back()
		);
	}

	this->widgets->processing.procress_finished = true;

	this->widgets->processing.process_mutex.unlock();
}

// SIGNALHANDLER::DELETE_THREAD ------------------------------------------------
// THIS FUNCTION IS CALLED FROM A DISPATCHER WHICH WILL CALL THE GUI-THREAD AND
// THE GUI-THREAD WILL JOIN THE PROCESS_THREAD IF IT IS JOINABLE
// -----------------------------------------------------------------------------

void SignalHandler::delete_thread() {

	if (this->widgets->processing.process_thread->joinable()) {
		this->widgets->processing.process_thread->join();
	}

	if (this->widgets->main.search_entry->get_progress_fraction() != 0) {
		this->widgets->main.search_entry->set_progress_fraction(0);
	}

	this->widgets->main.number_results->set_text(std::to_string(this->widgets->search_engine[0].get_last_search_results()->size()) + " " + _("Results"));

	this->widgets->main.text_view->show_if_results();

	// ------------------------------------------
	// ENABLE EVERY WIDGETS WHICH WERE DISABLED
	// ------------------------------------------

	for (int i = 0; i < this->widgets->main.combo_boxes.size(); i++) {
		this->widgets->main.combo_boxes[i]->set_button_sensitivity(Gtk::SENSITIVITY_ON);
		this->widgets->main.close_buttons[i]->set_sensitive(true);
	}

	this->widgets->main.add_button->set_sensitive(true);

	this->widgets->main.search_entry->set_sensitive(true);
	this->widgets->main.history_button->set_sensitive(true);
	this->widgets->ui.action_group->set_sensitive(true);

	if (this->widgets->search_engine[0].get_last_search_results()->size() == 0) {
		this->widgets->main.search_entry->grab_focus();
	}
}

// SIGNALHANDLER::DO_SEARCH ----------------------------------------------------
// THIS FUNCTION WILL BE EXECUTED BY THE PROCESS_THREAD BECAUSE IF THE
// GUI-THREAD EXECUTES THIS FUNCTION OR THE DO_REPLACEMENT FUNCTION THE GUI WILL
// ONLY BE UPDATED AFTER THE PROCESS FINISHED AND THE USER WOULD NOT HAVE ANY
// FEEDBACK HOW LONG THIS PROCESS WILL TAKE
// -----------------------------------------------------------------------------

void SignalHandler::do_search() {

	// ------------------------------------------
	// SET THE SEARCH ARGUMENT
	// ------------------------------------------

	this->widgets->search_engine[0].set_search_argument(this->widgets->main.search_entry->get_text());

	// ------------------------------------------
	// THE SEARCH_ENGINE WILL SEARCH UNTIL THE
	// FIRST MATCH RETURN THAT VERSE THEN THOSE
	// VERSES WILL BE SEARCHED FOR THE OTHER
	// TEXT_BUFFERS WE SET THE BUFFER OVER THE
	// DISPATCHER AND SET THE PROGRESSBAR
	// ------------------------------------------

	this->widgets->processing.found_verses.clear();
	this->widgets->processing.found_verses.push_back(new std::string(""));

	while (this->widgets->search_engine[0].search(this->widgets->processing.found_verses[0])) {

		this->widgets->processing.process_mutex.lock();

		this->widgets->processing.found_position = this->widgets->search_engine[0].get_last_search_results()->back();

		// ------------------------------------------
		// SET THE SAME VERSES THE THE OTHER BUFFERS
		// ------------------------------------------

		for (int i = 1; i < this->widgets->search_engine.size(); i++) {
			this->widgets->processing.found_verses.push_back(this->widgets->search_engine[i].get_verse(this->widgets->processing.found_position));
		}

		this->widgets->processing.procress_finished = false;

		this->widgets->processing.process_mutex.unlock();

		this->widgets->processing.set_text_dispatcher.emit();

		while (!this->widgets->processing.procress_finished) { std::this_thread::yield(); }

		this->widgets->processing.process_mutex.lock();

		this->widgets->main.search_entry->set_progress_fraction(this->widgets->search_engine[0].get_progress());

		this->widgets->processing.found_verses.clear();
		this->widgets->processing.found_verses.push_back(new std::string(""));

		this->widgets->processing.process_mutex.unlock();
	}

	this->widgets->processing.delete_thread_dispatcher.emit();
}

// SIGNALHANDLER::DO_REPLACEMENT -----------------------------------------------
// THIS FUNCTION IS EXECUTED FROM THE PROCESS_THREAD LIKE THE DO_SEARCH FUNCTION
// IT REPLACES THE TEXT OF THE SPECIFIC BUFFER AT INDEX REPLACE_ID
// -----------------------------------------------------------------------------

void SignalHandler::do_replacement() {

	this->widgets->search_engine[this->widgets->processing.replace_id].set_source(
		this->widgets->package_manager.get_source_path(
			std::string(this->widgets->main.combo_boxes[this->widgets->processing.replace_id]->get_active_text())
		)
	);

	this->widgets->main.text_view->change_source(
		this->widgets->processing.replace_id,
		this->widgets->package_manager.get_source_path(
			std::string(this->widgets->main.combo_boxes[this->widgets->processing.replace_id]->get_active_text())
		)
	);

	std::vector<std::string> * v = this->widgets->search_engine[0].get_last_search_results();

	int x = 0;

	// ------------------------------------------
	// REPLACE BUFFER WITH NEW SOURCE CONTENT
	// -----------------------------------------

	this->widgets->processing.found_verses.clear();

	for (std::vector<std::string>::iterator i = v->begin(); i != v->end() && v->size() != 0; i++) {

		this->widgets->processing.process_mutex.lock();

		this->widgets->processing.procress_finished = false;
		this->widgets->processing.found_verses.push_back(this->widgets->search_engine[this->widgets->processing.replace_id].get_verse(*i));
		this->widgets->processing.found_position = *i;

		this->widgets->processing.process_mutex.unlock();

		this->widgets->processing.set_text_dispatcher.emit();

		while (!this->widgets->processing.procress_finished) { std::this_thread::yield(); }

		this->widgets->processing.process_mutex.lock();
		x++;
		this->widgets->main.search_entry->set_progress_fraction(x / static_cast<float>(v->size()));
		this->widgets->processing.process_mutex.unlock();
	}

	this->widgets->processing.delete_thread_dispatcher.emit();
}

// SIGNALHANDLER::QUIT ---------------------------------------------------------
// THIS FUNCTION IS CALLED WHEN CTRL-Q PRESSED, IT ONLY QUITS THE APPLICATION
// -----------------------------------------------------------------------------

void SignalHandler::quit() {
	this->widgets->app->quit();
}

// SIGNALHANDLER::TOGGLE_FULLSCREEN --------------------------------------------
// THIS FUNCTION IS CALLED WHEN F11 PRESSED OR "VIEW/TOGGLE FULLSCREEN" PRESSED
// -----------------------------------------------------------------------------

void SignalHandler::toggle_fullscreen() {
	LOG("--> \"toggle_fullscreen\" emmited");
	if (this->widgets->main.is_fullscreen)
		this->widgets->main.window->unfullscreen();
	else
		this->widgets->main.window->fullscreen();

	this->widgets->main.is_fullscreen = !this->widgets->main.is_fullscreen;
}

// SIGNALHANDLER::TOGGLE_ICONIFY -----------------------------------------------
// THIS FUNCTION IS CALLED WHEN CTRL-M PRESSED OR "VIEW/MINIMIZE" PRESSED
// -----------------------------------------------------------------------------

void SignalHandler::toggle_iconify() {
	LOG("--> \"toggle_iconify\" emmited");
	this->widgets->main.window->iconify();
}

// SIGNALHANDLER::TOGGLE_SEARCH ------------------------------------------------
// THIS FUNCTION IS CALLED WHEN CTRL-F PRESSED OR "EDIT/SEARCH" PRESSED
// -----------------------------------------------------------------------------

void SignalHandler::toggle_search() {
	LOG("--> \"toggle_search\" emmited");
	this->widgets->main.search_entry->grab_focus();
}

// SIGNALHANDLER::TOGGLE_PREFERENCES -------------------------------------------
// THIS FUNCTION IS CALLED WHEN CTRL-, PRESSED OR "EDIT/PREFERENCES" PRESSED
// -----------------------------------------------------------------------------

void SignalHandler::toggle_preferences() {
	LOG("--> \"toggle_preferences\" emmited");
	this->widgets->preferences.window->show_all();
	this->widgets->preferences.window->raise();
}

// SIGNALHANDLER::ZOOM_IN ------------------------------------------------------
// THIS FUNCTION IS CALLED WHEN CTRL-+ PRESSED OR "VIEW/ZOOM_IN" PRESSED
// -----------------------------------------------------------------------------

void SignalHandler::zoom_in() {
	LOG("--> \"zoom_in\" emmited");
	this->widgets->style.font_size += 2;
	this->widgets->style.font_size_css->load_from_data("* { font-size: " + std::to_string(this->widgets->style.font_size) + "px; }");
}

// SIGNALHANDLER::ZOOM_OUT -----------------------------------------------------
// THIS FUNCTION IS CALLED WHEN CTRL-- PRESSED OR "VIEW/ZOOM_OUT" PRESSED
// -----------------------------------------------------------------------------

void SignalHandler::zoom_out() {
	LOG("--> \"zoom_out\" emmited");
	this->widgets->style.font_size -= 2;
	if (this->widgets->style.font_size < 1) {
		this->widgets->style.font_size = 1;
	}
	this->widgets->style.font_size_css->load_from_data("* { font-size: " + std::to_string(this->widgets->style.font_size) + "px; }");
}

// SIGNALHANDLER::ZOOM_RESET ---------------------------------------------------
// THIS FUNCTION IS CALLED WHEN CTRL-= PRESSED OR "VIEW/ZOOM_RESET" PRESSED
// -----------------------------------------------------------------------------

void SignalHandler::zoom_reset() {
	LOG("--> \"zoom_reset\" emmited");
	this->widgets->style.font_size = std::stoi(this->settings.get_attribute("font", "size"));
	this->widgets->style.font_size_css->load_from_data("* { font-size: " + std::to_string(this->widgets->style.font_size) + "px; }");
}

// SIGNALHANDLER::THEME_CHANGED ------------------------------------------------
// THIS FUNCTION IS CALLED THE THEME CHANGED. THE THEME CAN BE SET BY THE USER
// IN THE PREFERENCES UNDER "INTERFACE/THEME". THIS FUNCTION LOADS A NEW CSS
// -----------------------------------------------------------------------------

void SignalHandler::theme_changed() {
	LOG("--> \"theme_changed\" emmited");
	this->settings.set("themes", "active", this->widgets->preferences.theme_combo->get_active_text());

	if(!this->widgets->style.css->load_from_path(DATA(this->widgets->preferences.theme_combo->get_active_text() + ".css"))) {
			std::cerr << "Failed to load css\n";
	}
}

// SIGNALHANDLER::DEFAULT_FONT_SIZE_CHANGED ------------------------------------
// THIS FUNCTION IS CALLED THE DEFAULT FONT SIZE CHANGED. SAVE SETTINGS AND
// LOAD NEW CSS FILE
// -----------------------------------------------------------------------------

void SignalHandler::default_font_size_changed() {
	LOG("--> \"default_font_size_changed\" emmited");
	this->widgets->style.font_size = this->widgets->preferences.font_size_spinbutton->get_value();
	this->settings.set("font", "size", std::to_string(this->widgets->style.font_size));
	this->widgets->style.font_size_css->load_from_data("* { font-size: " + std::to_string(this->widgets->style.font_size) + "px; }");
}

// SIGNALHANDLER::ADD_SOURCE ---------------------------------------------------
// THIS FUNCTION ADDS THE SOURCE AT THE END OF THE TEXT_VIEW_BOX AND ADD A
// HEADER TO THE NEW TEXT_VIEW WITH CLOSE_BUTTONS AND COMBOBOX.
// -----------------------------------------------------------------------------

void SignalHandler::add_source() {
	LOG("--> \"add_source\" emmited");

	// ------------------------------------------
	// ADD A NEW SEARCH ENGINE AND SET ITS ARGS
	// ------------------------------------------

	this->widgets->search_engine.push_back(
		SearchEngine(
			this->widgets->package_manager.get_source_path(this->settings.get_attribute("startupfile", "file")))
	);

	this->widgets->search_engine.back().set_mark_argument(this->mark_argument);

	// ------------------------------------------
	// ADD PANEL AND CONNECT THE BUTTONS
	// ------------------------------------------

	this->widgets->add_panel();
	this->widgets->main.text_view->append_tab(this->widgets->package_manager.get_source_path(this->settings.get_attribute("startupfile", "file")));

	this->widgets->main.combo_boxes.back()->signal_changed().connect(
		sigc::bind<Gtk::ComboBoxText *>(
		sigc::mem_fun(this, &SignalHandler::source_changed),
		this->widgets->main.combo_boxes.back()),
		false
	);

	this->widgets->main.close_buttons.back()->signal_clicked().connect(
		sigc::bind<Gtk::Button *>(
		sigc::mem_fun(this, &SignalHandler::remove_source_by_reference),
		this->widgets->main.close_buttons.back()),
		false
	);

	this->widgets->main.add_button->signal_clicked().connect(sigc::mem_fun(this, &SignalHandler::add_source), false);

	// ------------------------------------------
	// DISPLAY THE NEW PANEL
	// ------------------------------------------

	this->widgets->main.panels->show_all();
	this->source_changed(this->widgets->main.combo_boxes.back());
}

// SIGNALHANDLER::REMOVE_SOURCE ------------------------------------------------
// THIS FUNCTION REMOVES THE LAST PANEL OF THE TEXT_VIEW_BOX. IT IS ONLY CALLED
// IF YOU PRESSED CTRL-D OR "VIEW/REMOVE SOURCE" PRESSED. WHEN THE CLOSE_BUTTON
// WAS PRESSED THE REMOVE_SOURCE_BY_REFERENCE FUNCTION IS CALLED
// -----------------------------------------------------------------------------

void SignalHandler::remove_source() {
	LOG("--> \"remove_source\" emmited");
	if (this->widgets->search_engine.size() > 1) { // IF THERE IS JUST ONE SOURCE IT DOES NOT REMOVE IT

		// ------------------------------------------
		// DELETE THE BACK OF EVERY VECTOR AND DELETE
		// THE LAST PANEL. TO HAVE NO DATA LACK IT
		// GETS THE POINTERS (t, c, h) TO DELETE THEM
		// ------------------------------------------

		this->widgets->search_engine.pop_back();

		this->widgets->main.panels->remove(*this->widgets->main.panels->get_children().back());

		Gtk::ComboBoxText * c = this->widgets->main.combo_boxes.back();
		Gtk::HBox * h = this->widgets->main.headers.back();
		this->widgets->main.combo_boxes.pop_back();
		this->widgets->main.headers.pop_back();

		delete h;
		delete c;
		delete this->widgets->main.add_button;

		// ------------------------------------------
		// NOW IT ADDS THE ADD_BUTTON TO THE NEW BACK
		// ------------------------------------------

		this->widgets->main.add_button = new Gtk::Button;
		this->widgets->main.add_button->set_image_from_icon_name("list-add", Gtk::ICON_SIZE_BUTTON);
		this->widgets->main.add_button->set_name("add_button");
		this->widgets->main.add_button->set_always_show_image(true);
		// Gtk::Image * img = new Gtk::Image(DATA("res/add.svg"));
		// this->widgets->main.add_button->set_image(*img);

		this->widgets->main.headers.back()->pack_end(*this->widgets->main.add_button, Gtk::PACK_SHRINK, 0);
		this->widgets->main.headers.back()->reorder_child(*this->widgets->main.add_button, 0);
		this->widgets->main.add_button->signal_clicked().connect(sigc::mem_fun(this, &SignalHandler::add_source), false);

		this->widgets->main.add_button->show();

		this->widgets->main.text_view->remove_tab(this->widgets->search_engine.size());
	}
}

// SIGNALHANDLER::REMOVE_SOURCE_BY_REFERENCE -----------------------------------
// THIS FUNCTION REMOVE A SPECIFIC SOURCE_PANEL. IT IS CALLED IF THE
// CLOSE_BUTTON IS PRESSED
// -----------------------------------------------------------------------------

void SignalHandler::remove_source_by_reference(Gtk::Button * b) {
	LOG("--> \"remove_source_by_reference\" emmited");
	if (this->widgets->search_engine.size() > 1) {

		// ------------------------------------------
		// BECAUSE THIS FUNCTION JUST HAS A POINTER
		// AS ARGUMENT IT ITERATES THRUE THE VECTOR
		// TO COMPATE IT WITH THE ARGUMENT
		// ------------------------------------------

		std::vector<std::string> last_search_results = *this->widgets->search_engine[0].get_last_search_results();

		int i = 0;
		for (;i < this->widgets->main.close_buttons.size(); i++) {
			if (b == this->widgets->main.close_buttons[i]) {
				this->widgets->main.close_buttons.erase(this->widgets->main.close_buttons.begin() + i);
				delete b;
				break;
			}
		}

		 // ------------------------------------------
		 // REMOVE WIDGETS AT INDEX I
		 // SIMILAR TO THE REMOVE_SOURCE FUNCTION
		 // ------------------------------------------

		this->widgets->search_engine.erase(this->widgets->search_engine.begin());

		this->widgets->main.panels->remove(*this->widgets->main.panels->get_children()[i]);

		Gtk::ComboBoxText * c = this->widgets->main.combo_boxes[i];
		Gtk::HBox * h = this->widgets->main.headers[i];
		this->widgets->main.combo_boxes.erase(this->widgets->main.combo_boxes.begin() + i);
		this->widgets->main.headers.erase(this->widgets->main.headers.begin() + i);

		delete h;
		delete c;

		// ------------------------------------------
		// MOVE THE ADD_BUTTON IF NECESSARY
		// ------------------------------------------

		if (this->widgets->main.add_button != nullptr && i != this->widgets->main.close_buttons.size()) {
			this->widgets->main.add_button->get_parent()->remove(*this->widgets->main.add_button);
			delete this->widgets->main.add_button;
			this->widgets->main.add_button = new Gtk::Button;
		}

		this->widgets->main.add_button->set_name("add_button");
		this->widgets->main.add_button->set_always_show_image(true);
		// Gtk::Image * img = new Gtk::Image(DATA("res/add.svg"));
		// this->widgets->main.add_button->set_image(*img);

		this->widgets->main.headers.back()->pack_end(*this->widgets->main.add_button, Gtk::PACK_SHRINK, 0);
		this->widgets->main.headers.back()->reorder_child(*this->widgets->main.add_button, 0);

		this->widgets->main.add_button->signal_clicked().connect(sigc::mem_fun(this, &SignalHandler::add_source), false);

		this->widgets->main.add_button->show();

		// ------------------------------------------
		// IT STORES THE LAST SEARCH RESULT IN THE
		// NEW FIRST SEARCH ENGINE FOR THE CASE
		// THE SOURCE OF A PANEL CHANGES AFTER THAT
		// ------------------------------------------

		this->widgets->search_engine[0].set_last_search_result(last_search_results);
		this->widgets->main.text_view->remove_tab(i);

	}
}

// SIGNALHANDLER::ADD_SOURCE_DIR -----------------------------------------------
// THIS FUNCTION CREATES A NEW DIALOG_WINDOW, ASKS FOR THE URL AND INSTALLES THE
// NEW SOURCES FROM THE GIVEN GIT REPOSITORY
// -----------------------------------------------------------------------------

void SignalHandler::add_source_dir() {
	LOG("--> \"add_source_dir\" emmited");
	// ------------------------------------------
	// CHECK IF THE DIALOG WINDOW IS EXISTING
	// IF TRUE DELETE IT AND CREATE AN NEW ONE
	// ------------------------------------------

	if (this->widgets->dialog.window != nullptr) {
		delete this->widgets->dialog.window;
	}
	this->widgets->dialog.window = new Gtk::Window;
	this->widgets->dialog.window->set_title(_("Add source directory"));
	this->widgets->dialog.window->set_default_size(500, 100);
	this->widgets->dialog.window->set_keep_above(true);
	this->widgets->dialog.window->set_resizable(false);
	this->widgets->dialog.window->set_position(Gtk::WIN_POS_CENTER);

	// ------------------------------------------
	// CREATE THE ROOT BOX FOR THE DIALOG WINDOW
	// ------------------------------------------

	Gtk::VBox * box = new Gtk::VBox;
	box->set_border_width(10);
	box->set_spacing(10);

	// ------------------------------------------
	// CREATE THE WIDGETS FOR THE DIALOG WINDOW
	// ------------------------------------------

	Gtk::Label * url_label = new Gtk::Label(_("Enter the url of your git source repository:"));

	Gtk::Entry * url_entry = new Gtk::Entry;
	url_entry->set_placeholder_text(_("url: example.org/your/source.git"));

	Gtk::HBox * button_container = new Gtk::HBox;
	button_container->set_spacing(10);

	Gtk::Button * ok_button = new Gtk::Button(_("Ok"));
	Gtk::Button * cancel_button = new Gtk::Button(_("Cancel"));

	button_container->pack_end(*ok_button, Gtk::PACK_SHRINK, 0);
	button_container->pack_end(*cancel_button, Gtk::PACK_SHRINK, 0);

	box->pack_start(*url_label, Gtk::PACK_SHRINK, 0);
	box->pack_start(*url_entry, Gtk::PACK_SHRINK, 0);
	box->pack_start(*button_container, Gtk::PACK_SHRINK, 0);

	this->widgets->dialog.window->add(*box);

	this->widgets->dialog.window->show_all();

	// ------------------------------------------
	// CONNECT SIGNALS
	// ------------------------------------------

	ok_button->signal_clicked().connect([url_entry, this]() {
		this->widgets->dialog.window->close();
		Glib::Thread::create([url_entry, this]() {
			this->widgets->package_manager.install(url_entry->get_text());
			this->widgets->processing.sync_sources_dispatcher.emit();
		});
	}, false);

	url_entry->signal_key_press_event().connect([ok_button](GdkEventKey * event) -> gboolean {
		if (event->keyval == 65293) {
			ok_button->clicked();
		}
		return false;
	}, false);

	cancel_button->signal_clicked().connect([this]() { this->widgets->dialog.window->close(); });
}

// SIGNALHANDLER::REMOVE_SOURCE_DIR --------------------------------------------
// THIS FUNCTION IS CALLED WHEN THE REMOVE BUTTON IN THE BOOK MANAGER IS PUSHED
// -----------------------------------------------------------------------------

void SignalHandler::remove_source_dir() {
	LOG("--> \"remove_source_dir\" emmited");

	// ------------------------------------------
	// DELETE THE OLD WINDOW AND CREATE A NEW ONE
	// ------------------------------------------

	if (this->widgets->dialog.window != nullptr) {
		delete this->widgets->dialog.window;
	}

	this->widgets->dialog.window = new Gtk::Window;
	this->widgets->dialog.window->set_title(_("Add source directory"));
	this->widgets->dialog.window->set_default_size(300, 100);
	this->widgets->dialog.window->set_keep_above(true);
	this->widgets->dialog.window->set_resizable(false);
	this->widgets->dialog.window->set_position(Gtk::WIN_POS_CENTER);

	// ------------------------------------------
	// CREATE ALL WIDGETS AND THEIR PROPERTIES
	// ------------------------------------------

	Gtk::VBox * box = new Gtk::VBox;
	box->set_border_width(10);
	box->set_spacing(10);

	Gtk::Label * path_label = new Gtk::Label(_("Chose the repository you want to be removed:"));
	Gtk::ComboBoxText * combo = new Gtk::ComboBoxText;

	Gtk::HBox * button_container = new Gtk::HBox;
	button_container->set_spacing(10);

	Gtk::Button * ok_button = new Gtk::Button(_("OK"));
	Gtk::Button * cancel_button = new Gtk::Button(_("Cancel"));

	// ------------------------------------------
	// PACK WIDGETS TO THE DIALOG WINDOW
	// ------------------------------------------

	button_container->pack_end(*ok_button, Gtk::PACK_SHRINK, 0);
	button_container->pack_end(*cancel_button, Gtk::PACK_SHRINK, 0);

	box->pack_start(*path_label, Gtk::PACK_SHRINK, 0);
	box->pack_start(*combo, Gtk::PACK_SHRINK, 0);
	box->pack_start(*button_container, Gtk::PACK_SHRINK, 0);

	std::vector<std::string> packages = this->widgets->package_manager.get_packages();

	for (int i = 0; i < packages.size(); i++) {
		combo->append(packages[i]);
	}

	combo->set_active(0);

	this->widgets->dialog.window->add(*box);
	this->widgets->dialog.window->show_all();

	// ------------------------------------------
	// CONNECT FUNCTIONS TO BUTTONS
	// ------------------------------------------

	ok_button->signal_clicked().connect([combo, this]() {
		this->widgets->dialog.window->close();
		Glib::Thread::create([combo, this]() {
			this->widgets->package_manager.remove(combo->get_active_text());
			this->widgets->processing.sync_sources_dispatcher.emit();
		});
	});

	cancel_button->signal_clicked().connect([this]() {
		this->widgets->dialog.window->close();
	});
}

// SIGNALHANDLER::SYNC_ENABLED_SOURCES -----------------------------------------
// THIS FUNCTION SYNCS THE SOURCES AND REMOVES THE DISABLED SOURCES
// FROM THE COMBOBOXES
// -----------------------------------------------------------------------------

void SignalHandler::sync_enabled_sources() {
	LOG("--> \"sync_enabled_sources\" emmited");

	// ------------------------------------------
	// SYNC THE COMBO BOXES
	// ------------------------------------------

	this->widgets->preferences.default_source_combo->remove_all();
	this->widgets->append_sources(this->widgets->preferences.default_source_combo);

	for (int i = 0; i < this->widgets->main.combo_boxes.size(); i++) {
		Gtk::HBox * parent = this->widgets->main.headers[i];
		std::vector<Gtk::Widget *> v = parent->get_children();

		int pos = std::distance(v.end(), std::find(v.begin(), v.end(), this->widgets->main.combo_boxes[i]));

		delete this->widgets->main.combo_boxes[i];
		this->widgets->main.combo_boxes[i] = new Gtk::ComboBoxText;

		parent->pack_end(*this->widgets->main.combo_boxes[i], Gtk::PACK_SHRINK, 0);
		parent->reorder_child(*this->widgets->main.combo_boxes[i], pos);

		this->widgets->main.combo_boxes[i]->show();

		this->widgets->append_sources(this->widgets->main.combo_boxes[i]);

		this->widgets->main.combo_boxes[i]->signal_changed().connect(
			sigc::bind<Gtk::ComboBoxText *>(
			sigc::mem_fun(this, &SignalHandler::source_changed),
			this->widgets->main.combo_boxes[i]),
			false
		);

	}

	// ------------------------------------------
	// SYNC THE CHECKBUTTONS IN THE BOOK MANAGER
	// ------------------------------------------

	for (std::vector<std::string>::iterator i = this->widgets->package_manager.get_sources().begin(); i != this->widgets->package_manager.get_sources().end(); i++) {
		delete this->widgets->preferences.sources_check[*i];
	}

	this->widgets->preferences.sources_check.clear();

	std::vector<Gtk::Widget *> v = this->widgets->preferences.book_manager_box->get_children();

	for (std::vector<Gtk::Widget *>::iterator i = v.begin(); i != v.end(); i++) {
		this->widgets->preferences.book_manager_box->remove(*(*i));
	}

	for (std::vector<std::string>::iterator i = this->widgets->package_manager.get_sources().begin(); i != this->widgets->package_manager.get_sources().end(); i++) {
		Gtk::HBox * book_container = new Gtk::HBox;
		Gtk::Label * book_title = new Gtk::Label(*i, Gtk::ALIGN_START);
		this->widgets->preferences.sources_check[*i] = new Gtk::CheckButton;

		this->widgets->preferences.sources_check[*i]->set_active(this->widgets->package_manager.is_enabled(*i));

		book_container->pack_start(*book_title, Gtk::PACK_SHRINK, 0);
		book_container->pack_end(*this->widgets->preferences.sources_check[*i], Gtk::PACK_SHRINK, 0);
		this->widgets->preferences.book_manager_box->pack_start(*book_container, Gtk::PACK_SHRINK, 0);

		this->widgets->preferences.book_manager_box->show_all();

		this->widgets->preferences.sources_check[*i]->signal_clicked().connect([this, i]() {
			(this->widgets->preferences.sources_check[*i]->get_active() ?
				this->widgets->package_manager.enable(*i) : this->widgets->package_manager.disable(*i));
				this->sync_enabled_sources();
		});
	}
}

void SignalHandler::toggle_note(std::string position) {
	LOG("--> \"toggle_note\" emmited");
	if (position == "") {
		this->widgets->main.note_paned->set_position(this->widgets->main.note_paned->get_height());
		this->widgets->main.note_book->save_note();
		this->widgets->main.text_view->grab_focus();
	} else {
		if (this->widgets->main.note_paned->get_position() > this->widgets->main.note_paned->get_height() - 50) {
			this->widgets->main.note_paned->set_position(this->widgets->main.note_paned->get_height() * 2 / 3);
		}
		this->widgets->main.note_book->open_note(position);
		this->widgets->main.note_book->grab_focus();
	}
}

void SignalHandler::trigger_search(const std::string & text) {

	this->widgets->main.history_button->add_to_history(text);
	this->widgets->main.search_entry->set_text(text);

	this->widgets->main.number_results->set_text(_("Searching"));

	this->widgets->main.text_view->show_content();
	this->widgets->main.text_view->grab_focus();

	// ------------------------------------------
	// DISABLE ALL WIDGETS
	// ------------------------------------------

	for (int i = 0; i < this->widgets->main.combo_boxes.size(); i++) {
		this->widgets->main.combo_boxes[i]->set_button_sensitivity(Gtk::SENSITIVITY_OFF);
		this->widgets->main.close_buttons[i]->set_sensitive(false);
	}

	this->widgets->main.text_view->clear();

	this->widgets->main.add_button->set_sensitive(false);

	this->widgets->main.search_entry->set_sensitive(false);
	this->widgets->ui.action_group->set_sensitive(false);

	this->widgets->processing.replace_id = -1;

	// ------------------------------------------
	// CREATE A NEW PROCESS_THREAD
	// ------------------------------------------

	this->widgets->processing.process_thread = Glib::Thread::create(
		sigc::mem_fun(*this, &SignalHandler::do_search), true
	);
	LOG("--> \"do_search\" emmited");
}

void SignalHandler::export_notes() {
	Gtk::Window * pos_dialog = new Gtk::Window;
	pos_dialog->set_position(Gtk::WIN_POS_CENTER);
	pos_dialog->set_border_width(5);
	Gtk::VBox * box = new Gtk::VBox(false, 5);
	Gtk::Label * l = new Gtk::Label(_("Passage"));
	Gtk::Entry * e = new Gtk::Entry;
	Gtk::HBox * button_container = new Gtk::HBox(false, 10);
	Gtk::Button * ok_button = new Gtk::Button(_("Select"));
	Gtk::Button * cancel_button = new Gtk::Button(_("Cancel"));

	button_container->pack_end(*ok_button);
	button_container->pack_end(*cancel_button);
	box->pack_start(*l);
	box->pack_start(*e);
	box->pack_start(*button_container);
	pos_dialog->add(*box);
	pos_dialog->set_resizable(false);
	pos_dialog->show_all();
	
	ok_button->signal_clicked().connect([this, pos_dialog, e]() {
		pos_dialog->hide();
		pos_dialog->remove();
		delete pos_dialog;

		Gtk::FileChooserDialog dialog(*this->widgets->main.window, _("Choose Directory"), Gtk::FILE_CHOOSER_ACTION_SAVE);
		dialog.add_button(_("Select"), Gtk::ResponseType::RESPONSE_OK);
		dialog.add_button(_("Cancel"), Gtk::ResponseType::RESPONSE_CANCEL);
		dialog.add_choice("suffix", _("Type"), {".md"}, {"Markdown"});
		dialog.set_choice("suffix", ".md");
		dialog.set_create_folders(true);

		int response = dialog.run();
		dialog.hide();

		if (response == Gtk::ResponseType::RESPONSE_OK) {
			std::string pos = e->get_text();
			std::string file_name = dialog.get_uri().substr(7);
			std::string source_file = this->widgets->package_manager.get_source_path(this->settings.get_attribute("startupfile", "file"));

			if (file_name.substr((file_name.find_last_of(".") == std::string::npos ? 0 : file_name.find_last_of(".")), std::string::npos) != dialog.get_choice("suffix")) {
				file_name += dialog.get_choice("suffix");
			}

			this->widgets->main.note_book->export_note(
				pos,
				file_name,
				source_file
			);
		}
	});

	cancel_button->signal_clicked().connect([pos_dialog]() {
			pos_dialog->hide();
			pos_dialog->remove();
			delete pos_dialog;
	});
}
