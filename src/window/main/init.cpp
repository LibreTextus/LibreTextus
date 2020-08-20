#include "main.hpp"

Libre::MainWindow::MainWindow(const std::string & info) : Gtk::Window(), view_pane(info), is_fullscreen(false) {
	this->create_menu_items();
	this->container.pack_start(this->menu, Gtk::PACK_SHRINK);
	this->container.pack_start(this->search_section, Gtk::PACK_SHRINK);
	this->container.pack_start(this->header, Gtk::PACK_SHRINK);
	this->container.pack_start(this->view_pane, Gtk::PACK_EXPAND_WIDGET);
	
	this->add(this->container);

	this->set_default_size(1000, 800);
	this->set_title("LibreTextus");
	this->set_icon_from_file(DATA("icon.svg"));
	this->set_position(Gtk::WIN_POS_CENTER);

	this->connect_signals();
}

void Libre::MainWindow::init() {

	SourceHandler source_handler;
	source_handler.set_names_path(HOME(this->settings.get_attribute("namesfile", "file")));

	this->set_startup_file_if_empty();

	this->package_manager->show_message(_("Init Searchengine"), _("Fetch style"));

	std::string mark_color = this->get_mark_color();

	this->mark_argument = "<span font_weight=\"bold\" underline=\"single\" underline_color=\"#" + mark_color + "\">$&</span>";
	this->header_argument = "<span font_weight=\"ultralight\">$&</span>";

	this->package_manager->show_message(_("Init Searchengine"), _("Load File"));

	this->add_new_search_engine();

	this->package_manager->show_message(_("Init user interface"), _("Create tab"));

	this->header.append();
	this->sync_combo_boxes();
	this->view_pane.get_text_view()->append_tab(this->package_manager->get_source_path(this->settings.get_attribute("startupfile", "file")));
	this->header.get_elements()->back()->get_combo()->set_active_text(this->settings.get_attribute("startupfile", "file"));
	this->connect_signals_of_new_buttons();

	this->package_manager->show_message(_("Init Notebook"), _("Load notes"));

	this->view_pane.get_notebook()->set_file(HOME(this->settings.get_attribute("notebook", "file")));
	this->view_pane.get_text_view()->set_note_book(this->view_pane.get_notebook()->get_xml_root());

	this->search_section.get_search_entry()->grab_focus();
}

std::string Libre::MainWindow::get_mark_color() {
	Gdk::RGBA rgba;
	this->preferences_window->get_style_context()->lookup_color("theme_highlight_color", rgba);

	std::string r, g, b;

	std::stringstream stream;
	stream << std::hex << static_cast<int>(rgba.get_red() * 255);
	r = stream.str();
	if (r.length() < 2) { r = "0" + r; }
	stream.str("");

	stream << std::hex << static_cast<int>(rgba.get_green() * 255);
	g += stream.str();
	if (g.length() < 2) { g = "0" + g; }
	stream.str("");

	stream << std::hex << static_cast<int>(rgba.get_blue() * 255);
	b += stream.str();
	if (b.length() < 2) { b = "0" + b; }

	return r + g + b;
}

void Libre::MainWindow::set_startup_file_if_empty() {
	if (this->settings.get_attribute("startupfile", "file").empty()) {
		this->settings.set("startupfile", "file", this->package_manager->get_sources().front());
	}
}
