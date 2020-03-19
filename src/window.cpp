#include "window.hpp"

bool LibreWindow::Main::create(LibreWidgets * w, SignalHandler * s) {
	w->window = new Gtk::Window;							// CREATE NEW WINDOW
	w->window->set_default_size(1000, 800);	// SET WINDOW SIZE
	w->window->set_title("LibreTextus");			// SET WINDOW TITLE
	w->window->set_icon_from_file("data/Icon.svg");
	w->is_fullscreen = false;

	Gtk::VBox * v_box = new Gtk::VBox(false, 0);					// CREATE VBOX
	w->window->add(*v_box);										// ADD VBOX TO WINDOW

	// ADD MENU ------------------------------------------------------------------

	w->action_group = Gtk::ActionGroup::create();	// CREATE ACTIONGROUP

	// CREATE FILE MENU
	w->action_group->add(Gtk::Action::create("FileMenu", Gtk::Stock::FILE));

	// CREATE QUIT SUBMENU
	w->action_group->add(Gtk::Action::create("FileNewTab", "New Tab"),
			Gtk::AccelKey("<control>T"));
	w->action_group->add(Gtk::Action::create("FileCloseTab", "Close Tab"),
			Gtk::AccelKey("<control>W"));
	w->action_group->add(Gtk::Action::create("FileQuit", Gtk::Stock::QUIT),
					sigc::mem_fun(s, &SignalHandler::quit));

	// CREATE EDIT MENU
	w->action_group->add(Gtk::Action::create("EditMenu", Gtk::Stock::EDIT));
	w->action_group->add(Gtk::Action::create("EditCut", Gtk::Stock::CUT));
	w->action_group->add(Gtk::Action::create("EditCopy", Gtk::Stock::COPY));
	w->action_group->add(Gtk::Action::create("EditPaste", Gtk::Stock::PASTE));
	w->action_group->add(Gtk::Action::create("EditFind", Gtk::Stock::FIND),
			Gtk::AccelKey("<control>F"), sigc::mem_fun(s, &SignalHandler::toggle_search));
	w->action_group->add(Gtk::Action::create("EditPreferences", Gtk::Stock::PREFERENCES),
			Gtk::AccelKey(',', Gdk::ModifierType::CONTROL_MASK), sigc::mem_fun(s, &SignalHandler::toggle_preferences));

	// CREATE VIEW MENU

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

	// CREATE HISTORY MENU

	w->action_group->add(Gtk::Action::create("HistoryMenu", "History"));
	w->action_group->add(Gtk::Action::create("HistoryBack", Gtk::Stock::GO_BACK),
			Gtk::AccelKey("<control>Z"));
	w->action_group->add(Gtk::Action::create("HistoryForward", Gtk::Stock::GO_FORWARD),
			Gtk::AccelKey("<control><shift>Z"));

	// CREATE HELP MENU

	w->action_group->add(Gtk::Action::create("HelpMenu", Gtk::Stock::HELP));
	w->action_group->add(Gtk::Action::create("HelpGetHelp", Gtk::Stock::HELP));
	w->action_group->add(Gtk::Action::create("HelpAbout", Gtk::Stock::ABOUT));

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

	//Get the menubar and toolbar widgets, and add them to a container widget:
	Gtk::Widget * pMenubar = w->ui_manager->get_widget("/MenuBar");
	if(pMenubar)
		v_box->pack_start(*pMenubar, Gtk::PACK_SHRINK);

	// ADD SEARCHENTRY AND TEXTVIEW

	w->search_entry = new Gtk::SearchEntry;	// CREATE NEW SEARCHENTRY

	w->search_entry->set_placeholder_text("Search");

	w->add_button = nullptr;

	w->panels = new Gtk::HBox(false, 0);
	w->panels->set_spacing(5);
	w->panels->set_border_width(5);
	w->add_panel();

	v_box->pack_start(*w->search_entry, Gtk::PACK_SHRINK, 0);
	v_box->pack_end(*w->panels, Gtk::PACK_EXPAND_WIDGET, 0);

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

	w->add_button->signal_clicked().connect(sigc::mem_fun(s, &SignalHandler::add_source), false);

	return true;
}

bool LibreWindow::Preferences::create(LibreWidgets * w, SignalHandler * s) {

	w->preferences_window = new Gtk::Window;
	w->preferences_window->set_default_size(500, 400);
	w->preferences_window->set_title("Preferences");

	Gtk::Notebook * note_book = new Gtk::Notebook;
	note_book->set_scrollable(true);
	note_book->set_tab_pos(Gtk::POS_LEFT);

	// PAGE ONE: USER INTERFACE

	Gtk::VBox * user_interface_box = new Gtk::VBox;
	user_interface_box->set_spacing(10);

	// -- THEME SETTINGS

	Gtk::HBox * theme_box = new Gtk::HBox;
	Gtk::Label * theme_label = new Gtk::Label("Theme", Gtk::ALIGN_START);
	w->preferences_theme_combo = new Gtk::ComboBoxText;

	Settings settings;

	for (int i = 0; i < settings.get("theme-themes").size(); i++) {
		w->preferences_theme_combo->append(settings.get("theme-themes")[i].as<std::string>());

		if (settings.get("theme-themes")[i].as<std::string>() == settings.get("theme-active").as<std::string>()) {
			w->preferences_theme_combo->set_active(i);
		}
	}

	theme_box->pack_start(*theme_label);
	theme_box->pack_end(*w->preferences_theme_combo);

	user_interface_box->pack_start(*theme_box, Gtk::PACK_SHRINK, 0);

	// -- FONT SIZE SETTINGS

	Gtk::HBox * font_size_box = new Gtk::HBox;
	Gtk::Label * font_size_label = new Gtk::Label("Font size", Gtk::ALIGN_START);
	Glib::RefPtr<Gtk::Adjustment> spinbutton_adjustment = Gtk::Adjustment::create(
		settings.get<int>("font_size"), 1, 100
	);

	w->font_size_spinbutton = new Gtk::SpinButton(spinbutton_adjustment, 1, 0);

	font_size_box->pack_start(*font_size_label);
	font_size_box->pack_end(*w->font_size_spinbutton);

	user_interface_box->pack_start(*font_size_box, Gtk::PACK_SHRINK, 0);

	Gtk::Label * l2 = new Gtk::Label("Keybindings");
	Gtk::Label * l3 = new Gtk::Label("Books");

	note_book->append_page(*user_interface_box, "User Interface");
	note_book->append_page(*l2, "Keybindings");
	note_book->append_page(*l3, "Books");

	w->preferences_window->add(*note_book);

	return true;
}
