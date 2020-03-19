#include "signal_handler.hpp"

// SIGNAL_HANDLER : SEARCH_REQUEST ---------------------------------------------

gboolean SignalHandler::search_request(GdkEventKey * event) {

	if (event->keyval == 65293 && this->widgets->search_entry->get_text() != "") {	// IF ENTER IS PRESSED (KEYCODE: 65293)
		for (int i = 0; i < this->widgets->combo_boxes.size(); i++) {
			this->widgets->combo_boxes[i]->set_button_sensitivity(Gtk::SENSITIVITY_OFF);
			this->widgets->search_results[i]->set_text("");
		}

		this->widgets->search_entry->set_editable(false);
		this->widgets->action_group->set_sensitive(false);
		this->widgets->replace_id = -1;

		this->widgets->process_thread = Glib::Thread::create(sigc::mem_fun(*this, &SignalHandler::do_search), true);
	}

	return false;
}

void SignalHandler::source_changed(Gtk::ComboBoxText * b) {
	for (int i = 0; i < this->widgets->combo_boxes.size(); i++) {
		this->widgets->combo_boxes[i]->set_button_sensitivity(Gtk::SENSITIVITY_OFF);
	}

	this->widgets->search_entry->set_editable(false);
	this->widgets->action_group->set_sensitive(false);
	this->widgets->replace_id = 0;

	for (;this->widgets->replace_id < this->widgets->combo_boxes.size(); this->widgets->replace_id++) {
		if (b == this->widgets->combo_boxes[this->widgets->replace_id]) {
			break;
		}
	}

	this->widgets->search_results[this->widgets->replace_id]->set_text("");

	this->widgets->process_thread = Glib::Thread::create(sigc::mem_fun(*this, &SignalHandler::do_replacement), true);
}

void SignalHandler::set_text() {
	if (this->widgets->replace_id == -1) {
		for (int i = 0; i < this->widgets->search_results.size(); i++) {
			this->widgets->search_results[i]->insert_markup(this->widgets->search_results[i]->end(), this->widgets->found_text[i] + "\n\n");
		}
	} else {
		this->widgets->search_results[this->widgets->replace_id]->insert_markup(
			this->widgets->search_results[this->widgets->replace_id]->end(),
			this->widgets->found_text[this->widgets->replace_id] + "\n\n"
		);
	}

	this->widgets->procress_finished = true;
}

void SignalHandler::delete_thread() {
	if (this->widgets->process_thread) {
		if (this->widgets->process_thread->joinable()) {
			this->widgets->process_thread->join();
		}
	}
}

void SignalHandler::do_search() {
	this->search_engine[0].set_search_argument(this->widgets->search_entry->get_text());

	while (this->search_engine[0].search(&this->widgets->found_text[0])) {
		std::array<std::string, 3> verse = this->search_engine[0].get_last_search_results()->back();

		for (int i = 1; i < this->widgets->search_results.size(); i++) {
			this->widgets->found_text[i] = "<span font_weight=\"ultralight\">" + verse[0] + ", " + verse[1] + ", " + verse[2] + "</span>\n\n";
			this->widgets->found_text[i] += this->search_engine[i].get_verse(verse[0], verse[1], verse[2]);
		}

		this->widgets->set_text_dispatcher.emit();

		this->widgets->procress_finished = false;
		while (!this->widgets->procress_finished) {}
		this->widgets->search_entry->set_progress_fraction(this->search_engine[0].get_progress());
	}

	this->widgets->search_entry->set_progress_fraction(0.0);

	for (int i = 0; i < this->widgets->combo_boxes.size(); i++) {
		this->widgets->combo_boxes[i]->set_button_sensitivity(Gtk::SENSITIVITY_ON);
	}
	this->widgets->search_entry->set_editable(true);
	this->widgets->action_group->set_sensitive(true);

	this->widgets->delete_thread_dispatcher.emit();
}

