#include "window.hpp"

// LIBRE::MAINWINDOW::CREATE ---------------------------------------------------
// THIS FUNCTION CREATES THE MAIN WINDOW
// -----------------------------------------------------------------------------

bool Libre::MainWindow::create(Libre::Widgets * w, SignalHandler * s) {

	// ------------------------------------------
	// CREATE A NEW WINDOW AND ITS PROPERTIES
	// ------------------------------------------

	LOG(" * Init new Main Window");

	w->main.window = new Gtk::Window;
	w->main.window->set_default_size(1000, 800);
	w->main.window->set_title("LibreTextus");
	w->main.window->set_icon_from_file(DATA("Icon.svg"));
	w->main.window->set_position(Gtk::WIN_POS_CENTER);
	w->main.is_fullscreen = false;

	// ------------------------------------------
	// ADD THE ROOT VBOX TO THE WINDOW
	// ------------------------------------------

	Gtk::VBox * v_box = new Gtk::VBox(false, 0);
	w->main.window->add(*v_box);

	// ------------------------------------------
	// CREATE THE MENUBAR FOR THE WINDOW
	// ------------------------------------------

	LOG(" * Create ActionGroup for Menu");

	w->ui.action_group = Gtk::ActionGroup::create();

	// ------------------------------------------
	// CREATE FILE MENU
	// ------------------------------------------

	w->ui.action_group->add(Gtk::Action::create("FileMenu", Gtk::Stock::FILE));

	// ------------------------------------------
	// CREATE QUIT MENU
	// ------------------------------------------

	w->ui.action_group->add(Gtk::Action::create("FileNewTab", "New Tab"),
			Gtk::AccelKey("<control>T"));
	w->ui.action_group->add(Gtk::Action::create("FileCloseTab", "Close Tab"),
			Gtk::AccelKey("<control>W"));
	w->ui.action_group->add(Gtk::Action::create("FileQuit", Gtk::Stock::QUIT),
					sigc::mem_fun(s, &SignalHandler::quit));

	// ------------------------------------------
	// CREATE EDIT MENU
	// ------------------------------------------

	w->ui.action_group->add(Gtk::Action::create("EditMenu", Gtk::Stock::EDIT));
	w->ui.action_group->add(Gtk::Action::create("EditCut", Gtk::Stock::CUT));
	w->ui.action_group->add(Gtk::Action::create("EditCopy", Gtk::Stock::COPY));
	w->ui.action_group->add(Gtk::Action::create("EditPaste", Gtk::Stock::PASTE));
	w->ui.action_group->add(Gtk::Action::create("EditFind", Gtk::Stock::FIND),
			Gtk::AccelKey("<control>F"), sigc::mem_fun(s, &SignalHandler::toggle_search));
	w->ui.action_group->add(Gtk::Action::create("EditPreferences", Gtk::Stock::PREFERENCES),
			Gtk::AccelKey(',', Gdk::ModifierType::CONTROL_MASK), sigc::mem_fun(s, &SignalHandler::toggle_preferences));

	// ------------------------------------------
	// CREATE VIEW MENU
	// ------------------------------------------

	w->ui.action_group->add(Gtk::Action::create("ViewMenu", "View"));
	w->ui.action_group->add(Gtk::Action::create("ViewAddSource", "Add Source"),
			Gtk::AccelKey("<control>N"), sigc::mem_fun(s, &SignalHandler::add_source));
	w->ui.action_group->add(Gtk::Action::create("ViewRemoveSource", "Remove Source"),
			Gtk::AccelKey("<control>D"), sigc::mem_fun(s, &SignalHandler::remove_source));
	w->ui.action_group->add(Gtk::Action::create("ViewToggleNotes", "Toggle Notes"),
			Gtk::AccelKey("<control><alt>N"));
	w->ui.action_group->add(Gtk::Action::create("ViewToggleComments", "Toggle Comments"),
			Gtk::AccelKey("<control><alt>C"));
	w->ui.action_group->add(Gtk::Action::create("ViewZoomIn", Gtk::Stock::ZOOM_IN),
			Gtk::AccelKey('+', Gdk::ModifierType::CONTROL_MASK), sigc::mem_fun(s, &SignalHandler::zoom_in));
	w->ui.action_group->add(Gtk::Action::create("ViewZoomOut", Gtk::Stock::ZOOM_OUT),
			Gtk::AccelKey('-', Gdk::ModifierType::CONTROL_MASK), sigc::mem_fun(s, &SignalHandler::zoom_out));
	w->ui.action_group->add(Gtk::Action::create("ViewZoomReset", Gtk::Stock::ZOOM_100),
			Gtk::AccelKey('=', Gdk::ModifierType::CONTROL_MASK), sigc::mem_fun(s, &SignalHandler::zoom_reset));
	w->ui.action_group->add(Gtk::Action::create("ViewMinimize", "Minimize"),
			Gtk::AccelKey("<control>M"), sigc::mem_fun(s, &SignalHandler::toggle_iconify));
	w->ui.action_group->add(Gtk::Action::create("ViewToggleFullscreen", Gtk::Stock::FULLSCREEN),
			Gtk::AccelKey("F11"), sigc::mem_fun(s, &SignalHandler::toggle_fullscreen));

	// ------------------------------------------
	// CREATE HISTORY MENU
	// ------------------------------------------

	w->ui.action_group->add(Gtk::Action::create("HistoryMenu", "History"));
	w->ui.action_group->add(Gtk::Action::create("HistoryBack", Gtk::Stock::GO_BACK),
			Gtk::AccelKey("<control>Z"));
	w->ui.action_group->add(Gtk::Action::create("HistoryForward", Gtk::Stock::GO_FORWARD),
			Gtk::AccelKey("<control><shift>Z"));

	// ------------------------------------------
	// CREATE HELP MENU
	// ------------------------------------------

	w->ui.action_group->add(Gtk::Action::create("HelpMenu", Gtk::Stock::HELP));
	w->ui.action_group->add(Gtk::Action::create("HelpGetHelp", Gtk::Stock::HELP));
	w->ui.action_group->add(Gtk::Action::create("HelpAbout", Gtk::Stock::ABOUT));

	// ------------------------------------------
	// ADD UIMANAGER ACCEL GROUP TO THE WINDOW
	// ------------------------------------------

	w->ui.manager = Gtk::UIManager::create();
	w->ui.manager->insert_action_group(w->ui.action_group);

	w->main.window->add_accel_group(w->ui.manager->get_accel_group());

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
		w->ui.manager->add_ui_from_string(ui_info);
	}
	catch(const Glib::Error& ex) {
		std::cerr << "building menus failed: " <<  ex.what();
	}

	// ------------------------------------------
	// ADD MENUBAR TO THE WINDOW
	// ------------------------------------------

	LOG(" * Create Menu");

	Gtk::Widget * pMenubar = w->ui.manager->get_widget("/MenuBar");
	if(pMenubar) {
		v_box->pack_start(*pMenubar, Gtk::PACK_SHRINK);
	}


	// ------------------------------------------
	// CREATE SEARCHENTRY AND SET ITS PROPERTIES
	// ------------------------------------------

	LOG(" * Create SearchEntry");

	w->main.search_entry = new Gtk::SearchEntry;
	w->main.search_entry->set_placeholder_text("Search");

	w->main.search_entry->signal_key_press_event().connect(
		sigc::mem_fun(s, &SignalHandler::search_request),
		false
	);

	w->main.number_results = new Gtk::Label("0 Results");
	w->main.history_button = new Libre::HistoryButton;
	w->main.history_button->trigger_search().connect(sigc::mem_fun(s, &SignalHandler::trigger_search));

	Gtk::HBox * search_box = new Gtk::HBox;

	search_box->pack_start(*w->main.history_button, Gtk::PACK_SHRINK, 0);
	search_box->pack_start(*w->main.search_entry, Gtk::PACK_EXPAND_WIDGET, 0);
	search_box->pack_start(*w->main.number_results, Gtk::PACK_SHRINK, 10);

	search_box->set_name("search_entry");

	w->main.add_button = nullptr;

	// ------------------------------------------
	// CREATE TEXTVIEW AND NOTEBOOK
	// ------------------------------------------

	LOG(" * Create TextView and NoteBook");

	w->main.panels = new Gtk::HBox(false, 0);
	w->main.panels->set_spacing(5);
	w->main.panels->set_border_width(5);
	w->main.panels->set_homogeneous(true);
	w->add_panel();

	w->main.text_view = new Libre::TextView(w->settings.get<std::string>("splash_text"));
	w->main.text_view->signal_toggle_note().connect(sigc::mem_fun(s, &SignalHandler::toggle_note));
	w->main.text_view->signal_right_click_search().connect(sigc::mem_fun(s, &SignalHandler::trigger_search));

	w->main.note_book = new Libre::NoteBook;
	w->main.note_book->get_close_button()->signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(s, &SignalHandler::toggle_note), ""));

	w->main.note_book->signal_key_press_event().connect([s](GdkEventKey * key) -> bool {
		if (key->keyval == 65307) {
			s->toggle_note("");
		}
		return false;
	});

	w->main.note_book->signal_refresh().connect(sigc::mem_fun(w->main.text_view, &Libre::TextView::_display));
	w->main.is_note_book_open = false;

 	w->main.note_paned = new Gtk::Paned;

	w->main.note_paned->pack1(*w->main.text_view, true, false);
	w->main.note_paned->pack2(*w->main.note_book, true, true);
	w->main.note_paned->set_wide_handle(true);
	w->main.note_paned->set_position(800);
	w->main.note_paned->set_orientation(Gtk::ORIENTATION_VERTICAL);

	// ------------------------------------------
	// DISPLAY THE PANEL AND SEARCHENTRY
	// ------------------------------------------

	v_box->pack_start(*search_box, Gtk::PACK_SHRINK, 0);
	v_box->pack_start(*w->main.panels, Gtk::PACK_SHRINK, 0);
	v_box->pack_start(*w->main.note_paned, Gtk::PACK_EXPAND_WIDGET, 0);

	// ------------------------------------------
	// CONNECT THE FUNCTIONS TO THE COMBOBOXES
	// AND TO THE CLOSEBUTTONS
	// ------------------------------------------

	for (int i = 0; i < w->main.combo_boxes.size(); i++) {
		w->main.combo_boxes[i]->signal_changed().connect(
			sigc::bind<Gtk::ComboBoxText *>(
			sigc::mem_fun(s, &SignalHandler::source_changed),
			w->main.combo_boxes[i]),
			false
		);

		w->main.close_buttons[i]->signal_clicked().connect(
			sigc::bind<Gtk::Button *>(
			sigc::mem_fun(s, &SignalHandler::remove_source_by_reference),
			w->main.close_buttons[i]),
			false
		);
	}

	// ------------------------------------------
	// CONNECT FUNCTION TO THE ADD BUTTON
	// ------------------------------------------

	LOG(" * Connect add_source Signal");

	w->main.add_button->signal_clicked().connect(sigc::mem_fun(s, &SignalHandler::add_source), false);

	return true;
}

