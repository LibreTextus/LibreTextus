#include "../../preferences.hpp"

void Libre::PreferencesWindow::theme_changed() {
	std::string theme_name = this->ui_pane.get_theme()->get_element()->get_active_text();
	this->settings.set("themes", "active", theme_name);

	bool css_load_error = !this->theme_css_provider->load_from_path(DATA(theme_name + ".css"));
	if (css_load_error) {
		std::cerr << "Failed to load css file\n";
	}
}

void Libre::PreferencesWindow::locales_changed() {
	if (this->ui_pane.get_locale()->get_element()->get_active_text() == _("System default")) {
		this->settings.set("locale", "locale", "");
	} else {
		this->settings.set("locale", "locale", this->ui_pane.get_locale()->get_element()->get_active_text());
	}

	Libre::DialogWindow * dialog = new Libre::DialogWindow(_("Restart"), _("This change only takes affect after a restart"));

	dialog->show_all();

	dialog->get_ok_button()->signal_clicked().connect([dialog, this]() {
			dialog->hide();
			delete dialog;
			this->_restart_application.emit();
	});

	dialog->get_cancel_button()->signal_clicked().connect([dialog]() {
			dialog->hide();
			delete dialog;
	});
}

void Libre::PreferencesWindow::font_size_changed() {
	this->settings.set("font", "size", std::to_string(this->ui_pane.get_font_size()->get_element()->get_value()));

	this->font_size_css_provider->load_from_data(
			"#text_view { font-size: " + 
			std::to_string(this->ui_pane.get_font_size()->get_element()->get_value()) + "px;}"
	);
}