void SignalHandler::do_replacement() {

	this->search_engine[this->widgets->replace_id].set_source(
		"data/BibleEditions/" +
		this->widgets->sources[std::string(this->widgets->combo_boxes[this->widgets->replace_id]->get_active_text())].as<std::string>()
	);

	std::vector<std::array<std::string, 3>> * v = this->search_engine[0].get_last_search_results();

	int x = 0;

	for (std::vector<std::array<std::string, 3>>::iterator i = v->begin(); i != v->end() && v->size() != 0; i++) {
		this->widgets->procress_finished = false;
		for (int t = 0; t < this->widgets->found_text.size(); t++) {
			this->widgets->found_text[t] = "<span font_weight=\"ultralight\">" + (*i)[0] + ", " + (*i)[1] + ", " + (*i)[2] + "</span>\n\n";
			this->widgets->found_text[t] += this->search_engine[t].get_verse((*i)[0], (*i)[1], (*i)[2]);
		}
		this->widgets->set_text_dispatcher.emit();
		while (!this->widgets->procress_finished) {}
		x++;
		this->widgets->search_entry->set_progress_fraction(x / static_cast<float>(v->size()));
	}

	for (int i = 0; i < this->widgets->combo_boxes.size(); i++) {
		this->widgets->combo_boxes[i]->set_button_sensitivity(Gtk::SENSITIVITY_ON);
	}
	this->widgets->search_entry->set_editable(true);
	this->widgets->action_group->set_sensitive(true);
	this->widgets->search_entry->set_progress_fraction(0.0);

	this->widgets->delete_thread_dispatcher.emit();
}

void SignalHandler::quit() {
	this->widgets->app->quit();
}

void SignalHandler::toggle_fullscreen() {
	if (this->widgets->is_fullscreen)
		this->widgets->window->unfullscreen();
	else
		this->widgets->window->fullscreen();

	this->widgets->is_fullscreen = !this->widgets->is_fullscreen;
}

void SignalHandler::toggle_iconify() {
	this->widgets->window->iconify();
}

void SignalHandler::toggle_search() {
	this->widgets->search_entry->grab_focus_without_selecting();
}

void SignalHandler::toggle_preferences() {
	this->widgets->preferences_window->show_all();
	this->widgets->preferences_window->raise();
}

void SignalHandler::zoom_in() {
	this->widgets->font_size += 2;
	this->widgets->font_size_css->load_from_data("* { font-size: " + std::to_string(this->widgets->font_size) + "px; }");
}

void SignalHandler::zoom_out() {
	this->widgets->font_size -= 2;
	if (this->widgets->font_size < 1) {
		this->widgets->font_size = 1;
	}
	this->widgets->font_size_css->load_from_data("* { font-size: " + std::to_string(this->widgets->font_size) + "px; }");
}

void SignalHandler::zoom_reset() {
	this->widgets->font_size = settings.get<int>("font_size");
	this->widgets->font_size_css->load_from_data("* { font-size: " + std::to_string(this->widgets->font_size) + "px; }");
}

void SignalHandler::theme_changed() {
	settings.set("theme-active", this->widgets->preferences_theme_combo->get_active_text());

	if(!this->widgets->css->load_from_path("data/" + this->widgets->preferences_theme_combo->get_active_text() + ".css")) {
			std::cerr << "Failed to load css\n";
	}
}

void SignalHandler::default_font_size_changed() {
	this->widgets->font_size = this->widgets->font_size_spinbutton->get_value();
	settings.set("font_size", std::to_string(this->widgets->font_size));
	this->widgets->font_size_css->load_from_data("* { font-size: " + std::to_string(this->widgets->font_size) + "px; }");
}