// LIBRE::MAINWINDOW::CREATE ---------------------------------------------------
// THIS FUNCTION CREATES THE PREFERENCES WINDOW
// -----------------------------------------------------------------------------

bool Libre::PreferencesWindow::create(Libre::Widgets * w, SignalHandler * s) {

	// ------------------------------------------
	// CREATE A NEW WINDOW AND SET ITS PROPERTIES
	// ------------------------------------------

	LOG(" * Init new Properties Window");

	w->preferences.window = new Gtk::Window;
	w->preferences.window->set_default_size(500, 400);
	w->preferences.window->set_title("Preferences");
	w->preferences.window->set_position(Gtk::WIN_POS_CENTER);
	w->preferences.window->set_icon_from_file(DATA("Icon.svg"));

	// ------------------------------------------
	// CREATE A NEW NOTEBOOK AND SET THE TAB
	// POSITION TO THE LEFT SIDE AND SCROLLABLE
	// ------------------------------------------

	LOG(" * Create Tabs");

	Gtk::Notebook * note_book = new Gtk::Notebook;
	note_book->set_scrollable(true);
	note_book->set_tab_pos(Gtk::POS_LEFT);

	// ------------------------------------------
	// CREATE THE FIRST TAB FOR THE UI SETTINGS
	// ------------------------------------------

	LOG(" * Init Tab \"Theme\"");

	Gtk::VBox * user_interface_box = new Gtk::VBox;
	user_interface_box->set_spacing(10);

	// ------------------------------------------
	// CREATE A CONTAINER, A LABEL, AND A
	// COMBOBOX FOR SETTING THE THEME
	// ------------------------------------------

	Gtk::HBox * theme_box = new Gtk::HBox;
	Gtk::Label * theme_label = new Gtk::Label("Theme", Gtk::ALIGN_START);
	w->preferences.theme_combo = new Gtk::ComboBoxText;

	// ------------------------------------------
	// GET THE SETTINGS AND SET THE CHOSEN THEME
	// TO THE COMBOBOX AS TEXT
	// ------------------------------------------

	LOG(" * Load Settings");

	Settings settings;

	for (int i = 0; i < settings.get("theme-themes").size(); i++) {
		w->preferences.theme_combo->append(settings.get("theme-themes")[i].as<std::string>());

		if (settings.get("theme-themes")[i].as<std::string>() == settings.get("theme-active").as<std::string>()) {
			w->preferences.theme_combo->set_active(i);
		}
	}

	w->preferences.theme_combo->signal_changed().connect(
		sigc::mem_fun(s, &SignalHandler::theme_changed),
		false
	);

	// ------------------------------------------
	// DISPLAY THE LABEL AND COMBOBOX
	// ------------------------------------------

	theme_box->pack_start(*theme_label);
	theme_box->pack_end(*w->preferences.theme_combo);

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

	w->preferences.font_size_spinbutton = new Gtk::SpinButton(spinbutton_adjustment, 1, 0);

	w->preferences.font_size_spinbutton->signal_value_changed().connect(
		sigc::mem_fun(s, &SignalHandler::default_font_size_changed),
		false
	);

	// ------------------------------------------
	// DISPLAY THE LABEL AND THE SPINBUTTON
	// ------------------------------------------

	font_size_box->pack_start(*font_size_label);
	font_size_box->pack_end(*w->preferences.font_size_spinbutton);

	user_interface_box->pack_start(*font_size_box, Gtk::PACK_SHRINK, 0);

	note_book->append_page(*user_interface_box, "User Interface");

	// ------------------------------------------
	// CREATE THE KEYBINDINGS SETTINGS TAB
	// ------------------------------------------

	LOG(" * Init Tab \"Keybindings\"");

	Gtk::Label * l2 = new Gtk::Label("Keybindings");

	note_book->append_page(*l2, "Keybindings");

	// ------------------------------------------
	// CREATE THE BOOKS MANAGER TAB
	// ------------------------------------------

	LOG(" * Init Tab \"BOOKS\"");

	Gtk::VBox * books_box = new Gtk::VBox;

	Gtk::Label * books_page_title = new Gtk::Label("Book Manager");

	Gtk::ScrolledWindow * manager_container = new Gtk::ScrolledWindow;
	manager_container->set_border_width(20);

	books_box->pack_start(*books_page_title, Gtk::PACK_SHRINK, 0);

	w->preferences.book_manager_box = new Gtk::VBox;
	w->preferences.book_manager_box->set_spacing(5);

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

	LOG(" * Get Sources");

	for (YAML::const_iterator i = w->package_manager.get_sources().begin(); i != w->package_manager.get_sources().end(); i++) {
		book_container = new Gtk::HBox;
		book_title = new Gtk::Label(i->first.as<std::string>(), Gtk::ALIGN_START);
		w->preferences.sources_check[i->first.as<std::string>()] = new Gtk::CheckButton;

		book_container->pack_start(*book_title, Gtk::PACK_SHRINK, 0);
		book_container->pack_end(*w->preferences.sources_check[i->first.as<std::string>()], Gtk::PACK_SHRINK, 0);
		w->preferences.book_manager_box->pack_start(*book_container, Gtk::PACK_SHRINK, 0);

		w->preferences.sources_check[i->first.as<std::string>()]->signal_clicked().connect([s, w, i]() {
			(w->preferences.sources_check[i->first.as<std::string>()]->get_active() ?
				w->package_manager.enable(i->first.as<std::string>()) : w->package_manager.disable(i->first.as<std::string>()));
				s->sync_enabled_sources();
		});
	}

	manager_container->add(*w->preferences.book_manager_box);

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

	LOG(" * Connect Signals");

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

	w->preferences.window->add(*note_book);

	return true;
}
