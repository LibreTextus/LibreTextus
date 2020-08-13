#include "../signal_handler.hpp"

void SignalHandler::add_source_dir() {
	LOG("--> \"add_source_dir\" emmited");
	
	Libre::EntryDialogWindow * dialog = new Libre::EntryDialogWindow(_("Add source directory"), _("Enter the url of your git source repository:"), _("url: example.org/your/source.git"));;

	dialog->show_all();

	dialog->get_ok_button()->signal_clicked().connect([dialog, this]() {
		dialog->close();
		delete dialog;

		Glib::Thread::create([dialog, this]() {
			this->widgets->package_manager.install(dialog->get_entry()->get_text());
			this->widgets->processing.sync_sources_dispatcher.emit();
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

void SignalHandler::remove_source_dir() {
	LOG("--> \"remove_source_dir\" emmited");

	std::vector<std::string> packages = this->widgets->package_manager.get_packages();
	Libre::ComboDialogWindow * dialog = new Libre::ComboDialogWindow(
			_("Remove source directory"), _("Chose the repository you want to be removed:"), packages);

	dialog->show_all();

	dialog->get_ok_button()->signal_clicked().connect([dialog, this]() {
		dialog->close();

		Glib::Thread::create([dialog, this]() {
			this->widgets->package_manager.remove(dialog->get_combo()->get_active_text());
			this->widgets->processing.sync_sources_dispatcher.emit();
		});

		delete dialog;
	});

	dialog->get_cancel_button()->signal_clicked().connect([dialog]() {
		dialog->close(),
		delete dialog;
	});
}

void SignalHandler::sync_enabled_sources() {
	LOG("--> \"sync_enabled_sources\" emmited");

	this->sync_combo_boxes();
}

void SignalHandler::sync_combo_boxes() {

	for (int i = 0; i < this->widgets->main.combo_boxes.size(); i++) {
		Gtk::HBox * parent = this->widgets->main.headers[i];
		std::vector<Gtk::Widget *> v = parent->get_children();

		int pos = std::distance(v.end(), std::find(v.begin(), v.end(), this->widgets->main.combo_boxes[i]));

		delete this->widgets->main.combo_boxes[i];
		this->widgets->main.combo_boxes[i] = new Gtk::ComboBoxText;

		parent->pack_end(*this->widgets->main.combo_boxes[i], Gtk::PACK_SHRINK, 0);
		parent->reorder_child(*this->widgets->main.combo_boxes[i], pos);

		this->widgets->main.combo_boxes[i]->show();

		this->widgets->append_sources(this->widgets->main.combo_boxes[i]);

		this->widgets->main.combo_boxes[i]->signal_changed().connect(
			sigc::bind<Gtk::ComboBoxText *>(
			sigc::mem_fun(this, &SignalHandler::source_changed),
			this->widgets->main.combo_boxes[i]),
			false
		);
	}
}
