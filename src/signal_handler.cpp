#include "signal_handler.hpp"

// SIGNAL_HANDLER : SEARCH_REQUEST ---------------------------------------------

gboolean SignalHandler::search_request(GdkEventKey * event) {

	if (event->keyval == 65293 && this->widgets->search_entry->get_text() != "") {	// IF ENTER IS PRESSED (KEYCODE: 65293)
		for (int i = 0; i < this->widgets->combo_boxes.size(); i++) {
			this->widgets->combo_boxes[i].set_button_sensitivity(Gtk::SENSITIVITY_OFF);
		}

		this->widgets->search_entry->set_editable(false);

		for (int i = 0; i < this->widgets->search_results.size(); i++) {
				this->widgets->search_results[i]->set_text("");
		}
		this->widgets->process_thread = Glib::Thread::create(sigc::mem_fun(*this, &SignalHandler::do_search), true);
	}

	return false;
}

void SignalHandler::source_changed(int id) {
	for (int i = 0; i < this->widgets->combo_boxes.size(); i++) {
		this->widgets->combo_boxes[i].set_button_sensitivity(Gtk::SENSITIVITY_OFF);
	}

	this->widgets->search_entry->set_editable(false);

	for (int i = 0; i < this->widgets->search_results.size(); i++) {
			this->widgets->search_results[i]->set_text("");
	}
	this->widgets->process_thread = Glib::Thread::create(sigc::bind<int>(sigc::mem_fun(*this, &SignalHandler::do_replacement), id), true);
}

void SignalHandler::set_text() {
	for (int i = 0; i < this->widgets->search_results.size(); i++) {
		this->widgets->search_results[i]->insert_markup(this->widgets->search_results[i]->end(), this->widgets->found_text[i] + "\n\n");
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
		std::array<std::string, 3> verse = search_engine[0].get_last_search_results()->back();

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
		this->widgets->combo_boxes[i].set_button_sensitivity(Gtk::SENSITIVITY_ON);
	}
	this->widgets->search_entry->set_editable(true);

	this->widgets->delete_thread_dispatcher.emit();
}

void SignalHandler::do_replacement(int id) {

	this->search_engine[id].set_source(
		"data/BibleEditions/" +
		this->widgets->sources[std::string(this->widgets->combo_boxes[id].get_active_text())].as<std::string>()
	);

	std::vector<std::array<std::string, 3>> * v = this->search_engine[0].get_last_search_results();

	int x = 0;

	for (std::vector<std::array<std::string, 3>>::iterator i = v->begin(); i != v->end(); i++) {
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

	this->widgets->search_entry->set_progress_fraction(0.0);
	for (int i = 0; i < this->widgets->combo_boxes.size(); i++) {
		this->widgets->combo_boxes[i].set_button_sensitivity(Gtk::SENSITIVITY_ON);
	}
	this->widgets->search_entry->set_editable(true);

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

	this->widgets->combo_boxes.back().signal_changed().connect(	// SEARCH_ENTRY : WHEN KEY PRESSED
		sigc::bind<int>(
		sigc::mem_fun(this, &SignalHandler::source_changed),
		this->widgets->combo_boxes.size() - 1),
		false
	);

	this->widgets->panels->show_all();
}
