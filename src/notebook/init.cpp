#include "notebook.hpp"
#include "notebook/nav_modes/mode.hpp"
#include <rapidxml/rapidxml.hpp>

Libre::NoteBook::NoteBook() {
	this->set_text_view_properties();
	this->set_title_properties();
	this->set_button_properties();
	this->set_header_properties();

	this->content_buffer->signal_end_user_action().connect(
			sigc::mem_fun(this, &Libre::NoteBook::on_content_change));

	this->text_view.signal_key_press_event().connect(
			sigc::mem_fun(this, &Libre::NoteBook::nav_modes), false);

	this->create_markdown_tags();
	this->active_position = nullptr;
	
	this->pack_children();
	
	modes["Vim"] = new NavMode::VI;
	modes["Normal"] = new NavMode::NavMode;

	this->refresh_mode();
}

Libre::NoteBook::~NoteBook() {
	this->save_note();
	delete modes["Vim"];
	delete modes["Normal"];
}
