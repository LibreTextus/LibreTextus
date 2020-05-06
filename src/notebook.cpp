#include "notebook.hpp"

Libre::NoteBook::NoteBook(Gtk::HBox * h) {
	this->set_name("text_view");
	this->text_view.set_border_width(10);
	this->content_buffer = Gtk::TextBuffer::create();
	this->text_view.set_buffer(this->content_buffer);
	this->text_view.set_name("text_view");

	this->content_buffer->signal_end_user_action().connect(sigc::mem_fun(this, &Libre::NoteBook::on_content_change));

	this->add(this->text_view);

	this->header = h;

	this->active_position = "Startup Note";
	this->title.set_text(this->active_position);

	this->header->pack_start(this->title, Gtk::PACK_SHRINK, 0);
}


Libre::NoteBook::~NoteBook() {
	this->safe_note();
}

void Libre::NoteBook::safe_note() {
	YAML::Emitter emitter;
	emitter << this->notes_file;

	std::ofstream fout(this->path);
	if (fout.is_open()) {
		fout << emitter.c_str();
		fout.close();
	}
}

void Libre::NoteBook::open_note(const std::string & position) {
	this->safe_note();
	
	if (this->notes_file[position]) {
		this->content_buffer->set_text(this->notes_file[position].as<std::string>());
	} else {
		this->notes_file[position] = "";
		this->content_buffer->set_text("");
	}

	this->active_position = position;
	this->title.set_text("Note - " + position);
}

void Libre::NoteBook::on_content_change() {
	this->notes_file[this->active_position] = std::string(this->content_buffer->get_text());
	// ------------------------------------------
	// TODO PARSE MARKDOWN SYNTAX
	// ------------------------------------------
}
