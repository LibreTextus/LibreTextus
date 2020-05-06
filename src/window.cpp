#include "window.hpp"

// LIBRE::MAINWINDOW::CREATE ---------------------------------------------------
// THIS FUNCTION CREATES THE MAIN WINDOW
// -----------------------------------------------------------------------------

bool Libre::MainWindow::create(Libre::Widgets * w, SignalHandler * s) {

	// ------------------------------------------
	// CREATE A NEW WINDOW AND ITS PROPERTIES
	// ------------------------------------------

	w->window = new Gtk::Window;
	w->window->set_default_size(1000, 800);
	w->window->set_title("LibreTextus");
	w->window->set_icon_from_file(DATA("Icon.svg"));
	w->window->set_position(Gtk::WIN_POS_CENTER);
	w->is_fullscreen = false;

	// ------------------------------------------
	// ADD THE ROOT VBOX TO THE WINDOW
	// ------------------------------------------

	Gtk::VBox * v_box = new Gtk::VBox(false, 0);
	w->window->add(*v_box);

	// ------------------------------------------
	// CREATE THE MENUBAR FOR THE WINDOW
	// ------------------------------------------

	w->action_group = Gtk::ActionGroup::create();

	// ------------------------------------------
	// CREATE FILE MENU
	// ------------------------------------------

	w->action_group->add(Gtk::Action::create("FileMenu", Gtk::Stock::FILE));

	// ------------------------------------------
	// CREATE QUIT MENU
	// ------------------------------------------

	w->action_group->add(Gtk::Action::create("FileNewTab", "New Tab"),
			Gtk::AccelKey("<control>T"));
	w->action_group->add(Gtk::Action::create("FileCloseTab", "Close Tab"),
			Gtk::AccelKey("<control>W"));
	w->action_group->add(Gtk::Action::create("FileQuit", Gtk::Stock::QUIT),
					sigc::mem_fun(s, &SignalHandler::quit));

	// ------------------------------------------
	// CREATE EDIT MENU
	// ------------------------------------------

	w->action_group->add(Gtk::Action::create("EditMenu", Gtk::Stock::EDIT));
	w->action_group->add(Gtk::Action::create("EditCut", Gtk::Stock::CUT));
	w->action_group->add(Gtk::Action::create("EditCopy", Gtk::Stock::COPY));
	w->action_group->add(Gtk::Action::create("EditPaste", Gtk::Stock::PASTE));
	w->action_group->add(Gtk::Action::create("EditFind", Gtk::Stock::FIND),
			Gtk::AccelKey("<control>F"), sigc::mem_fun(s, &SignalHandler::toggle_search));
	w->action_group->add(Gtk::Action::create("EditPreferences", Gtk::Stock::PREFERENCES),
			Gtk::AccelKey(',', Gdk::ModifierType::CONTROL_MASK), sigc::mem_fun(s, &SignalHandler::toggle_preferences));

	// ------------------------------------------
	// CREATE VIEW MENU
	// ------------------------------------------

	w->action_group->add(Gtk::Action::create("ViewMenu", "View"));
	w->action_group->add(Gtk::Action::create("ViewAddSource", "Add Source"),
			Gtk::AccelKey("<control>N"), sigc::mem_fun(s, &SignalHandler::add_source));
	w->action_group->add(Gtk::Action::create("ViewRemoveSource", "Remove Source"),
			Gtk::AccelKey("<control>D"), sigc::mem_fun(s, &SignalHandler::remove_source));
	w->action_group->add(Gtk::Action::create("ViewToggleNotes", "Toggle Notes"),
			Gtk::AccelKey("<control><alt>N"));
	w->action_group->add(Gtk::Action::create("ViewToggleComments", "Toggle Comments"),
			Gtk::AccelKey("<control><alt>C"));
	w->action_group->add(Gtk::Action::create("ViewZoomIn", Gtk::Stock::ZOOM_IN),
			Gtk::AccelKey('+', Gdk::ModifierType::CONTROL_MASK), sigc::mem_fun(s, &SignalHandler::zoom_in));
	w->action_group->add(Gtk::Action::create("ViewZoomOut", Gtk::Stock::ZOOM_OUT),
			Gtk::AccelKey('-', Gdk::ModifierType::CONTROL_MASK), sigc::mem_fun(s, &SignalHandler::zoom_out));
	w->action_group->add(Gtk::Action::create("ViewZoomReset", Gtk::Stock::ZOOM_100),
			Gtk::AccelKey('=', Gdk::ModifierType::CONTROL_MASK), sigc::mem_fun(s, &SignalHandler::zoom_reset));
	w->action_group->add(Gtk::Action::create("ViewMinimize", "Minimize"),
			Gtk::AccelKey("<control>M"), sigc::mem_fun(s, &SignalHandler::toggle_iconify));
	w->action_group->add(Gtk::Action::create("ViewToggleFullscreen", Gtk::Stock::FULLSCREEN),
			Gtk::AccelKey("F11"), sigc::mem_fun(s, &SignalHandler::toggle_fullscreen));

	// ------------------------------------------
	// CREATE HISTORY MENU
	// ------------------------------------------

	w->action_group->add(Gtk::Action::create("HistoryMenu", "History"));
	w->action_group->add(Gtk::Action::create("HistoryBack", Gtk::Stock::GO_BACK),
			Gtk::AccelKey("<control>Z"));
	w->action_group->add(Gtk::Action::create("HistoryForward", Gtk::Stock::GO_FORWARD),
			Gtk::AccelKey("<control><shift>Z"));

	// ------------------------------------------
	// CREATE HELP MENU
	// ------------------------------------------

	w->action_group->add(Gtk::Action::create("HelpMenu", Gtk::Stock::HELP));
	w->action_group->add(Gtk::Action::create("HelpGetHelp", Gtk::Stock::HELP));
	w->action_group->add(Gtk::Action::create("HelpAbout", Gtk::Stock::ABOUT));

	// ------------------------------------------
	// ADD UIMANAGER ACCEL GROUP TO THE WINDOW
	// ------------------------------------------

	w->ui_manager = Gtk::UIManager::create();
	w->ui_manager->insert_action_group(w->action_group);

	w->window->add_accel_group(w->ui_manager->get_accel_group());

	Glib::ustring ui_info =
				"<ui>"
				"	<menubar name='MenuBar'>"
				"		<menu action='FileMenu'>"
				"			<menuitem action='FileNewTab'/>"
				"			<menuitem action='FileCloseTab'/>"
				"			<separator/>"
				"			<menuitem action='FileQuit'/>"
				"		</menu>"
				"		<menu action='EditMenu'>"
				"			<menuitem action='EditCut'/>"
				"			<menuitem action='EditCopy'/>"
				"			<menuitem action='EditPaste'/>"
				"			<separator/>"
				"			<menuitem action='EditFind'/>"
				"			<separator/>"
				"			<menuitem action='EditPreferences'/>"
				"		</menu>"
				"		<menu action='ViewMenu'>"
				"			<menuitem action='ViewAddSource'/>"
				"			<menuitem action='ViewRemoveSource'/>"
				"			<separator/>"
				"			<menuitem action='ViewToggleNotes'/>"
				"			<menuitem action='ViewToggleComments'/>"
				"			<separator/>"
				"			<menuitem action='ViewZoomIn'/>"
				"			<menuitem action='ViewZoomOut'/>"
				"			<menuitem action='ViewZoomReset'/>"
				"			<separator/>"
				"			<menuitem action='ViewMinimize'/>"
				"			<menuitem action='ViewToggleFullscreen'/>"
				"		</menu>"
				"		<menu action='HistoryMenu'>"
				"			<menuitem action='HistoryBack'/>"
				"			<menuitem action='HistoryForward'/>"
				"		</menu>"
				"		<menu action='HelpMenu'>"
				"			<menuitem action='HelpGetHelp'/>"
				"			<menuitem action='HelpAbout'/>"
				"		</menu>"
				"	</menubar>"
				"</ui>";

	try {
		w->ui_manager->add_ui_from_string(ui_info);
	}
	catch(const Glib::Error& ex) {
		std::cerr << "building menus failed: " <<  ex.what();
	}

	// ------------------------------------------
	// ADD MENUBAR TO THE WINDOW
	// ------------------------------------------

	Gtk::Widget * pMenubar = w->ui_manager->get_widget("/MenuBar");
	if(pMenubar) {
		v_box->pack_start(*pMenubar, Gtk::PACK_SHRINK);
	}


	// ------------------------------------------
	// CREATE SEARCHENTRY AND SET ITS PROPERTIES
	// ------------------------------------------

	w->search_entry = new Gtk::SearchEntry;

	w->search_entry->set_placeholder_text("Search");

	w->add_button = nullptr;

	// ------------------------------------------
	// ADD THE STARTUP PANEL TO THE WINDOW
	// ------------------------------------------

	w->panels = new Gtk::HBox(false, 0);
	w->panels->set_spacing(5);
	w->panels->set_border_width(5);
	w->panels->set_homogeneous(true);
	w->add_panel();

	w->text_view = new Libre::TextView(w->settings.get<std::string>("splash_text"));
	w->text_view->signal_toggle_note().connect(sigc::mem_fun(s, &SignalHandler::toggle_note));

	Gtk::VBox * note_container = new Gtk::VBox;

	Gtk::Button * note_close = new Gtk::Button;
	note_close->set_image_from_icon_name("window-close", Gtk::ICON_SIZE_BUTTON);
	note_close->set_name("view_button");
	note_close->signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(s, &SignalHandler::toggle_note), ""));
	Gtk::HBox * note_header = new Gtk::HBox;
	note_header->set_border_width(10);
	note_header->pack_end(*note_close, Gtk::PACK_SHRINK, 0);

	w->note_book = new Libre::NoteBook(note_header);
	w->is_note_book_open = false;

	note_container->pack_start(*note_header, Gtk::PACK_SHRINK, 0);
	note_container->pack_start(*w->note_book, Gtk::PACK_EXPAND_WIDGET, 0);

 	w->note_paned = new Gtk::Paned;

	w->note_paned->pack1(*w->text_view, true, false);
	w->note_paned->pack2(*note_container, true, true);
	w->note_paned->set_wide_handle(true);
	w->note_paned->set_position(800);
	w->note_paned->set_orientation(Gtk::ORIENTATION_VERTICAL);

	// ------------------------------------------
	// DISPLAY THE PANEL AND SEARCHENTRY
	// ------------------------------------------

	v_box->pack_start(*w->search_entry, Gtk::PACK_SHRINK, 0);
	v_box->pack_start(*w->panels, Gtk::PACK_SHRINK, 0);
	v_box->pack_start(*w->note_paned, Gtk::PACK_EXPAND_WIDGET, 0);

	// ------------------------------------------
	// CONNECT THE FUNCTIONS TO THE COMBOBOXES
	// AND TO THE CLOSEBUTTONS
	// ------------------------------------------

	for (int i = 0; i < w->combo_boxes.size(); i++) {
		w->combo_boxes[i]->signal_changed().connect(
			sigc::bind<Gtk::ComboBoxText *>(
			sigc::mem_fun(s, &SignalHandler::source_changed),
			w->combo_boxes[i]),
			false
		);

		w->close_buttons[i]->signal_clicked().connect(
			sigc::bind<Gtk::Button *>(
			sigc::mem_fun(s, &SignalHandler::remove_source_by_reference),
			w->close_buttons[i]),
			false
		);
	}

	// ------------------------------------------
	// CONNECT FUNCTION TO THE ADD BUTTON
	// ------------------------------------------

	w->add_button->signal_clicked().connect(sigc::mem_fun(s, &SignalHandler::add_source), false);

	return true;
}

