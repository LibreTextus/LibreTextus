#include "text_view.hpp"

sigc::signal<void, std::string> Libre::TextView::signal_toggle_note() {
	return this->m_signal_toggle_note;
}

sigc::signal<void, std::string> Libre::TextView::signal_right_click_search() {
	return this->m_signal_right_click_search;
}

