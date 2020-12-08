#include "../main.hpp"

void Libre::MainWindow::add_source() {
	LOG("--> \"add_source\" emmited");

	this->add_new_search_engine();

	this->header.append();

	this->view_pane.get_text_view()->append_tab(this->package_manager->get_source_path(this->settings.get_attribute("startupfile", "file")));

	this->connect_signals_of_new_buttons();

	this->header.get_elements()->back()->get_combo()->set_active_text(this->settings.get_attribute("startupfile", "file"));

	this->show_all();

	this->source_changed(this->header.get_elements()->back());

}

void Libre::MainWindow::add_new_search_engine() {
	this->search_engine.push_back(
			this->package_manager->get_source_path(this->settings.get_attribute("startupfile", "file"))
	);

	this->search_engine.back().set_mark_argument(this->mark_argument);
}

void Libre::MainWindow::connect_signals_of_new_buttons() {
	this->header.get_elements()->back()->get_combo()->signal_changed().connect(
		sigc::bind<Libre::HeaderElement *>(
		sigc::mem_fun(this, &Libre::MainWindow::source_changed),
		this->header.get_elements()->back()),
		false
	);

	this->header.get_elements()->back()->get_close()->signal_clicked().connect(
		sigc::bind<Libre::HeaderElement *>(
		sigc::mem_fun(this, &Libre::MainWindow::remove_source_by_reference),
		this->header.get_elements()->back()),
		false
	);
}

void Libre::MainWindow::remove_source() {
	LOG("--> \"remove_source\" emmited");
	this->remove_source_by_reference(this->header.get_elements()->back());
}

void Libre::MainWindow::remove_source_by_reference(Libre::HeaderElement * e) {
	LOG("--> \"remove_source_by_reference\" emmited");
	if (this->search_engine.size() > 1) {

		int i = this->get_id(e);

		std::vector<std::string> last_search_results = *this->search_engine[0].get_last_search_results();
		
		this->header.remove_element(i);
		this->search_engine.erase(this->search_engine.begin());

		this->search_engine[0].set_last_search_result(last_search_results);
		this->view_pane.get_text_view()->remove_tab(i);
	}
}

int Libre::MainWindow::get_id(Libre::HeaderElement * e) {

	int i = 0;
	for (;i < this->header.get_elements()->size(); i++) {
		if (e == (*this->header.get_elements())[i]) {
			break;
		}
	}

	return i;
}
