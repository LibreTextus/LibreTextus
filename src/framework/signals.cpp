#include "framework.hpp"
#include "notebook/notebook.hpp"
#include "window/main/main.hpp"

void Framework::connect_app_startup_signal() {
	this->app->signal_startup().connect([this]() {

		this->app->add_window(*this->splash_screen);

		this->splash_screen->set_position(Gtk::WIN_POS_CENTER);
		this->splash_screen->get_spinner()->start();
		this->splash_screen->show_all();

		LOG("--> \"startup\" emmited");
		this->init_session();
	});
}

void Framework::connect_session_init_success_signal() {
	this->start_session.connect([this]() {

		if (this->update_thread->joinable()) {
			this->update_thread->join();
		}

		// ------------------------------------------
		// CREATING THE WINDOWS
		// ------------------------------------------


		LOG("-- Create Properties Window");

		this->preferences_window->restart_application().connect(
				sigc::mem_fun(this, &Framework::restart));

		this->preferences_window->sync_source_combo().connect(
				sigc::mem_fun(this->main_window->get_sync_sources_dispatcher(), &Glib::Dispatcher::emit));

		this->preferences_window->refresh_theme().connect(
				sigc::mem_fun(this->main_window, &Libre::MainWindow::refresh_theme));

		this->preferences_window->get_keybindings_pane()->get_up()->get_element()->refresh_shortcuts().connect(
				sigc::mem_fun(this->main_window->get_view_pane()->get_text_view(), &Libre::TextView::refresh_shortcuts));

		this->preferences_window->get_keybindings_pane()->get_down()->get_element()->refresh_shortcuts().connect(
				sigc::mem_fun(this->main_window->get_view_pane()->get_text_view(), &Libre::TextView::refresh_shortcuts));
		
		this->preferences_window->get_keybindings_pane()->get_top()->get_element()->refresh_shortcuts().connect(
				sigc::mem_fun(this->main_window->get_view_pane()->get_text_view(), &Libre::TextView::refresh_shortcuts));

		this->preferences_window->get_keybindings_pane()->get_bottom()->get_element()->refresh_shortcuts().connect(
				sigc::mem_fun(this->main_window->get_view_pane()->get_text_view(), &Libre::TextView::refresh_shortcuts));

		this->preferences_window->get_keybindings_pane()->signal_refresh_mode().connect(
				sigc::mem_fun(this->main_window->get_view_pane()->get_notebook(), &Libre::NoteBook::refresh_mode));

		this->preferences_window->set_package_manager(
				&this->package_manager);

		LOG("--> \"start_session\" emmited");
		
		this->app->add_window(*this->main_window);
		this->app->remove_window(*this->splash_screen);
		this->main_window->show_all();

		this->splash_screen->hide();
		this->splash_screen->get_spinner()->stop();

		// ------------------------------------------
		// IF A SEARCH ARGUMENT IS GIVEN
		// ------------------------------------------
		
		if (!this->arg.empty()) {
			this->main_window->trigger_search_with_history(arg);
		}
	});
}

void Framework::restart() {
	this->restart_application = true;
	this->app->quit();
}
