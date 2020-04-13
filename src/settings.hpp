#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <yaml-cpp/yaml.h>
#include <regex>
#include <iostream>
#include <fstream>

// -----------------------------------------------------------------------------
// THIS CLASS IS FOR READ AND WRITE THE SETTINGS STORED IN THE YAML FILE
// -----------------------------------------------------------------------------

class Settings {
public:
	Settings () = default;
	virtual ~Settings () = default;

	template <typename T>
	T get(std::string arg) {
		YAML::Node output = YAML::LoadFile("data/settings.yml");

		std::regex e("-");
		std::smatch m;

		while (std::regex_search(arg, m, e)) {
			output = output[m.prefix().str()];
			arg = m.suffix().str();
		}

		return output[arg].as<T>();
	}

	YAML::Node get(std::string arg) {
		YAML::Node output = YAML::LoadFile("data/settings.yml");

		std::regex e("-");
		std::smatch m;

		while (std::regex_search(arg, m, e)) {
			output = output[m.prefix().str()];
			arg = m.suffix().str();
		}

		return output[arg];
	}

	void set(std::string tag, std::string arg) {
		YAML::Node node = YAML::LoadFile("data/settings.yml");

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

		std::ofstream fout("data/settings.yml");
		if (fout.is_open()) {
			fout << emitter.c_str();
			fout.close();
		}
	}
};

#endif
