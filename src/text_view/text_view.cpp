#include "text_view.hpp"

// LIBRE::TEXTVIEW::TEXTVIEW ---------------------------------------------------
// CONSTRUCTOR OF THE TEXTVIEW SETS THE DEFAULT SETTINGS OF THE CHILDREN
// -----------------------------------------------------------------------------

Libre::TextView::TextView(const std::string & info) {

	// ------------------------------------------
	// SET PROPERTIES OF THIS WIDGET AND OF ITS
	// CHILDREN
	// ------------------------------------------

	this->set_name("text_view");
	this->set_can_focus(true);
	this->set_focus_on_click(true);

	// ------------------------------------------
	// SET PROPERTIES FOR THE FOLLOWING CHILDREN:
	// 	* main -> CONTAINER FOR THE RESULTS
	// 	* information_text -> TEXT DISPLAYED WHEN
	//			PROGRAM STARTED OR SEARCHED EMPTY
	// 	* no_result_label -> DISPLAYED IF THERE
	//			ARE NO RESULTS
	// ------------------------------------------

	this->main.set_name("text_view");
	this->main.set_homogeneous(true);

	this->information_text.set_markup(info);
	this->information_text.set_justify(Gtk::JUSTIFY_CENTER);
	this->information_text.set_line_wrap(true);
	this->information_text.set_line_wrap_mode(Pango::WRAP_WORD);
	this->information_text.set_selectable(true);
	this->information_text.set_can_focus(false);

	this->no_result_label.set_markup("<span size=\"xx-large\">" + std::string(_("No Results")) + "</span>");
	this->no_result_label.set_justify(Gtk::JUSTIFY_CENTER);
	this->no_result_label.set_line_wrap(true);
	this->no_result_label.set_line_wrap_mode(Pango::WRAP_WORD);
	this->no_result_label.set_selectable(true);
	this->no_result_label.set_can_focus(false);
	this->no_result_label.set_name("no_result_label");

	// ------------------------------------------
	// * ADD OVERLAY TO THIS SCROLLED_WINDOW
	// * ADD THE information_text TO THE OVERLAY
	// * HIDE THE VERTICAL SCROLLBAR
	// ------------------------------------------

	this->add(this->overlay);
	this->overlay.add(this->information_text);
	this->get_vscrollbar()->hide();

	// ------------------------------------------
	// SET PROPERTIES OF THIS TEXTVIEW
	// AND ADD A TAB
	// ------------------------------------------

	this->padding_x = 10;
	this->padding_y = 10;
	this->max_verses = 20;
	this->tabs = 0;
	this->scroll_status = 0;
	this->scroll_sensitivity = 0.5;

}

// LIBRE::TEXTVIEW::SHOW_INFORMATION -------------------------------------------
// THIS FUNCTION DISPLAYES THE INFORMATION TEXT WICH WAS SET IN THE CONSTRUCTOR
// -----------------------------------------------------------------------------

void Libre::TextView::show_information() {
	this->overlay.set_halign(Gtk::ALIGN_CENTER);
	this->overlay.set_valign(Gtk::ALIGN_CENTER);
	this->overlay.remove();
	this->overlay.add(this->information_text);
	this->show_all();
}

// LIBRE::TEXTVIEW::SHOW_CONTENT -----------------------------------------------
// THIS FUNCTION DISPLAYES THE CONTENT OF THIS TEXTVIEW
// -----------------------------------------------------------------------------

void Libre::TextView::show_content() {
	this->verses[0].get_children()[0]->set_name("active_verse");
	this->overlay.set_halign(Gtk::ALIGN_FILL);
	this->overlay.set_valign(Gtk::ALIGN_FILL);
	this->overlay.remove();
	this->overlay.add(this->main);
	this->show_all();
}

// LIBRE::TEXTVIEW::SHOW_IF_RESULTS --------------------------------------------
// THIS FUNCTION DISPLAYES THE NO_RESULT_LABEL IF THERE ARE NO RESULTS
// -----------------------------------------------------------------------------

