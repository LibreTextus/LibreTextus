#include "../signal_handler.hpp"

void SignalHandler::init(Libre::Widgets * w) {

	LOG("-- Init SignalHandler");

	this->widgets = w;

	SourceHandler source_handler;
	source_handler.set_names_path(HOME(this->widgets->settings.get_attribute("namesfile", "file")));

	this->widgets->package_manager.show_message(_("Init Searchengine"), _("Load File"));

	this->set_startup_file_if_empty();
	
	this->widgets->search_engine.push_back(
		SearchEngine(this->widgets->package_manager.get_source_path(this->settings.get_attribute("startupfile", "file")))
	);

	this->widgets->package_manager.show_message(_("Init Searchengine"), _("Fetch mark color"));

	std::string mark_color = this->get_mark_color();

	this->mark_argument = "<span font_weight=\"bold\" underline=\"single\" underline_color=\"#" + mark_color + "\">$&</span>";
	this->header_argument = "<span font_weight=\"ultralight\">$&</span>";

	this->widgets->search_engine[0].set_mark_argument(this->mark_argument);
}

std::string SignalHandler::get_mark_color() {
	Gdk::RGBA rgba;
	this->widgets->preferences_window->get_style_context()->lookup_color("theme_highlight_color", rgba);

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

void SignalHandler::set_startup_file_if_empty() {
	if (this->settings.get_attribute("startupfile", "file").empty()) {
		this->settings.set("startupfile", "file", this->widgets->package_manager.get_sources().front());
	}
}