// LIBRE::MAINWINDOW::CREATE ---------------------------------------------------
// THIS FUNCTION CREATES THE PREFERENCES WINDOW
// -----------------------------------------------------------------------------

bool Libre::PreferencesWindow::create(Libre::Widgets * w, SignalHandler * s) {

	// ------------------------------------------
	// CREATE A NEW WINDOW AND SET ITS PROPERTIES
	// ------------------------------------------

	w->preferences_window = new Gtk::Window;
	w->preferences_window->set_default_size(500, 400);
	w->preferences_window->set_title("Preferences");
	w->preferences_window->set_position(Gtk::WIN_POS_CENTER);
	w->preferences_window->set_icon_from_file(DATA("Icon.svg"));

	// ------------------------------------------
	// CREATE A NEW NOTEBOOK AND SET THE TAB
	// POSITION TO THE LEFT SIDE AND SCROLLABLE
	// ------------------------------------------

	Gtk::Notebook * note_book = new Gtk::Notebook;
	note_book->set_scrollable(true);
	note_book->set_tab_pos(Gtk::POS_LEFT);

	// ------------------------------------------
	// CREATE THE FIRST TAB FOR THE UI SETTINGS
	// ------------------------------------------

	Gtk::VBox * user_interface_box = new Gtk::VBox;
	user_interface_box->set_spacing(10);

	// ------------------------------------------
	// CREATE A CONTAINER, A LABEL, AND A
	// COMBOBOX FOR SETTING THE THEME
	// ------------------------------------------

	Gtk::HBox * theme_box = new Gtk::HBox;
	Gtk::Label * theme_label = new Gtk::Label("Theme", Gtk::ALIGN_START);
	w->preferences_theme_combo = new Gtk::ComboBoxText;

	// ------------------------------------------
	// GET THE SETTINGS AND SET THE CHOSEN THEME
	// TO THE COMBOBOX AS TEXT
	// ------------------------------------------

	Settings settings;

	for (int i = 0; i < settings.get("theme-themes").size(); i++) {
		w->preferences_theme_combo->append(settings.get("theme-themes")[i].as<std::string>());

		if (settings.get("theme-themes")[i].as<std::string>() == settings.get("theme-active").as<std::string>()) {
			w->preferences_theme_combo->set_active(i);
		}
	}

	// ------------------------------------------
	// DISPLAY THE LABEL AND COMBOBOX
	// ------------------------------------------

	theme_box->pack_start(*theme_label);
	theme_box->pack_end(*w->preferences_theme_combo);

	user_interface_box->pack_start(*theme_box, Gtk::PACK_SHRINK, 0);

	// ------------------------------------------
	// CREATE A CONTAINER, LABEL AND SPINBUTTON
	// FOR SETTING THE APPLICATION FONT SIZE
	// ------------------------------------------

	Gtk::HBox * font_size_box = new Gtk::HBox;
	Gtk::Label * font_size_label = new Gtk::Label("Font size", Gtk::ALIGN_START);
	Glib::RefPtr<Gtk::Adjustment> spinbutton_adjustment = Gtk::Adjustment::create(
		settings.get<int>("font_size"), 1, 100
	);

	w->font_size_spinbutton = new Gtk::SpinButton(spinbutton_adjustment, 1, 0);

	// ------------------------------------------
	// DISPLAY THE LABEL AND THE SPINBUTTON
	// ------------------------------------------

	font_size_box->pack_start(*font_size_label);
	font_size_box->pack_end(*w->font_size_spinbutton);

	user_interface_box->pack_start(*font_size_box, Gtk::PACK_SHRINK, 0);

	note_book->append_page(*user_interface_box, "User Interface");

	// ------------------------------------------
	// CREATE THE KEYBINDINGS SETTINGS TAB
	// ------------------------------------------

	Gtk::Label * l2 = new Gtk::Label("Keybindings");

	note_book->append_page(*l2, "Keybindings");

	// ------------------------------------------
	// CREATE THE BOOKS MANAGER TAB
	// ------------------------------------------

	Gtk::VBox * books_box = new Gtk::VBox;

	Gtk::Label * books_page_title = new Gtk::Label("Book Manager");

	Gtk::ScrolledWindow * manager_container = new Gtk::ScrolledWindow;
	manager_container->set_border_width(20);

	books_box->pack_start(*books_page_title, Gtk::PACK_SHRINK, 0);

	w->book_manager_box = new Gtk::VBox;
	w->book_manager_box->set_spacing(5);

	Gtk::Label * book_title = new Gtk::Label("Source");
	Gtk::HBox * book_container = new Gtk::HBox;
	book_container->set_border_width(20);
	Gtk::CheckButton * enable_checkbutton;

	book_container->pack_start(*book_title, Gtk::PACK_SHRINK, 0);
	book_title = new Gtk::Label("Enabled");
	book_container->pack_end(*book_title, Gtk::PACK_SHRINK, 0);
	books_box->pack_start(*book_container, Gtk::PACK_SHRINK, 0);

	Gtk::Separator * sep = new Gtk::Separator;

	books_box->pack_start(*sep, Gtk::PACK_SHRINK, 0);

	books_box->pack_start(*manager_container, Gtk::PACK_EXPAND_WIDGET, 0);

	for (YAML::const_iterator i = w->package_manager.get_sources().begin(); i != w->package_manager.get_sources().end(); i++) {
		book_container = new Gtk::HBox;
		book_title = new Gtk::Label(i->first.as<std::string>(), Gtk::ALIGN_START);
		w->preferences_sources_check[i->first.as<std::string>()] = new Gtk::CheckButton;

		book_container->pack_start(*book_title, Gtk::PACK_SHRINK, 0);
		book_container->pack_end(*w->preferences_sources_check[i->first.as<std::string>()], Gtk::PACK_SHRINK, 0);
		w->book_manager_box->pack_start(*book_container, Gtk::PACK_SHRINK, 0);

		w->preferences_sources_check[i->first.as<std::string>()]->signal_clicked().connect([s, w, i]() {
			(w->preferences_sources_check[i->first.as<std::string>()]->get_active() ?
				w->package_manager.enable(i->first.as<std::string>()) : w->package_manager.disable(i->first.as<std::string>()));
				s->sync_enabled_sources();
		});
	}

	manager_container->add(*w->book_manager_box);

	Gtk::HBox * manage_panel = new Gtk::HBox;
	manage_panel->set_border_width(20);
	Gtk::Button * add = new Gtk::Button;
	add->set_image_from_icon_name("list-add", Gtk::ICON_SIZE_BUTTON);
	add->set_name("view_button");
	Gtk::Button * remove = new Gtk::Button;
	remove->set_image_from_icon_name("list-remove", Gtk::ICON_SIZE_BUTTON);
	remove->set_name("view_button");

	manage_panel->pack_end(*add, Gtk::PACK_SHRINK, 0);
	manage_panel->pack_end(*remove, Gtk::PACK_SHRINK, 0);

	books_box->pack_end(*manage_panel, Gtk::PACK_SHRINK, 0);

	sep = new Gtk::Separator;
	books_box->pack_end(*sep, Gtk::PACK_SHRINK, 0);

	note_book->append_page(*books_box, "Book Manager");

	// ------------------------------------------
	// CONNECT BUTTONS TO FUNCTIONS
	// ------------------------------------------

	add->signal_clicked().connect(
		sigc::mem_fun(s, &SignalHandler::add_source_dir),
		false
	);

	remove->signal_clicked().connect(
		sigc::mem_fun(s, &SignalHandler::remove_source_dir),
		false
	);



	// ------------------------------------------
	// ADD NOTEBOOK TO THE PREFERENCES WINDOW
	// ------------------------------------------

	w->preferences_window->add(*note_book);

	return true;
}