void Libre::TextView::show_if_results() {
	if (this->captions.size() == 0) {
		this->overlay.set_halign(Gtk::ALIGN_CENTER);
		this->overlay.set_valign(Gtk::ALIGN_CENTER);
		this->overlay.remove();
		this->overlay.add(this->no_result_label);
		this->show_all();
	}
}

// LIBRE::TEXTVIEW::CLEAR ------------------------------------------------------
// CLEARES THE CONTENT OF THE TEXTVIEW
// -----------------------------------------------------------------------------

void Libre::TextView::clear() {
	this->content.clear();
	this->captions.clear();

	this->scroll_status = 0;

	this->_display(0);
}

// LIBRE::TEXTVIEW::ADD_VERSE --------------------------------------------------
// ADDS VERSES GIVEN WITH ITS CAPTION
// -----------------------------------------------------------------------------

void Libre::TextView::add_verse(const std::string & caption, const std::vector<std::string *> & verses_content) {
	this->content.push_back({});
	for (int i = 0; i < this->tabs; i++) {
		this->content[this->content.size() - 1].push_back((verses_content[i] == nullptr ? "~~~" : *verses_content[i]));
	}

	this->captions.push_back(caption);

	this->_display(this->captions.size() - 1);
}

// LIBRE::TEXTVIEW::REPLACE_VERSE ----------------------------------------------
// REPLACE THE VERSE-VERSION GIVEN WITH THE CAPTION NAME
// -----------------------------------------------------------------------------

void Libre::TextView::replace_verse(const std::string & caption, const int & version, const std::string * verse_content) {
	int verse_id = std::distance(this->captions.begin(), std::find(this->captions.begin(), this->captions.end(), caption));
	this->content[verse_id][version] = (verse_content == nullptr ? "~~~" : *verse_content);

	this->_display((verse_id >= this->scroll_status && verse_id < (this->scroll_status + this->max_verses) ?
									verse_id - this->scroll_status : this->max_verses));
}

// LIBRE::TEXTVIEW::_DISPLAY ---------------------------------------------------
// THIS FUNCTION DISPLAYS EVERY WIDGET WHICH IS MENT TO BE DISPLAYED
// -----------------------------------------------------------------------------

void Libre::TextView::_display(int begin) {

	if (this->captions.size() != 0) {
		this->show_all();
		// ------------------------------------------
		// JUST DISPLAY THOSE VERSES WHICH CONATAIN
		// SOMETHING
		// ------------------------------------------

		for (int i = begin; i < this->max_verses; i++) {
			for (int x = 0; x < this->tabs; x++) {
				if (i < this->captions.size() - this->scroll_status) {
					this->c_labels[x][i].set_text(this->captions[i + this->scroll_status]);
					this->v_labels[x][i].set_markup(this->content[i + this->scroll_status][x]);
					this->verse_status[x][i].set_active((this->note_exists(this->captions[i + this->scroll_status]) ? true : false));
					this->verse_status[x][i].signal_released().connect([this, i]() {
							this->m_signal_toggle_note.emit(this->captions[i + this->scroll_status]);
							for (int x = 0; x < this->tabs; x++) {
							this->verse_status[x][i].set_active(true);
							}
							});
				} else {
					this->c_labels[x][i].hide();
					this->v_labels[x][i].hide();
					this->verse_status[x][i].hide();
				}
			}
		}
	}
}

// LIBRE::TEXTVIEW::ON_SCROLL_EVENT --------------------------------------------
// IF THE USER SCROLLS IN THE TEXTVIEW AREA THIS FUNCTION WILL BE CALLED. IT
// WILL JUMP TO THE TEXT OR THE LAST VERSE
// -----------------------------------------------------------------------------

