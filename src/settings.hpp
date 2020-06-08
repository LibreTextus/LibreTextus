#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <yaml-cpp/yaml.h>
#include <regex>
#include <iostream>
#include <fstream>
#include <experimental/filesystem>

#include "path.hpp"

// -----------------------------------------------------------------------------
// THIS CLASS IS FOR READ AND WRITE THE SETTINGS STORED IN THE YAML FILE
// -----------------------------------------------------------------------------

class Settings {
public:
	Settings () = default;
	virtual ~Settings () = default;

	// SETTINGS::GET<T> ----------------------------------------------------------
	// THIS FUNCTION RETURNS THE VALUE STORED IN THE SETTINGS FILE IN THE DEMANDED
	// TYPE
	// ---------------------------------------------------------------------------

	template <typename T>
	T get(std::string arg) {
		YAML::Node output = YAML::LoadFile(HOME("settings.yml"));

		std::regex e("-");
		std::smatch m;

		while (std::regex_search(arg, m, e)) {
			output = output[m.prefix().str()];
			arg = m.suffix().str();
		}

		if (!output[arg]) {
			output[arg] = "";
		}

		return output[arg].as<T>();
	}

	// SETTINGS::GET -------------------------------------------------------------
	// THIS FUNCTION RETURNS THE VALUE STORED IN THE SETTINGS AS YAML::NODE
	// ---------------------------------------------------------------------------

	YAML::Node get(std::string arg) {
		YAML::Node output = YAML::LoadFile(HOME("settings.yml"));

		std::regex e("-");
		std::smatch m;

		while (std::regex_search(arg, m, e)) {
			output = output[m.prefix().str()];
			arg = m.suffix().str();
		}

		return output[arg];
	}

	// SETTINGS::SET -------------------------------------------------------------
	// THIS FUNCTION SAVES THE SETTNGS IN THE SETTINGS FILE
	// ---------------------------------------------------------------------------

	void set(std::string tag, std::string arg) {
		YAML::Node node = YAML::LoadFile(HOME("settings.yml"));

		YAML::iterator i = node.begin();

		std::regex e("-");
		std::smatch m;
		std::regex_search(tag, m, e);

		for (; i != node.end() && m.empty() && i->first.as<std::string>() != tag; i++) {}

		while (std::regex_search(tag, m, e)) {
			for (; i != node.end(); i++) {
				if (i->first.as<std::string>() == m.prefix().str()) {
					i = i->second.begin();
					break;
				}
			}
			tag = m.suffix().str();
		}

		i->second = arg;

		YAML::Emitter emitter;
		emitter << node;

		std::ofstream fout(HOME("settings.yml"));
		if (fout.is_open()) {
			fout << emitter.c_str();
			fout.close();
		}
	}
};

#endif
