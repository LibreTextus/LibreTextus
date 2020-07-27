#ifndef PACKAGE_MANAGER
#define PACKAGE_MANAGER

#include <string>
#include <fstream>
#include <stdlib.h>
#include <experimental/filesystem>
#include <boost/regex.hpp>
#include <algorithm>
#include <gtkmm.h>
#include <mutex>
#include <iostream>
#include <glibmm/i18n.h>
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <rapidxml/rapidxml_print.hpp>
#include "settings.hpp"
#include "path.hpp"

namespace Libre {
  class PackageManager {
  private:
    Settings settings;
		rapidxml::xml_document<> sources_doc;
		std::string dummy_path;
		std::vector<std::string> packages;
		std::vector<std::string> sources;

		void create_empty_node();
		void install_default_sources();
		void read_sources_file();
		void install_books_file();

		void write_to_file();

		rapidxml::xml_node<> * get_source_by_name(const std::string &);

		void remove_invalid_paths();
		void add_new_sources(const std::string &);
		void append_source_info_to_list(const std::string &, const std::string &);
		int get_file_name_number(const std::string &, const std::string &);
		
		void add_source_to_source_list(const std::string &, const std::string &, const std::string &);
		void show_message(const std::string &, const std::string &);

  public:
		Glib::Dispatcher update_text;
		std::string header_string;
		std::string info_string;
		std::mutex mtx;

		void connect_dispatcher_signal(Gtk::Label *, Gtk::Label *);

    PackageManager() = default;
    virtual ~PackageManager() = default;


    void init(bool without_update = false);
    void remove(std::string);
    void install(std::string);
    void disable(std::string);
    void enable(std::string);
		void update();
		void refresh_lists();
		void refresh_db(const std::string &);

		std::vector<std::string> & get_packages() {
			return this->packages;
		}

		std::vector<std::string> & get_sources() {
			return this->sources;
		}

		std::string get_source_path(std::string name) {
			rapidxml::xml_node<> * n = this->sources_doc.first_node("sources")->first_node();
			
			for (;n && std::string(n->first_attribute("name")->value()) != name; n = n->next_sibling()) {}
			
			if (!n) {
				return "";
			}
			
			n = n->first_node("path");
			return (n ? n->value() : "");
		}

		bool is_enabled(std::string name) {
			rapidxml::xml_node<> * n = this->sources_doc.first_node("sources")->first_node();
			for (;n && std::string(n->first_attribute("name")->value()) != name; n = n->next_sibling()) {}

			return (std::string(n->first_node("enabled")->value()) == "true");
		}
  };
}

#endif
