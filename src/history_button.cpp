#include "history_button.hpp"

Libre::HistoryButton::HistoryButton() {

	this->set_name("history_button");

	this->history_button.signal_clicked().connect(sigc::mem_fun(this, &Libre::HistoryButton::right_click));

	this->pack_start(this->history_button, Gtk::PACK_SHRINK, 0);

	this->active_search = -1;
}

void Libre::HistoryButton::right_click() {
	if (!this->search_history.empty()) {

		this->check_buttons.clear();

		int begin, end;

		if (this->search_history.size() < 10) {
			begin = 0;
			end = this->search_history.size();
		} else {
			if (this->search_history.size() - this->active_search <= 5) {
				begin = this->search_history.size() - 10;
				end = this->search_history.size();
			} else {
				if (this->active_search - 5 < 0) {
					begin = 0;
					end = 10;
				} else {
					begin = this->active_search - 5;
					end = this->active_search + 5;
				}
			}
		}

		for (int i = begin; i < end; i++) {
			this->check_buttons.push_back(Gtk::CheckMenuItem(this->search_history[i]));
			this->check_buttons.back().set_draw_as_radio(true);
			this->check_buttons.back().set_active(i == this->active_search);
			this->check_buttons.back().property_width_request() = 150;

			this->check_buttons.back().signal_button_release_event().connect([this, i, begin](GdkEventButton * event) -> bool {
				if (!this->check_buttons[i - begin].get_active()) {
					this->m_trigger_search.emit(this->search_history[i]);
					this->active_search = i;
				}
				return false;
			});

			this->popup_menu.prepend(this->check_buttons.back());
		}

		this->popup_menu.show_all();

		this->popup_menu.popup(0, 0);
	}
}

void Libre::HistoryButton::button_pressed(bool forward) {
	if ((this->active_search > 0 && !forward) || (this->active_search + 1 != this->search_history.size() && forward)) {
		(forward ? this->active_search++ : this->active_search--);
		this->m_trigger_search.emit(this->search_history[this->active_search]);
	}
}

void Libre::HistoryButton::add_to_history(std::string arg) {
	this->active_search++;

	if (this->active_search != this->search_history.size()) {
		while (this->active_search != this->search_history.size()) {
			this->search_history.pop_back();
		}
	}

	this->search_history.push_back(arg);
}
