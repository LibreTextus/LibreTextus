#include "framework.hpp"

int Framework::init(int argc, char *argv[]) {

	// CREATE BUILDER AND APP ----------------------------------------------------

	this->widgets.app = Gtk::Application::create(argc, argv);	// CREATE APP

	this->signal_handler.set_widgets(&this->widgets);	// PASS WIDGETS TO SIGNAL_HANDLER

	// CREATING WIDGETS ----------------------------------------------------------

	this->widgets.window = new Gtk::Window;							// CREATE NEW WINDOW
	this->widgets.window->set_default_size(1000, 800);	// SET WINDOW SIZE
	this->widgets.window->set_title("LibreTextus");			// SET WINDOW TITLE
	this->widgets.window->set_icon_from_file("data/Icon.svg");
	this->widgets.is_fullscreen = false;

	Gtk::VBox * v_box = new Gtk::VBox(false, 0);					// CREATE VBOX
	this->widgets.window->add(*v_box);										// ADD VBOX TO WINDOW

	// ADD MENU ------------------------------------------------------------------

	this->widgets.action_group = Gtk::ActionGroup::create();	// CREATE ACTIONGROUP

	// CREATE FILE MENU
	this->widgets.action_group->add(Gtk::Action::create("FileMenu", Gtk::Stock::FILE));

	// CREATE QUIT SUBMENU
	this->widgets.action_group->add(Gtk::Action::create("FileNewTab", "New Tab"),
			Gtk::AccelKey("<control>T"));
	this->widgets.action_group->add(Gtk::Action::create("FileCloseTab", "Close Tab"),
			Gtk::AccelKey("<control>W"));
	this->widgets.action_group->add(Gtk::Action::create("FileQuit", Gtk::Stock::QUIT),
					sigc::mem_fun(this->signal_handler, &SignalHandler::quit));

	// CREATE EDIT MENU
	this->widgets.action_group->add(Gtk::Action::create("EditMenu", Gtk::Stock::EDIT));
	this->widgets.action_group->add(Gtk::Action::create("EditCut", Gtk::Stock::CUT));
	this->widgets.action_group->add(Gtk::Action::create("EditCopy", Gtk::Stock::COPY));
	this->widgets.action_group->add(Gtk::Action::create("EditPaste", Gtk::Stock::PASTE));
	this->widgets.action_group->add(Gtk::Action::create("EditFind", Gtk::Stock::FIND));
	this->widgets.action_group->add(Gtk::Action::create("EditPreferences", Gtk::Stock::PREFERENCES),
			Gtk::AccelKey(',', Gdk::ModifierType::CONTROL_MASK));

	// CREATE VIEW MENU

	this->widgets.action_group->add(Gtk::Action::create("ViewMenu", "View"));
	this->widgets.action_group->add(Gtk::Action::create("ViewAddSource", "Add Source"));
	this->widgets.action_group->add(Gtk::Action::create("ViewRemoveSource", "Remove Source"));
	this->widgets.action_group->add(Gtk::Action::create("ViewToggleNotes", "Toggle Notes"),
			Gtk::AccelKey("<control><alt>N"));
	this->widgets.action_group->add(Gtk::Action::create("ViewToggleComments", "Toggle Comments"),
			Gtk::AccelKey("<control><alt>C"));
	this->widgets.action_group->add(Gtk::Action::create("ViewZoomIn", Gtk::Stock::ZOOM_IN),
			Gtk::AccelKey('+', Gdk::ModifierType::CONTROL_MASK));
	this->widgets.action_group->add(Gtk::Action::create("ViewZoomOut", Gtk::Stock::ZOOM_OUT),
			Gtk::AccelKey('-', Gdk::ModifierType::CONTROL_MASK));
	this->widgets.action_group->add(Gtk::Action::create("ViewZoomReset", Gtk::Stock::ZOOM_100),
			Gtk::AccelKey('=', Gdk::ModifierType::CONTROL_MASK));
	this->widgets.action_group->add(Gtk::Action::create("ViewMinimize", "Minimize"),
			Gtk::AccelKey("<control>M"));
	this->widgets.action_group->add(Gtk::Action::create("ViewToggleFullscreen", Gtk::Stock::FULLSCREEN),
			Gtk::AccelKey("F11"), sigc::mem_fun(this->signal_handler, &SignalHandler::toggle_fullscreen));

	// CREATE HISTORY MENU

	this->widgets.action_group->add(Gtk::Action::create("HistoryMenu", "History"));
	this->widgets.action_group->add(Gtk::Action::create("HistoryBack", Gtk::Stock::GO_BACK),
			Gtk::AccelKey("<control>Z"));
	this->widgets.action_group->add(Gtk::Action::create("HistoryForward", Gtk::Stock::GO_FORWARD),
			Gtk::AccelKey("<control><shift>Z"));

	// CREATE HELP MENU

	this->widgets.action_group->add(Gtk::Action::create("HelpMenu", Gtk::Stock::HELP));
	this->widgets.action_group->add(Gtk::Action::create("HelpGetHelp", Gtk::Stock::HELP));
	this->widgets.action_group->add(Gtk::Action::create("HelpAbout", Gtk::Stock::ABOUT));

	this->widgets.ui_manager = Gtk::UIManager::create();
	this->widgets.ui_manager->insert_action_group(this->widgets.action_group);

	this->widgets.window->add_accel_group(this->widgets.ui_manager->get_accel_group());

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
		this->widgets.ui_manager->add_ui_from_string(ui_info);
	}
	catch(const Glib::Error& ex) {
		std::cerr << "building menus failed: " <<  ex.what();
	}

	//Get the menubar and toolbar widgets, and add them to a container widget:
	Gtk::Widget * pMenubar = this->widgets.ui_manager->get_widget("/MenuBar");
	if(pMenubar)
		v_box->pack_start(*pMenubar, Gtk::PACK_SHRINK);



	// ADD SEARCHENTRY AND TEXTVIEW

	this->widgets.search_entry = new Gtk::SearchEntry;	// CREATE NEW SEARCHENTRY

	Gtk::VBox * scrl_container = new Gtk::VBox(false, 0);
	this->widgets.text_views = new Gtk::TextView;
	Gtk::ScrolledWindow * scrolled_window = new Gtk::ScrolledWindow;
	Gtk::HBox * header = new Gtk::HBox(false, 0);

	this->widgets.search_result = Gtk::TextBuffer::create();
	this->widgets.text_views->set_buffer(this->widgets.search_result);
	this->widgets.text_views->set_editable(false);
	this->widgets.text_views->set_cursor_visible(false);
	this->widgets.text_views->set_wrap_mode(Gtk::WRAP_WORD);

	v_box->pack_start(*this->widgets.search_entry, Gtk::PACK_SHRINK, 0);	// ADD SEARCH_ENTRY WITH SHRINKABLE FLAG
	v_box->pack_end(*scrl_container, Gtk::PACK_EXPAND_WIDGET, 0);

	scrl_container->pack_start(*header, Gtk::PACK_SHRINK, 0);
	scrl_container->pack_end(*scrolled_window, Gtk::PACK_EXPAND_WIDGET, 0);

	scrolled_window->add(*this->widgets.text_views);
	this->widgets.text_views->set_border_width(10);

	this->widgets.combo_boxes = new Gtk::ComboBoxText;

	this->widgets.append_sources(this->widgets.combo_boxes);

	header->pack_end(*this->widgets.combo_boxes, Gtk::PACK_SHRINK, 0);
	header->set_border_width(10);

	this->widgets.window->show_all();

	// ADD CSS -------------------------------------------------------------------

	Glib::RefPtr<Gtk::CssProvider> css = Gtk::CssProvider::create();
	if(!css->load_from_path("data/dark.css")) {
			std::cerr << "Failed to load css\n";
			return 1;
	}
	auto screen = Gdk::Screen::get_default();
	this->widgets.style = this->widgets.window->get_style_context();
	this->widgets.style->add_provider_for_screen(screen, css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

	this->signal_handler.init();


	// CONNECT SIGNALS -----------------------------------------------------------

	this->widgets.search_entry->signal_key_press_event().connect(	// SEARCH_ENTRY : WHEN KEY PRESSED
		sigc::mem_fun(this->signal_handler, &SignalHandler::search_request),
		false
	);

	this->widgets.combo_boxes->signal_changed().connect(	// SEARCH_ENTRY : WHEN KEY PRESSED
		sigc::mem_fun(this->signal_handler, &SignalHandler::source_changed),
		false
	);

	this->widgets.set_text_dispatcher.connect(sigc::mem_fun(this->signal_handler, &SignalHandler::set_text));
	this->widgets.delete_thread_dispatcher.connect(sigc::mem_fun(this->signal_handler, &SignalHandler::delete_thread));

	return 0;
}

void Framework::run() {
	if (this->widgets.window) {
		this->widgets.app->run(*this->widgets.window);
	} else {
		std::cerr << "ERROR: UNABLE TO RUN APPLICATION" << '\n';
	}
}
