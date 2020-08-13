#include "history_button.hpp"

void Libre::HistoryButton::right_click() {
	if (!this->search_history.empty()) {

		this->check_buttons.clear();

		this->get_display_range();
		this->add_history_to_popup(),
		
		this->popup_menu.show_all();

		this->popup_menu.popup(0, 0);
	}
}

void Libre::HistoryButton::button_pressed(bool forward) {
	bool not_out_of_bounds = (this->active_search > 0 && !forward);
	not_out_of_bounds |= (this->active_search + 1 != this->search_history.size() && forward);
	if (not_out_of_bounds) {
		(forward ? this->active_search++ : this->active_search--);
		this->m_trigger_search.emit(this->search_history[this->active_search]);
	}
}

void Libre::HistoryButton::get_display_range() {
	if (this->search_history.size() < 10) {
		this->display_begin = 0;
		this->display_end = this->search_history.size();
	} else {
		if (this->search_history.size() - this->active_search <= 5) {
			this->display_begin = this->search_history.size() - 10;
			this->display_end = this->search_history.size();
		} else {
			if (this->active_search - 5 < 0) {
				this->display_begin = 0;
				this->display_end = 10;
			} else {
				this->display_begin = this->active_search - 5;
				this->display_end = this->active_search + 5;
			}
		}
	}
}

void Libre::HistoryButton::add_history_to_popup() {
	for (int i = this->display_begin; i < this->display_end; i++) {
		this->add_new_history_popup_button(i);
		this->check_buttons.back().set_active(i == this->active_search);
		this->last_check_button_connect_button_signal(i);
		
		this->popup_menu.prepend(this->check_buttons.back());
	}
}

void Libre::HistoryButton::add_new_history_popup_button(const int & i) {
	this->check_buttons.push_back(Gtk::CheckMenuItem(this->search_history[i]));
	this->check_buttons.back().set_draw_as_radio(true);
	this->check_buttons.back().property_width_request() = 150;
}

void Libre::HistoryButton::last_check_button_connect_button_signal(const int & i) {
	this->check_buttons.back().signal_button_release_event().connect(
		[this, i](GdkEventButton * event) -> bool {
			if (!this->check_buttons[i - this->display_begin].get_active()) {
				this->m_trigger_search.emit(this->search_history[i]);
				this->active_search = i;
				}
				return false;
		});
}
