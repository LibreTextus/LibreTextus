#include "../main.hpp"


void Libre::MainWindow::add_source_dir() {
	LOG("--> \"add_source_dir\" emmited");
	
	Libre::EntryDialogWindow * dialog = new Libre::EntryDialogWindow(_("Add source directory"), _("Enter the url of your git source repository:"), _("url: example.org/your/source.git"));;

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

void Libre::MainWindow::remove_source_dir() {
	LOG("--> \"remove_source_dir\" emmited");

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

void Libre::MainWindow::sync_combo_boxes() {

	this->header.get_combo_content()->clear();

	std::vector<std::string> v = this->package_manager->get_sources();

	for (std::vector<std::string>::iterator i = v.begin(); i != v.end(); i++) {
		if (this->package_manager->is_enabled(*i)) {
			this->header.get_combo_content()->push_back(*i);
		}
	}

	this->process_finished = false;
	this->mutex.lock();
	this->header.refresh();
	this->mutex.unlock();
	this->process_finished = true;
}
