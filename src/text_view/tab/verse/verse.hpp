#ifndef LIBRE_TEXT_VIEW_VERSE_HPP
#define LIBRE_TEXT_VIEW_VERSE_HPP

#include <gtkmm.h>
#include <glibmm/i18n.h>
#include <tsl/ordered_map.h>

namespace Libre {
	class TextViewVerse : public Gtk::VBox {
		private:
			Gtk::HBox header_box;
			Gtk::CheckButton button;
			Gtk::Label caption;
			Gtk::Label verse;
			tsl::ordered_map<std::string, std::string> * strongs;
			sigc::signal<void, std::string> * trigger_search;
			sigc::signal<void, std::string> * toggle_note;
			sigc::signal<bool, const std::string &> * note_exists;

		public:
			TextViewVerse();
			~TextViewVerse() = default;

			void clear();
			void show_if_not_empty();
			void set_caption(const std::string &);
			void set_verse(const std::string &);
			void set_strongs(tsl::ordered_map<std::string, std::string> *);
			void set_trigger_search(sigc::signal<void, std::string> *);
			void set_note_exits(sigc::signal<bool, const std::string &> *);
			void set_toggle_note(sigc::signal<void, std::string> *);
			void label_populate_popup(Gtk::Menu *);

			Gtk::Label * get_caption_label();
			Gtk::Label * get_verse_label();
			Gtk::CheckButton * get_check_button();
	};
}

#endif
