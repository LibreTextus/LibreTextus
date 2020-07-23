#include "../framework.hpp"

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
	
	Libre::SplashScreen::create(&this->widgets.splash_screen, &this->signal_handler);
	
	this->load_css_file();
	this->set_font_size_from_settings();
	this->apply_css_context_to_screen();

	LOG("-- Connect Signals");

	this->widgets.package_manager.connect_dispatcher_signal(
		this->widgets.splash_screen.header_label,
		this->widgets.splash_screen.info_label
	);

	this->connect_app_startup_signal();
	
	this->connect_session_init_success_signal();

	this->connect_processing_signals();
	
	return 0;
}

void Framework::init_session() {
	this->widgets.processing.update_thread = Glib::Thread::create([this]() {
		this->widgets.package_manager.init();
		this->signal_handler.init(&this->widgets);
		this->widgets.processing.start_session.emit();
	});
}
