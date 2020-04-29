#ifndef LIBRE_TEXT_VIEW
#define LIBRE_TEXT_VIEW

#include <gtkmm.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

namespace Libre {
	class TextView : public Gtk::ScrolledWindow {
	private:
		Gtk::VBox main;
		Gtk::Overlay overlay;
		Gtk::Label information_text;
		std::vector<Gtk::HBox *> verses;
		std::vector<std::string> captions;
		std::vector<std::vector<std::string *>> content;
		int scroll_status;
		int padding_x;
		int padding_y;
		int max_verses;

	public:
		TextView(const std::string & info_text);
		virtual ~TextView() = default;

		void clear();
		void add_verse(const std::string & caption, const std::vector<std::string *> & verses_content);
		void replace_verse(const std::string & caption, const int & version, const std::string * content);
		void _display();
		bool on_scroll_event(GdkEventScroll * scroll_event);
		void show_information();
		void show_content();

		void remove_tab(const int & id);

	};
}

#endif
