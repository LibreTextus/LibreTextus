#include "../preferences.hpp"

void Libre::PreferencesWindow::enable_changed(Gtk::CheckButton * i) {
	if (i->get_active())
	 	this->package_manager->enable(i->get_label());
	else
		this->package_manager->disable(i->get_label());

	this->sync_default_source_combo();
}

void Libre::PreferencesWindow::default_source_changed() {
	bool selection_is_not_empty = !this->book_manager_pane.get_default_source()->get_element()->get_active_text().empty();
	if (selection_is_not_empty) {
		this->settings.set(
				"startupfile", "file", 
				this->book_manager_pane.get_default_source()->get_element()->get_active_text());
	}
}

void Libre::PreferencesWindow::sync_default_source_combo() {

	std::vector<std::string>::iterator b = this->package_manager->get_sources().begin();
	std::vector<std::string>::iterator e = this->package_manager->get_sources().end();
	std::string default_source = this->book_manager_pane.get_default_source()->get_element()->get_active_text();
	bool default_no_longer_exists = std::find(b, e, default_source) == e;

	this->book_manager_pane.get_default_source()->get_element()->remove_all();

	for (std::vector<std::string>::iterator i = this->package_manager->get_sources().begin(); i != this->package_manager->get_sources().end(); i++) {
		if (this->package_manager->is_enabled(*i)) {
			this->book_manager_pane.get_default_source()->get_element()->append(*i);
		}
	}

	if (default_no_longer_exists || !this->package_manager->is_enabled(default_source)) {
		this->book_manager_pane.get_default_source()->get_element()->set_active_text(*b);
	} else {
		this->book_manager_pane.get_default_source()->get_element()->set_active_text(
				this->settings.get_attribute("startupfile", "file"));
	}

	this->_sync_all_source_combo_main_window.emit();
}

void Libre::PreferencesWindow::sync_sources() {
	Gtk::VBox * b_container = this->book_manager_pane.get_book_list()->get_container();

	for (int i = 0; i < b_container->get_children().size(); i++) {
		b_container->remove(*b_container->get_children()[0]);
	}

	std::vector<std::string> v = this->package_manager->get_sources();

	for (std::vector<std::string>::const_iterator i = v.begin(); i != v.end(); i++) {
		this->book_manager_pane.get_book_list()->append(*i);
		this->book_manager_pane.get_book_list()->get_items()->back()->set_active(
				this->package_manager->is_enabled(*i)
		);
		
		this->book_manager_pane.get_book_list()->get_items()->back()->signal_clicked().connect(
				sigc::bind<Gtk::CheckButton *>(
					sigc::mem_fun(this, &Libre::PreferencesWindow::enable_changed), 
					this->book_manager_pane.get_book_list()->get_items()->back()
				)
		);

	}

	this->sync_source_combo();
}

void Libre::PreferencesWindow::manage_buttons_add_pressed() {
	Libre::EntryDialogWindow * dialog = new Libre::EntryDialogWindow(
			_("Add source directory"), 
			_("Enter the url of your git source repository:"), 
			_("url: example.org/your/source.git")
	);

	dialog->show_all();

	dialog->get_ok_button()->signal_clicked().connect([dialog, this]() {
		dialog->close();
		delete dialog;

		Glib::Thread::create([dialog, this]() {
			this->package_manager->install(dialog->get_entry()->get_text());
			this->sync_sources_dispatcher.emit();
		});
	}, false);

	dialog->get_entry()->signal_key_press_event().connect([dialog](GdkEventKey * event) -> gboolean {
		if (event->keyval == 65293) {
			dialog->get_ok_button()->clicked();
		}
		return false;
	}, false);

	dialog->get_cancel_button()->signal_clicked().connect([dialog]() {
		dialog->close();
		delete dialog;
	});
}

void Libre::PreferencesWindow::manage_buttons_remove_pressed() {
	
	std::vector<std::string> packages = this->package_manager->get_packages();
	Libre::ComboDialogWindow * dialog = new Libre::ComboDialogWindow(
			_("Remove source directory"), _("Chose the repository you want to be removed:"), packages);

	dialog->show_all();

	dialog->get_ok_button()->signal_clicked().connect([dialog, this]() {
		dialog->close();

		Glib::Thread::create([dialog, this]() {
			this->package_manager->remove(dialog->get_combo()->get_active_text());
			this->sync_sources_dispatcher.emit();
		});

		delete dialog;
	});

	dialog->get_cancel_button()->signal_clicked().connect([dialog]() {
		dialog->close(),
		delete dialog;
	});
}
