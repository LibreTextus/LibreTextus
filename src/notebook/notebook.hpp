#ifndef LIBRE_NOTEBOOCK_HPP
#define LIBRE_NOTEBOOCK_HPP

#include <gtkmm.h>
#include <iostream>
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <rapidxml/rapidxml_print.hpp>
#include <experimental/filesystem>
#include <fstream>
#include <string>
#include <markdown/markdown.hpp>
#include <glibmm/i18n.h>

#include <path/path.hpp>
#include <exporter/exporter.hpp>


namespace Libre {
	class NoteBook : public Gtk::VBox {
	private:
		Glib::RefPtr<Gtk::TextBuffer> content_buffer;
		Gtk::ScrolledWindow scrolled_window;
		Gtk::TextView text_view;
		rapidxml::xml_document<> notes_file;
		std::string path;
		rapidxml::xml_node<> * active_position;
		Gtk::HBox header;
		Gtk::Label title;
		Gtk::Button close_button;
		Glib::RefPtr<Gtk::TextBuffer::Tag> tag_bold;
		Glib::RefPtr<Gtk::TextBuffer::Tag> tag_italic;
		Glib::RefPtr<Gtk::TextBuffer::Tag> tag_strikethrough;
		Glib::RefPtr<Gtk::TextBuffer::Tag> tag_hidden;
		Glib::RefPtr<Gtk::TextBuffer::Tag> tag_h1;
		Glib::RefPtr<Gtk::TextBuffer::Tag> tag_h2;
		Glib::RefPtr<Gtk::TextBuffer::Tag> tag_h3;
		Glib::RefPtr<Gtk::TextBuffer::Tag> tag_h4;
		Glib::RefPtr<Gtk::TextBuffer::Tag> tag_h5;
		Glib::RefPtr<Gtk::TextBuffer::Tag> tag_h6;
		Glib::RefPtr<Gtk::TextBuffer::Tag> tag_blockquotes;
		MD::String markdown_text;
		typedef sigc::signal<void> type_signal_refresh;
		type_signal_refresh m_signal_refresh;
		
		bool note_exists(const std::string & pos);
		void set_active_position_and_get_content(const std::string &);
		void get_content_from_existing_note(const std::string &);
		void create_new_note_at_position(const std::string &);
		void remove_empty_notes();

		void set_text_view_properties();
		void set_title_properties();
		void set_button_properties();
		void set_header_properties();
		void create_markdown_tags();
		void pack_children();

		void write_to_file();
		void read_from_file(const std::string &);
		void create_new_note_book_node();

		void write_changes_to_node();
		
	public:
		NoteBook();
		virtual ~NoteBook();

		void open_note(const std::string & verse);
		void save_note();
		void export_note(std::string &, std::string &, std::string &);

		void change_style_of_selection();
		void on_content_change();
		void on_new_selection(const Gtk::TextBuffer::iterator, const Glib::RefPtr<Gtk::TextBuffer::Mark>);

		void set_file(const std::string & p);

		rapidxml::xml_node<> * get_xml_root() {
			return this->notes_file.first_node("notebook");
		}

		Gtk::Button * get_close_button() {
			return &this->close_button;
		}

		type_signal_refresh signal_refresh() {
			return this->m_signal_refresh;
		}

		void on_grab_focus() {
			this->text_view.grab_focus();
		}
	};
};

#endif
