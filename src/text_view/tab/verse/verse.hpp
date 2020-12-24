#ifndef LIBRE_TEXT_VIEW_VERSE_HPP
#define LIBRE_TEXT_VIEW_VERSE_HPP

#include <gtkmm.h>
#include <glibmm/i18n.h>
#include <tsl/ordered_map.h>
#include <vector>

namespace Libre {
	class TextViewVerse : public Gtk::VBox {
		private:
			Gtk::HBox header_box;
			Gtk::CheckButton button;
			Gtk::Label caption;
			Gtk::Label verse;
			tsl::ordered_map<std::string, std::string> * strongs;
			tsl::ordered_map<std::string, std::vector<std::string> *> * grammar;
			sigc::signal<void, std::string> * trigger_search;
			sigc::signal<void, std::string> * toggle_note;
			sigc::signal<bool, const std::string &> * note_exists;
			sigc::signal<void, std::string> * append_grammar;
			sigc::signal<void> * clear_grammar;
			sigc::signal<void, const size_t &, const size_t &, const std::string &> * m_show_strong_in_other;
			Glib::ustring verse_content;
			std::string mark_color;
			int last_mark_index;
			size_t view_index;

		public:
			TextViewVerse(const size_t &);
			~TextViewVerse() = default;

			void clear();
			void show_if_not_empty();
			void set_caption(const std::string &);
			void set_verse(const std::string &);
			void set_strongs(tsl::ordered_map<std::string, std::string> *);
			void set_grammar(tsl::ordered_map<std::string, std::vector<std::string> *> *);
			void set_trigger_search(sigc::signal<void, std::string> *);
			void set_note_exits(sigc::signal<bool, const std::string &> *);
			void set_toggle_note(sigc::signal<void, std::string> *);
			void set_append_grammar(sigc::signal<void, std::string> *);
			void set_clear_grammar(sigc::signal<void> *);
			void set_show_similar_strong(sigc::signal<void, const size_t &, const size_t &, const std::string &> *);
			void label_populate_popup(Gtk::Menu *);
			bool label_mouse_motion(GdkEventMotion *);
			bool is_non_word(const char & c);
			std::string get_mark_color();
			void mark_similar_strong(const size_t &, const std::string &);
			void refresh_theme();


			Gtk::Label * get_caption_label();
			Gtk::Label * get_verse_label();
			Gtk::CheckButton * get_check_button();
	};
}

#endif
