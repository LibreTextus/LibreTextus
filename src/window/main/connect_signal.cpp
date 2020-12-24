#include "main.hpp"

void Libre::MainWindow::connect_signals() {
	this->header.get_add()->signal_clicked().connect(sigc::mem_fun(this, &Libre::MainWindow::add_source), false);
	this->search_section.get_search_entry()->signal_key_press_event().connect(sigc::mem_fun(this, &Libre::MainWindow::search_request), false);
	this->search_section.get_history_button()->trigger_search().connect(sigc::mem_fun(this, &Libre::MainWindow::trigger_search));
	this->view_pane.get_text_view()->signal_toggle_note().connect(sigc::mem_fun(this, &Libre::MainWindow::toggle_note));
	this->view_pane.get_text_view()->signal_right_click_search().connect(sigc::mem_fun(this, &Libre::MainWindow::trigger_search_with_history));
	this->view_pane.get_text_view()->signal_append_grammar().connect(sigc::mem_fun(this->view_pane.get_grammar_view(), &Libre::GrammarView::append_label));
	this->view_pane.get_text_view()->signal_clear_grammar().connect(sigc::mem_fun(this->view_pane.get_grammar_view(), &Libre::GrammarView::clear));
	this->view_pane.get_notebook()->get_close_button()->signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(this, &Libre::MainWindow::toggle_note), ""));

	this->view_pane.get_notebook()->signal_key_press_event().connect([this](GdkEventKey * key) -> bool {
			if (key->keyval == GDK_KEY_Escape) {
				this->toggle_note("");
			}
			return false;
	});

	this->view_pane.get_notebook()->signal_refresh().connect(sigc::mem_fun(this->view_pane.get_text_view(), &Libre::TextView::display_all));
	this->set_text_dispatcher.connect(sigc::mem_fun(this, &Libre::MainWindow::set_text));
	this->join_thread_dispatcher.connect(sigc::mem_fun(this, &Libre::MainWindow::join_thread));
	this->sync_sources_dispatcher.connect(sigc::mem_fun(this, &Libre::MainWindow::sync_combo_boxes));
}
