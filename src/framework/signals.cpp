#include "framework.hpp"

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


		LOG("-- Create Properties Window");

		this->widgets.preferences_window->restart_application().connect(
				sigc::mem_fun(this, &Framework::restart));

		this->widgets.preferences_window->sync_source_combo().connect(
				sigc::mem_fun(this->widgets.main_window->get_sync_sources_dispatcher(), &Glib::Dispatcher::emit));

		this->widgets.preferences_window->set_package_manager(
				&this->widgets.package_manager);

		LOG("--> \"start_session\" emmited");
		
		this->widgets.app->add_window(*this->widgets.main_window);
		this->widgets.app->remove_window(*this->widgets.splash_screen);
		this->widgets.main_window->show_all();

		this->widgets.splash_screen->hide();
		this->widgets.splash_screen->get_spinner()->stop();

		// this->widgets_maintext_view->show_information();
		// this->signal_handler.sync_enabled_sources();
		// this->widgets.main.search_entry->grab_focus();

		// ------------------------------------------
		// IF A SEARCH ARGUMENT IS GIVEN
		// ------------------------------------------
		
		if (!this->arg.empty()) {
			this->widgets.main_window->trigger_search_with_history(arg);
		}
	});
}

void Framework::restart() {
	this->widgets.processing.restart_application = true;
	this->widgets.app->quit();
}
