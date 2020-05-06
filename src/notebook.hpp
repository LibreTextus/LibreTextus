#ifndef LIBRE_NOTEBOOCK_HPP
#define LIBRE_NOTEBOOCK_HPP

#include <gtkmm.h>
#include <iostream>
#include <yaml-cpp/yaml.h>
#include <fstream>

namespace Libre {
	class NoteBook : public Gtk::ScrolledWindow {
	private:
		Glib::RefPtr<Gtk::TextBuffer> content_buffer;
		Gtk::TextView text_view;
		YAML::Node notes_file;
		std::string path;
		std::string active_position;
		Gtk::HBox * header;
		Gtk::Label title;

	public:
		NoteBook(Gtk::HBox * h);
		virtual ~NoteBook();

		void open_note(const std::string & verse);
		void safe_note();

		void set_file(YAML::Node & n, std::string p) {
			this->notes_file = n;
			this->path = p;
		}

		void on_content_change();
	};
} /* Libre */

#endif
