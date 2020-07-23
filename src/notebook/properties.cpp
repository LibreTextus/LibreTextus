#include "../notebook.hpp"

void Libre::NoteBook::set_text_view_properties() {
	this->set_name("text_view");
	this->text_view.set_border_width(10);
	this->content_buffer = Gtk::TextBuffer::create();
	this->text_view.set_buffer(this->content_buffer);
	this->text_view.set_name("text_view");
	this->text_view.set_wrap_mode(Gtk::WRAP_WORD);
	this->text_view.set_sensitive(false);
}

void Libre::NoteBook::set_title_properties() {
	this->title.set_text("");
	this->title.set_name("note_header_title");
}

void Libre::NoteBook::set_button_properties() {
	this->close_button.set_name("close_button");
}

void Libre::NoteBook::set_header_properties() {
	this->header.set_name("note_header");
	this->header.set_border_width(0);
}

