#include "../signal_handler.hpp"

void SignalHandler::source_changed(Gtk::ComboBoxText * b) {

	LOG("--> \"source_changed\" emmited");

	this->disable_widgets();
	this->widgets->main.text_view->grab_focus();

	this->set_replace_id(b);

	this->widgets->processing.process_thread = Glib::Thread::create(sigc::mem_fun(*this, &SignalHandler::do_replacement), true);
	LOG("--> \"do_replacement\" emmited");
}

void SignalHandler::set_replace_id(Gtk::ComboBoxText * b) {
	this->widgets->processing.replace_id = 0;

	for (;this->widgets->processing.replace_id < this->widgets->main.combo_boxes.size(); this->widgets->processing.replace_id++) {
		if (b == this->widgets->main.combo_boxes[this->widgets->processing.replace_id]) {
			break;
		}
	}
}
