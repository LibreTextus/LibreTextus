#include "../signal_handler.hpp"

void SignalHandler::add_source() {
	LOG("--> \"add_source\" emmited");

	this->add_new_search_engine(),
	
	this->widgets->add_panel();
	this->widgets->main.text_view->append_tab(this->widgets->package_manager.get_source_path(this->settings.get_attribute("startupfile", "file")));

	this->connect_signals_of_new_buttons();

	this->widgets->main.add_button->signal_clicked().connect(sigc::mem_fun(this, &SignalHandler::add_source), false);

	this->widgets->main.panels->show_all();
	this->source_changed(this->widgets->main.combo_boxes.back());
}

void SignalHandler::add_new_search_engine() {
	this->widgets->search_engine.push_back(
		SearchEngine(
			this->widgets->package_manager.get_source_path(this->settings.get_attribute("startupfile", "file")))
	);

	this->widgets->search_engine.back().set_mark_argument(this->mark_argument);
}

void SignalHandler::connect_signals_of_new_buttons() {
	this->widgets->main.combo_boxes.back()->signal_changed().connect(
		sigc::bind<Gtk::ComboBoxText *>(
		sigc::mem_fun(this, &SignalHandler::source_changed),
		this->widgets->main.combo_boxes.back()),
		false
	);

	this->widgets->main.close_buttons.back()->signal_clicked().connect(
		sigc::bind<Gtk::Button *>(
		sigc::mem_fun(this, &SignalHandler::remove_source_by_reference),
		this->widgets->main.close_buttons.back()),
		false
	);
}

void SignalHandler::remove_source() {
	LOG("--> \"remove_source\" emmited");
	this->remove_source_by_reference(this->widgets->main.close_buttons.back());
}

void SignalHandler::remove_source_by_reference(Gtk::Button * b) {
	LOG("--> \"remove_source_by_reference\" emmited");
	if (this->widgets->search_engine.size() > 1) {

		int i = this->get_id_close_button_and_erase(b);

		std::vector<std::string> last_search_results = *this->widgets->search_engine[0].get_last_search_results();
		
		this->remove_tab_index(i);
		
		this->move_add_button(i);

		this->widgets->search_engine[0].set_last_search_result(last_search_results);
		this->widgets->main.text_view->remove_tab(i);
	}
}

int SignalHandler::get_id_close_button_and_erase(Gtk::Button * b) {

	int i = 0;
	for (;i < this->widgets->main.close_buttons.size(); i++) {
		if (b == this->widgets->main.close_buttons[i]) {
			this->widgets->main.close_buttons.erase(this->widgets->main.close_buttons.begin() + i);
			delete b;
			break;
		}
	}

	return i;
}

void SignalHandler::remove_tab_index(const int & i) {
	this->widgets->search_engine.erase(this->widgets->search_engine.begin());

	this->widgets->main.panels->remove(*this->widgets->main.panels->get_children()[i]);

	Gtk::ComboBoxText * c = this->widgets->main.combo_boxes[i];
	Gtk::HBox * h = this->widgets->main.headers[i];
	this->widgets->main.combo_boxes.erase(this->widgets->main.combo_boxes.begin() + i);
	this->widgets->main.headers.erase(this->widgets->main.headers.begin() + i);

	delete h;
	delete c;
}

void SignalHandler::move_add_button(const int & i) {
		if (this->widgets->main.add_button != nullptr && i != this->widgets->main.close_buttons.size()) {
			this->widgets->main.add_button->get_parent()->remove(*this->widgets->main.add_button);
			delete this->widgets->main.add_button;
			this->widgets->main.add_button = new Gtk::Button;
		}

		this->widgets->main.add_button->set_name("add_button");
		this->widgets->main.add_button->set_always_show_image(true);

		this->widgets->main.headers.back()->pack_end(*this->widgets->main.add_button, Gtk::PACK_SHRINK, 0);
		this->widgets->main.headers.back()->reorder_child(*this->widgets->main.add_button, 0);

		this->widgets->main.add_button->signal_clicked().connect(sigc::mem_fun(this, &SignalHandler::add_source), false);

		this->widgets->main.add_button->show();
}
