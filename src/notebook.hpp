#ifndef LIBRE_NOTEBOOCK_HPP
#define LIBRE_NOTEBOOCK_HPP

#include <gtkmm.h>
#include <iostream>
#include <yaml-cpp/yaml.h>
#include <fstream>
#include <string>
#include <markdown/markdown.hpp>

#include "path.hpp"


namespace Libre {
	class NoteBook : public Gtk::VBox {
	private:
		Glib::RefPtr<Gtk::TextBuffer> content_buffer;
		Gtk::ScrolledWindow scrolled_window;
		Gtk::TextView text_view;
		YAML::Node notes_file;
		std::string path;
		std::string active_position;
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

	public:
		NoteBook();
		virtual ~NoteBook();

		void open_note(const std::string & verse);
		void save_note();

		void change_style_of_selection();
		void on_content_change();
		void on_new_selection(const Gtk::TextBuffer::iterator & i, const Glib::RefPtr<Gtk::TextBuffer::Mark> & m);

		void set_file(YAML::Node & n, std::string p) {
			this->notes_file = n;
			this->path = p;
			this->open_note(this->active_position);
		}

		Gtk::Button * get_close_button() {
			return &this->close_button;
		}
	};
} /* Libre */

#endif
