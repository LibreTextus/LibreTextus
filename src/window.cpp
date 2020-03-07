#include "window.hpp"

bool Window::Main::create(LibreWidgets * w, SignalHandler * s) {
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
	w->action_group->add(Gtk::Action::create("ViewAddSource", "Add Source"));
	w->action_group->add(Gtk::Action::create("ViewRemoveSource", "Remove Source"));
	w->action_group->add(Gtk::Action::create("ViewToggleNotes", "Toggle Notes"),
			Gtk::AccelKey("<control><alt>N"));
	w->action_group->add(Gtk::Action::create("ViewToggleComments", "Toggle Comments"),
			Gtk::AccelKey("<control><alt>C"));
	w->action_group->add(Gtk::Action::create("ViewZoomIn", Gtk::Stock::ZOOM_IN),
			Gtk::AccelKey('+', Gdk::ModifierType::CONTROL_MASK));
	w->action_group->add(Gtk::Action::create("ViewZoomOut", Gtk::Stock::ZOOM_OUT),
			Gtk::AccelKey('-', Gdk::ModifierType::CONTROL_MASK));
	w->action_group->add(Gtk::Action::create("ViewZoomReset", Gtk::Stock::ZOOM_100),
			Gtk::AccelKey('=', Gdk::ModifierType::CONTROL_MASK));
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

	Gtk::VBox * scrl_container = new Gtk::VBox(false, 0);
	w->text_views = new Gtk::TextView;
	Gtk::ScrolledWindow * scrolled_window = new Gtk::ScrolledWindow;
	Gtk::HBox * header = new Gtk::HBox(false, 0);

	w->search_result = Gtk::TextBuffer::create();
	w->text_views->set_buffer(w->search_result);
	w->text_views->set_editable(false);
	w->text_views->set_cursor_visible(false);
	w->text_views->set_wrap_mode(Gtk::WRAP_WORD);

	v_box->pack_start(*w->search_entry, Gtk::PACK_SHRINK, 0);	// ADD SEARCH_ENTRY WITH SHRINKABLE FLAG
	v_box->pack_end(*scrl_container, Gtk::PACK_EXPAND_WIDGET, 0);

	scrl_container->pack_start(*header, Gtk::PACK_SHRINK, 0);
	scrl_container->pack_end(*scrolled_window, Gtk::PACK_EXPAND_WIDGET, 0);

	scrolled_window->add(*w->text_views);
	w->text_views->set_border_width(10);

	w->combo_boxes = new Gtk::ComboBoxText;

	w->append_sources(w->combo_boxes);

	header->pack_end(*w->combo_boxes, Gtk::PACK_SHRINK, 0);
	header->set_border_width(10);

	return true;
}

bool Window::Preferences::create(LibreWidgets * w, SignalHandler * s) {
	w->preferences_window = new Gtk::Window;
	w->preferences_window->set_default_size(500, 400);
	w->preferences_window->set_title("Preferences");

	Gtk::Notebook * note_book = new Gtk::Notebook;
	note_book->set_scrollable(true);
	note_book->set_tab_pos(Gtk::POS_LEFT);

	Gtk::VBox * user_interface_box = new Gtk::VBox;
	Gtk::HBox * theme_box = new Gtk::HBox;
	Gtk::Label * theme_label = new Gtk::Label("Theme", Gtk::ALIGN_START);
	w->preferences_theme_combo = new Gtk::ComboBoxText;

	Settings settings;

	for (int i = 0; i < settings.get<YAML::Node>("theme-themes").size(); i++) {
		w->preferences_theme_combo->append(settings.get<YAML::Node>("theme-themes")[i].as<std::string>());

		if (settings.get<YAML::Node>("theme-themes")[i].as<std::string>() == settings.get<YAML::Node>("theme-active").as<std::string>()) {
			w->preferences_theme_combo->set_active(i);
		}
	}

	theme_box->pack_end(*w->preferences_theme_combo);
	theme_box->pack_start(*theme_label);

	user_interface_box->pack_start(*theme_box, Gtk::PACK_SHRINK, 0);

	Gtk::Label * l2 = new Gtk::Label("Keybindings");
	Gtk::Label * l3 = new Gtk::Label("Page 3");

	note_book->append_page(*user_interface_box, "User Interface");
	note_book->append_page(*l2, "Keybindings");
	note_book->append_page(*l3, "Books");

	w->preferences_window->add(*note_book);

	return true;
}