bool Libre::TextView::on_scroll_event(GdkEventScroll * scroll_event) {

	if (this->captions.size() == 0) {
		return false;
	}

	this->scroll_status += (
		scroll_event->delta_y > this->scroll_sensitivity ?
		1 :
		(scroll_event->delta_y < -this->scroll_sensitivity ? -1 : 0));

	if (this->scroll_status < 0) {
		this->scroll_status = 0;

	} else if (this->scroll_status >= this->captions.size()) {
		this->scroll_status = this->captions.size() - 1;
	}

	this->_display(0);

	return false;
}

// LIBRE::TEXTVIEW::ON_KEY_PRESS_EVENT -----------------------------------------
// THIS FUNCTION IS CALLED WHEN A KEY IS PRESSED. IT IS ONLY USED TO SCOLL OR
// TO OPEN THE NOTE FOR ACTIVE VERSE (THE ONE ON THE TOP) IF ENTER IS PRESSED
// -----------------------------------------------------------------------------

bool Libre::TextView::on_key_press_event(GdkEventKey * key) {

	if (this->captions.size() == 0) {
		return true;
	}

	switch (key->keyval) {
		case 107: this->scroll_status -= 1; break;
		case 106: this->scroll_status += 1; break;
		case 65362: this->scroll_status -= 1; break;
		case 65364: this->scroll_status += 1; break;
		case 65293: this->m_signal_toggle_note.emit(this->captions[this->scroll_status]); break;
		default: break;
	}

	if (this->scroll_status < 0) {
		this->scroll_status = 0;
		this->error_bell();

	} else if (this->scroll_status >= this->captions.size()) {
		this->scroll_status = this->captions.size() - 1;
		this->error_bell();
	}

	if (this->main.is_visible()) {
		this->_display(0);
	}

	return true;
}

// LIBRE::TEXTVIEW::REMOVE_TAB -------------------------------------------------
// THIS FUNCTION REMOVES THE TAB AT THE *ID* PLACE
// -----------------------------------------------------------------------------

void Libre::TextView::remove_tab(const int & id) {
	this->source_paths.erase(this->source_paths.begin() + id);
	this->tabs--;

	this->verses[id].get_parent()->remove(this->verses[id]);

	for (int i = 0; i < this->max_verses; i++) {
		this->c_labels[id][i].get_parent()->remove(this->c_labels[id][i]);
		this->v_labels[id][i].get_parent()->remove(this->v_labels[id][i]);
		this->verse_status[id][i].get_parent()->remove(this->verse_status[id][i]);
	}

	this->verses.erase(this->verses.begin() + id);
	this->c_labels.erase(this->c_labels.begin() + id);
	this->v_labels.erase(this->v_labels.begin() + id);
	this->verse_status.erase(this->verse_status.begin() + id);

	for (int i = 0; i < this->content.size(); i++) {
		this->content[i].erase(this->content[i].begin() + id);
	}

	this->verses[0].get_children()[0]->set_name("active_verse");
}

// LIBRE::TEXTVIEW::APPEND_TAB -------------------------------------------------
// THIS FUNCTION APPENDS A NEW TAB AT THE END OF THE TEXTVIEW
// -----------------------------------------------------------------------------

