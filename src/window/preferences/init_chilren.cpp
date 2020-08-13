#include "../preferences.hpp"

void Libre::PreferencesWindow::add_themes_to_themes_combo() {

	std::vector<std::string> v = this->settings.get_children("themes", "name");

	for (std::vector<std::string>::iterator i = v.begin(); i != v.end(); i++) {
		this->ui_pane.get_theme()->get_element()->append(*i);
		
		if (*i == this->settings.get_attribute("themes", "active")) {
			this->ui_pane.get_theme()->get_element()->set_active_text(*i);
		}
	}
}

void Libre::PreferencesWindow::add_locales_to_locales_combo() {
	this->ui_pane.get_locale()->get_element()->append(_("System default"));

	for (auto & i : std::experimental::filesystem::directory_iterator(DATA("../locale"))) {
		this->ui_pane.get_locale()->get_element()->append(i.path().filename().string());
	}

	this->ui_pane.get_locale()->get_element()->set_active_text(
			(this->settings.get_attribute("locale", "locale").empty() ? 
			 _("System default") : this->settings.get_attribute("locale", "locale"))
	);
}

void Libre::PreferencesWindow::set_font_size_adjustment() {
	this->ui_pane.get_font_size()->get_element()->set_adjustment(
			Gtk::Adjustment::create(std::stoi(this->settings.get_attribute("font", "size")), 0, 100)
	);
}

void Libre::PreferencesWindow::create_css_context() {
	Glib::RefPtr<Gdk::Screen> screen = Gdk::Screen::get_default();
	this->theme_css_provider = Gtk::CssProvider::create();
	this->font_size_css_provider = Gtk::CssProvider::create();

	this->get_style_context()->add_provider_for_screen(screen, this->theme_css_provider,
			GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

	this->get_style_context()->add_provider_for_screen(screen, this->font_size_css_provider,
			GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

	this->theme_css_provider->load_from_path(DATA(this->settings.get_attribute("themes", "active") + ".css"));

	this->font_size_css_provider->load_from_data(
			"#text_view { font-size: " + 
			this->settings.get_attribute("font", "size") + "px;}"
	);
}

void Libre::PreferencesWindow::set_package_manager(Libre::PackageManager * pm) {
	this->package_manager = pm;
	
	std::vector<std::string> v = this->package_manager->get_sources();

	for (std::vector<std::string>::const_iterator i = v.begin(); i != v.end(); i++) {
		this->book_manager_pane.get_book_list()->append(*i);
		this->book_manager_pane.get_book_list()->get_items()->back()->set_active(
			this->package_manager->is_enabled(*i)		
		);

		this->book_manager_pane.get_default_source()->get_element()->append(*i);

		this->book_manager_pane.get_book_list()->get_items()->back()->signal_clicked().connect(
				sigc::bind<Gtk::CheckButton *>(
					sigc::mem_fun(this, &Libre::PreferencesWindow::enable_changed), 
					this->book_manager_pane.get_book_list()->get_items()->back()
				)
		);
	}

	this->book_manager_pane.get_default_source()->get_element()->set_active_text(this->settings.get_attribute("startupfile", "file"));
}
