#include "../history_button.hpp"

Libre::HistoryButton::HistoryButton() {
	this->set_name("history_button");

	this->history_button.signal_clicked().connect(
			sigc::mem_fun(this, &Libre::HistoryButton::right_click));

	this->pack_start(this->history_button, Gtk::PACK_SHRINK, 0);

	this->active_search = -1;
}
