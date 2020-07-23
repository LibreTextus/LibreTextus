#include "../notebook.hpp"
#include <rapidxml/rapidxml.hpp>

Libre::NoteBook::NoteBook() {

	this->set_text_view_properties();
	this->set_title_properties();
	this->set_button_properties();
	this->set_header_properties();

	this->content_buffer->signal_end_user_action().connect(
			sigc::mem_fun(this, &Libre::NoteBook::on_content_change));

	this->create_markdown_tags();
	this->active_position = nullptr;
	
	this->pack_children();
}

Libre::NoteBook::~NoteBook() {
	this->save_note();
}