void SignalHandler::add_source() {
	this->search_engine.push_back(SearchEngine("data/BibleEditions/deu/schlachter-1951.yml",
																					"data/BibleEditions/biblebooks.yml"));

	this->search_engine.back().set_mark_argument(this->mark_argument);
	this->search_engine.back().set_header_argument(this->header_argument);

	this->widgets->add_panel();

	this->widgets->combo_boxes.back()->signal_changed().connect(	// SEARCH_ENTRY : WHEN KEY PRESSED
		sigc::bind<Gtk::ComboBoxText *>(
		sigc::mem_fun(this, &SignalHandler::source_changed),
		this->widgets->combo_boxes.back()),
		false
	);

	this->widgets->close_buttons.back()->signal_clicked().connect(	// SEARCH_ENTRY : WHEN KEY PRESSED
		sigc::bind<Gtk::Button *>(
		sigc::mem_fun(this, &SignalHandler::remove_source_by_reference),
		this->widgets->close_buttons.back()),
		false
	);

	this->widgets->panels->show_all();
	this->source_changed(this->widgets->combo_boxes.back());

	this->widgets->add_button->signal_clicked().connect(sigc::mem_fun(this, &SignalHandler::add_source), false);
}

void SignalHandler::remove_source() {
	if (this->search_engine.size() > 1) {
		this->search_engine.pop_back();

		this->widgets->panels->remove(*this->widgets->panels->get_children().back());

		Gtk::TextView * t = this->widgets->text_views.back();
		Gtk::ComboBoxText * c = this->widgets->combo_boxes.back();
		Gtk::HBox * h = this->widgets->headers.back();
		this->widgets->text_views.pop_back();
		this->widgets->combo_boxes.pop_back();
		this->widgets->search_results.pop_back();
		this->widgets->found_text.pop_back();
		this->widgets->headers.pop_back();

		delete h;
		delete t;
		delete c;

		delete this->widgets->add_button;
		this->widgets->add_button = new Gtk::Button;
		this->widgets->add_button->set_image_from_icon_name("list-add", Gtk::ICON_SIZE_BUTTON);
		this->widgets->add_button->set_name("view_button");

		this->widgets->headers.back()->pack_end(*this->widgets->add_button, Gtk::PACK_SHRINK, 0);
		this->widgets->headers.back()->reorder_child(*this->widgets->add_button, 0);
		this->widgets->add_button->show();
		this->widgets->add_button->signal_clicked().connect(sigc::mem_fun(this, &SignalHandler::add_source), false);
	}
}

void SignalHandler::remove_source_by_reference(Gtk::Button * b) {
	if (this->search_engine.size() > 1) {

		std::vector<std::array<std::string, 3>> last_search_results = *this->search_engine[0].get_last_search_results();

		int i = 0;
		for (;i < this->widgets->close_buttons.size(); i++) {
			if (b == this->widgets->close_buttons[i]) {
				this->widgets->close_buttons.erase(this->widgets->close_buttons.begin() + i);
				delete b;
				break;
			}
		}

		this->search_engine.erase(this->search_engine.begin());

		this->widgets->panels->remove(*this->widgets->panels->get_children()[i]);

		Gtk::TextView * t = this->widgets->text_views[i];
		Gtk::ComboBoxText * c = this->widgets->combo_boxes[i];
		Gtk::HBox * h = this->widgets->headers[i];
		this->widgets->text_views.erase(this->widgets->text_views.begin() + i);
		this->widgets->combo_boxes.erase(this->widgets->combo_boxes.begin() + i);
		this->widgets->headers.erase(this->widgets->headers.begin() + i);

		delete h;
		delete t;
		delete c;

		this->widgets->search_results.erase(this->widgets->search_results.begin() + i);
		this->widgets->found_text.erase(this->widgets->found_text.begin() + i);

		if (this->widgets->add_button != nullptr && i != this->widgets->close_buttons.size()) {
			this->widgets->add_button->get_parent()->remove(*this->widgets->add_button);
			delete this->widgets->add_button;
		}

		this->widgets->add_button = new Gtk::Button;
		this->widgets->add_button->set_image_from_icon_name("list-add", Gtk::ICON_SIZE_BUTTON);
		this->widgets->add_button->set_name("view_button");

		this->widgets->headers.back()->pack_end(*this->widgets->add_button, Gtk::PACK_SHRINK, 0);
		this->widgets->headers.back()->reorder_child(*this->widgets->add_button, 0);

		this->widgets->add_button->show();

		this->search_engine[0].set_last_search_result(last_search_results);
		this->widgets->add_button->signal_clicked().connect(sigc::mem_fun(this, &SignalHandler::add_source), false);
	}
}