void Libre::TextView::append_tab(const std::string & path) {

	this->source_paths.push_back(path);

	this->tabs++;

	this->verses.push_back(Gtk::VBox());
	this->v_labels.push_back({});
	this->c_labels.push_back({});
	this->verse_status.push_back({});

	this->verses[this->tabs - 1].set_name("text_view");
	this->verses[this->tabs - 1].set_border_width(5);

	for (int i = 0; i < this->max_verses; i++) {
		this->v_labels[this->tabs - 1].push_back(Gtk::Label());
		this->v_labels[this->tabs - 1][i].set_name("text_view");
		this->v_labels[this->tabs - 1][i].set_line_wrap(true);
		this->v_labels[this->tabs - 1][i].set_alignment(Gtk::ALIGN_START);
		this->v_labels[this->tabs - 1][i].set_line_wrap_mode(Pango::WRAP_WORD);
		this->v_labels[this->tabs - 1][i].set_selectable(true);
		this->v_labels[this->tabs - 1][i].set_can_focus(false);

		this->v_labels[this->tabs - 1][i].signal_populate_popup().connect(
			sigc::bind<int, int>(sigc::mem_fun(this, &Libre::TextView::label_populate_popup), this->tabs - 1, i)
		);

		this->c_labels[this->tabs - 1].push_back(Gtk::Label());
		this->c_labels[this->tabs - 1][i].set_name("text_view");
		this->c_labels[this->tabs - 1][i].set_line_wrap(true);
		this->c_labels[this->tabs - 1][i].set_alignment(Gtk::ALIGN_START);
		this->c_labels[this->tabs - 1][i].set_line_wrap_mode(Pango::WRAP_WORD);
		this->c_labels[this->tabs - 1][i].set_selectable(true);
		this->c_labels[this->tabs - 1][i].set_can_focus(false);

		this->verse_status[this->tabs - 1].push_back(Gtk::CheckButton());
		this->verse_status[this->tabs - 1][i].set_name("note_toggle");
		this->verse_status[this->tabs - 1][i].set_can_focus(false);

		Gtk::VBox * vbox = new Gtk::VBox;
		vbox->set_name("verse_box");
		Gtk::HBox * hbox = new Gtk::HBox;
		hbox->set_name("text_view");

		hbox->pack_start(this->c_labels[this->tabs - 1][i], Gtk::PACK_SHRINK, 0);
		hbox->pack_start(this->verse_status[this->tabs - 1][i], Gtk::PACK_SHRINK, 5);

		vbox->pack_start(*hbox, Gtk::PACK_SHRINK, 0);
		vbox->pack_start(this->v_labels[this->tabs - 1][i], Gtk::PACK_EXPAND_WIDGET, 0);

		this->verses[this->tabs - 1].pack_start(*vbox, Gtk::PACK_EXPAND_WIDGET, this->padding_x);
	}

	this->main.pack_start(this->verses[this->tabs - 1], Gtk::PACK_EXPAND_WIDGET, 5);

	for (int i = 0; i < this->content.size(); i++) {
		this->content[i].push_back("");
	}
}

// LIBRE::TEXTVIEW::LABEL_POPULATE_POPUP ---------------------------------------
// THIS FUNCTION IS CALLED IF RIGHTCLICKED ON THE VERSE. IT ADDS A *SEARCH*
// LABEL TO THE MENU
// -------------------------------------------------------------------------­­­­----

void Libre::TextView::label_populate_popup(Gtk::Menu * menu, int tab, int version) {
	int begin = 0;
	int end = 0;
	this->v_labels[tab][version].get_selection_bounds(begin, end);

	std::string selection = this->v_labels[tab][version].get_text().substr(begin, end - begin);

	if (!selection.empty()) {
		Gtk::MenuItem * search_item = new Gtk::MenuItem(std::string(_("Search")) + " \"" + selection + "\"");
		search_item->signal_button_release_event().connect([this, selection](GdkEventButton * b) -> bool {
			this->m_signal_right_click_search.emit(selection);
			return false;
		});

		SourceHandler source_handler;
		Libre::StrongMap * s_m = source_handler.get_strongs(this->source_paths[tab]);

		Gtk::SeparatorMenuItem * sep = new Gtk::SeparatorMenuItem;
		menu->prepend(*sep);

		std::string strong = (*s_m)[this->captions[version]][selection];

		if (!strong.empty()) {
			Gtk::MenuItem * strong_search_item = new Gtk::MenuItem(std::string(_("Search Strong")) + " \"" + strong + "\"");

			strong_search_item->signal_button_release_event().connect([this, strong](GdkEventButton * b) {
				this->m_signal_right_click_search("[str " + strong + "]");
				return false;
			});

			menu->prepend(*strong_search_item);
		}

		menu->prepend(*search_item);
		menu->show_all();
	}
}
