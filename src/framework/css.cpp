#include "../framework.hpp"

void Framework::load_css_file() {
	LOG("-- Load Css");
	this->widgets.style.css = Gtk::CssProvider::create();
	
	std::string css_file_path = this->widgets.settings.get_attribute("themes", "active") + ".css";
	bool css_load_error = !this->widgets.style.css->load_from_path(DATA(css_file_path));
	if(css_load_error) {
			std::cerr << "Failed to load css\n";
			return;
	}
}

void Framework::set_font_size_from_settings() {
	this->widgets.style.font_size = std::stoi(this->widgets.settings.get_attribute("font", "size"));
	this->widgets.style.font_size_css = Gtk::CssProvider::create();
	this->widgets.style.font_size_css->load_from_data(
		"* { font-size: " + std::to_string(this->widgets.style.font_size) + "px; }"
	);
}

void Framework::apply_css_context_to_screen() {
	Glib::RefPtr<Gdk::Screen> screen = Gdk::Screen::get_default();
	this->widgets.style.style = this->widgets.splash_screen.window->get_style_context();

	this->widgets.style.style->add_provider_for_screen(
			screen, this->widgets.style.css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
	);

	this->widgets.style.style->add_provider_for_screen(
			screen, this->widgets.style.font_size_css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
	);
}

