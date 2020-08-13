#ifndef DIALOG_WINDOW_HPP
#define DIALOG_WINDOW_HPP

#include <gtkmm.h>
#include <glibmm/i18n.h>
#include <vector>

namespace Libre {
	class DialogWindow : public Gtk::Window {
		protected:
			Gtk::VBox main_container;
			Gtk::HBox button_container;
			Gtk::Label info_label;
			Gtk::Button ok_button;
			Gtk::Button cancel_button;
		public:
			DialogWindow(const std::string &, const std::string &);
			virtual ~DialogWindow() = default;

			Gtk::VBox * get_main_container();
			Gtk::HBox * get_button_container();
			Gtk::Label * get_info_label();
			Gtk::Button * get_ok_button();
			Gtk::Button * get_cancel_button();
	};

	class ComboDialogWindow : public DialogWindow {
		protected:
			Gtk::ComboBoxText combo;

		public:
			ComboDialogWindow(const std::string &, const std::string &, const std::vector<std::string> &);
			virtual ~ComboDialogWindow() = default;
			Gtk::ComboBoxText * get_combo();
	};

	class EntryDialogWindow : public DialogWindow {
		protected:
			Gtk::Entry entry;
		public:
			EntryDialogWindow(const std::string &, const std::string &, const std::string &);
			Gtk::Entry * get_entry();
	};
}

#endif
