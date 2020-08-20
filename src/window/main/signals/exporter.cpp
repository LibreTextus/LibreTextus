#include "../main.hpp"

void Libre::MainWindow::export_notes() {
	Libre::EntryDialogWindow * pos_dialog = new Libre::EntryDialogWindow(_("Export"), _("Passage"), _("eg. Gen, 1,1"));
	pos_dialog->show_all();
	
	pos_dialog->get_ok_button()->signal_clicked().connect([this, pos_dialog]() {
		pos_dialog->close();

		Gtk::FileChooserDialog dialog(*this, _("Choose Directory"), Gtk::FILE_CHOOSER_ACTION_SAVE);
		dialog.add_button(_("Select"), Gtk::ResponseType::RESPONSE_OK);
		dialog.add_button(_("Cancel"), Gtk::ResponseType::RESPONSE_CANCEL);
		dialog.add_choice("suffix", _("Type"), {".md"}, {"Markdown"});
		dialog.set_choice("suffix", ".md");
		dialog.set_create_folders(true);

		int response = dialog.run();

		if (response == Gtk::ResponseType::RESPONSE_OK) {
			std::string pos = pos_dialog->get_entry()->get_text();
			std::string file_name = dialog.get_uri().substr(7);
			std::string source_file = this->package_manager->get_source_path(this->settings.get_attribute("startupfile", "file"));

			if (file_name.substr((file_name.find_last_of(".") == std::string::npos ? 0 : file_name.find_last_of(".")), std::string::npos) != dialog.get_choice("suffix")) {
				file_name += dialog.get_choice("suffix");
			}

			this->view_pane.get_notebook()->export_note(
				pos,
				file_name,
				source_file
			);
		}
		
		delete pos_dialog;
	});

	pos_dialog->get_cancel_button()->signal_clicked().connect([pos_dialog]() {
			pos_dialog->hide();
			pos_dialog->remove();
			delete pos_dialog;
	});
}
