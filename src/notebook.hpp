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

#include "path.hpp"
#include "exporter.hpp"


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
		typedef sigc::signal<void, int> type_signal_refresh;
		type_signal_refresh m_signal_refresh;

		bool note_exists(const std::string & pos) {
			rapidxml::xml_node<> * notebook = this->notes_file.first_node("notebook");

			for (rapidxml::xml_node<> * note = notebook->first_node("note"); note; note = note->next_sibling()) {
				if (note->first_attribute("name")->value() == pos) {
					return true;
				}
			}

			return false;
		}


	public:
		NoteBook();
		virtual ~NoteBook();

		void open_note(const std::string & verse);
		void save_note();
		void export_note(std::string &, std::string &, std::string &);

		void change_style_of_selection();
		void on_content_change();
		void on_new_selection(const Gtk::TextBuffer::iterator & i, const Glib::RefPtr<Gtk::TextBuffer::Mark> & m);

		void set_file(const std::string & p) {
			if (std::experimental::filesystem::exists(p)) {
				rapidxml::file<> file(p.c_str());
				char * content = this->notes_file.allocate_string(file.data());
				this->notes_file.parse<rapidxml::parse_no_data_nodes>(content);
			} else {
				rapidxml::xml_node<> * notebook = this->notes_file.allocate_node(rapidxml::node_element, "notebook");
				this->notes_file.append_node(notebook);
			}

			this->path = p;

			if (this->active_position != nullptr) {
				this->open_note(this->active_position->first_attribute("name")->value());
			} else {
				this->save_note();
			}
		}

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
} /* Libre */

#endif
