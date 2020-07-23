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
