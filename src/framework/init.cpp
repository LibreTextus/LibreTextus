#include "framework.hpp"

int Framework::init(std::string a) {
	LOG_RESET();
	LOG("--------------------- LOG BEGIN ---------------------");

	this->arg = a;

	this->widgets.processing.restart_application = false;

	this->create_home_directory_if_missing();
	this->create_settings_file_if_missing();
	this->init_locales();

	LOG("-- Create Application");

	this->widgets.app = Gtk::Application::create();
	this->widgets.splash_screen = new Libre::SplashScreen();
	this->widgets.preferences_window = new Libre::PreferencesWindow();

	std::string info_string = _("<big>Welcome to LibreTextus!</big>\n"
			"Here are some search syntax hints:\n"
			"<i>WORD WORD2</i> will give you all verses with <i>WORD</i> and <i>WORD2</i> in it, but not in this order.\n"
			"<i>\"WORD ANOTHER WORD\"</i> this means you want exactly what is quoted\n"
			"To get specific verses or chapters use the standart notation like: <i>GEN 1,1-10</i>\n"
			"<i>WORD@GEN 1</i> will give all <i>WORD</i> in <i>GEN 1</i>\n");

	this->widgets.main_window = new Libre::MainWindow(info_string);

	LOG("-- Connect Signals");

	this->widgets.package_manager.connect_dispatcher_signal(
		this->widgets.splash_screen->get_header(),
		this->widgets.splash_screen->get_info()
	);

	this->connect_app_startup_signal();
	
	this->connect_session_init_success_signal();
	
	return 0;
}

void Framework::init_session() {
	this->widgets.processing.update_thread = Glib::Thread::create([this]() {
		this->widgets.package_manager.init();

		this->widgets.main_window->set_package_manager(&this->widgets.package_manager);
		this->widgets.main_window->set_preferences_window(this->widgets.preferences_window);
		this->widgets.main_window->set_application(this->widgets.app);
		this->widgets.main_window->init();

		this->widgets.processing.start_session.emit();
	});
}
