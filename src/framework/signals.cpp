#include "../framework.hpp"

void Framework::connect_app_startup_signal() {
	this->widgets.app->signal_startup().connect([this]() {

		this->widgets.app->add_window(*this->widgets.splash_screen);

		this->widgets.splash_screen->set_position(Gtk::WIN_POS_CENTER);
		this->widgets.splash_screen->get_spinner()->start();
		this->widgets.splash_screen->show_all();

		LOG("--> \"startup\" emmited");
		this->init_session();
	});
}

void Framework::connect_session_init_success_signal() {
	this->widgets.processing.start_session.connect([this]() {

		if (this->widgets.processing.update_thread->joinable()) {
			this->widgets.processing.update_thread->join();
		}

		// ------------------------------------------
		// CREATING THE WINDOWS
		// ------------------------------------------

		LOG("-- Create Main Window");

		Libre::MainWindow::create(&this->widgets, &this->signal_handler);

		LOG("-- Create Properties Window");

		Libre::PreferencesWindow::create(&this->widgets, &this->signal_handler);

		LOG("--> \"start_session\" emmited");
		
		this->widgets.app->add_window(*this->widgets.main.window);
		this->widgets.app->remove_window(*this->widgets.splash_screen);
		this->widgets.main.window->show_all();

		this->widgets.splash_screen->hide();
		this->widgets.splash_screen->get_spinner()->stop();

		this->widgets.main.text_view->show_information();
		this->signal_handler.sync_enabled_sources();
		this->widgets.main.search_entry->grab_focus();

		// ------------------------------------------
		// IF A SEARCH ARGUMENT IS GIVEN
		// ------------------------------------------
		
		if (!this->arg.empty()) {
			this->signal_handler.trigger_search(arg);
		}
	});
}

void Framework::connect_processing_signals() {
	this->widgets.processing.set_text_dispatcher.connect(
			sigc::mem_fun(this->signal_handler, &SignalHandler::set_text));
	
	this->widgets.processing.delete_thread_dispatcher.connect(
			sigc::mem_fun(this->signal_handler, &SignalHandler::delete_thread));

	this->widgets.processing.sync_sources_dispatcher.connect(
			sigc::mem_fun(this->signal_handler, &SignalHandler::sync_enabled_sources));
}
