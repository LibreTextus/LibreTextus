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
	w->main.window->set_icon_from_file(DATA("icon.svg"));
	w->main.window->set_position(Gtk::WIN_POS_CENTER);
	w->main.is_fullscreen = false;

	// ------------------------------------------
	// ADD THE ROOT VBOX TO THE WINDOW
	// ------------------------------------------

	Gtk::VBox * v_box = new Gtk::VBox(false, 0);
	w->main.window->add(*v_box);

	w->main.history_button = new Libre::HistoryButton;

	// ------------------------------------------
	// CREATE THE MENUBAR FOR THE WINDOW
	// ------------------------------------------

	LOG(" * Create ActionGroup for Menu");

	w->ui.action_group = Gtk::ActionGroup::create();

	// ------------------------------------------
	// CREATE FILE MENU
	// ------------------------------------------

	w->ui.action_group->add(Gtk::Action::create("FileMenu", _("File")));

	// ------------------------------------------
	// CREATE QUIT MENU
	// ------------------------------------------

	w->ui.action_group->add(Gtk::Action::create("FileNewTab", _("New Tab")),
			Gtk::AccelKey("<control>T"));
	w->ui.action_group->add(Gtk::Action::create("FileCloseTab", _("Close Tab")),
			Gtk::AccelKey("<control>W"));
	w->ui.action_group->add(Gtk::Action::create("FileExportNotes", _("Export Notes")),
			Gtk::AccelKey("<control>E"), sigc::mem_fun(s, &SignalHandler::export_notes));
	w->ui.action_group->add(Gtk::Action::create("FileQuit", _("Quit")),
					Gtk::AccelKey("<control>Q"), sigc::mem_fun(s, &SignalHandler::quit));

	// ------------------------------------------
	// CREATE EDIT MENU
	// ------------------------------------------

	w->ui.action_group->add(Gtk::Action::create("EditMenu", _("Edit")));
	w->ui.action_group->add(Gtk::Action::create("EditCut", _("Cut")));
	w->ui.action_group->add(Gtk::Action::create("EditCopy", _("Copy")));
	w->ui.action_group->add(Gtk::Action::create("EditPaste", _("Paste")));
	w->ui.action_group->add(Gtk::Action::create("EditFind", _("Search")),
			Gtk::AccelKey("<control>F"), sigc::mem_fun(s, &SignalHandler::toggle_search));
	w->ui.action_group->add(Gtk::Action::create("EditPreferences", Gtk::Stock::PREFERENCES),
			Gtk::AccelKey(',', Gdk::ModifierType::CONTROL_MASK), sigc::mem_fun(s, &SignalHandler::toggle_preferences));

	// ------------------------------------------
	// CREATE VIEW MENU
	// ------------------------------------------

	w->ui.action_group->add(Gtk::Action::create("ViewMenu", _("View")));
	w->ui.action_group->add(Gtk::Action::create("ViewAddSource", _("Add Source")),
			Gtk::AccelKey("<control>N"), sigc::mem_fun(s, &SignalHandler::add_source));
	w->ui.action_group->add(Gtk::Action::create("ViewRemoveSource", _("Remove Source")),
			Gtk::AccelKey("<control>D"), sigc::mem_fun(s, &SignalHandler::remove_source));
	w->ui.action_group->add(Gtk::Action::create("ViewToggleNotes", _("Toggle Notes")),
			Gtk::AccelKey("<control><alt>N"));
	w->ui.action_group->add(Gtk::Action::create("ViewZoomIn", _("Zoom in")),
			Gtk::AccelKey('+', Gdk::ModifierType::CONTROL_MASK), sigc::mem_fun(s, &SignalHandler::zoom_in));
	w->ui.action_group->add(Gtk::Action::create("ViewZoomOut", _("Zoom out")),
			Gtk::AccelKey('-', Gdk::ModifierType::CONTROL_MASK), sigc::mem_fun(s, &SignalHandler::zoom_out));
	w->ui.action_group->add(Gtk::Action::create("ViewZoomReset", _("Zoom reset")),
			Gtk::AccelKey('=', Gdk::ModifierType::CONTROL_MASK), sigc::mem_fun(s, &SignalHandler::zoom_reset));
	w->ui.action_group->add(Gtk::Action::create("ViewMinimize", _("Minimize")),
			Gtk::AccelKey("<control>M"), sigc::mem_fun(s, &SignalHandler::toggle_iconify));
	w->ui.action_group->add(Gtk::Action::create("ViewToggleFullscreen", _("Fullscreen")),
			Gtk::AccelKey("F11"), sigc::mem_fun(s, &SignalHandler::toggle_fullscreen));

	// ------------------------------------------
	// CREATE HISTORY MENU
	// ------------------------------------------

	w->ui.action_group->add(Gtk::Action::create("HistoryMenu", _("History")));
	w->ui.action_group->add(Gtk::Action::create("HistoryBack", _("Go back")),
			Gtk::AccelKey("<alt>Left"), sigc::bind<bool>(sigc::mem_fun(w->main.history_button, &Libre::HistoryButton::button_pressed), false));
	w->ui.action_group->add(Gtk::Action::create("HistoryForward", _("Go forward")),
			Gtk::AccelKey("<alt>Right"), sigc::bind<bool>(sigc::mem_fun(w->main.history_button, &Libre::HistoryButton::button_pressed), true));

	// ------------------------------------------
	// CREATE HELP MENU
	// ------------------------------------------

	w->ui.action_group->add(Gtk::Action::create("HelpMenu", _("Help")));
	w->ui.action_group->add(Gtk::Action::create("HelpGetHelp", _("Help")));
	w->ui.action_group->add(Gtk::Action::create("HelpAbout", _("About")));

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
				"			<menuitem action='FileExportNotes'/>"
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

	Gtk::Widget * pMenubar = w->ui.manager->get_widget("/ui/MenuBar");
	if(pMenubar) {
		v_box->pack_start(*pMenubar, Gtk::PACK_SHRINK);
	}

	// ------------------------------------------
	// CREATE SEARCHENTRY AND SET ITS PROPERTIES
	// ------------------------------------------

	LOG(" * Create SearchEntry");

	w->main.search_entry = new Gtk::SearchEntry;
	w->main.search_entry->set_placeholder_text(_("Search"));

	w->main.search_entry->signal_key_press_event().connect(
		sigc::mem_fun(s, &SignalHandler::search_request),
		false
	);

	w->main.number_results = new Gtk::Label(std::string("0 ") + _("Results"));
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

	std::string splash_text = _("<big>Welcome to LibreTextus!</big>\n"
														"Here are some search syntax hints:\n"
														"<i>WORD WORD2</i> will give you all verses with <i>WORD</i> and <i>WORD2</i> in it, but not in this order.\n"
														"<i>\"WORD ANOTHER WORD\"</i> this means you want exactly what is quoted\n"
														"To get specific verses or chapters use the standart notation like: <i>GEN 1,1-10</i>\n"
														"<i>WORD@GEN 1</i> will give all <i>WORD</i> in <i>GEN 1</i>\n");

	Settings settings;
	w->main.text_view = new Libre::TextView(splash_text, w->package_manager.get_source_path(settings.get_attribute("startupfile", "file")));
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

	w->main.note_book->set_file(HOME(w->settings.get_attribute("notebook", "file")));
	w->main.text_view->set_note_book(w->main.note_book->get_xml_root());

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
