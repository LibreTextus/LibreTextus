#include "notebook.hpp"

void Libre::NoteBook::open_note(const std::string & position) {
	this->text_view.set_sensitive(true);
	this->save_note();

	this->set_active_position_and_get_content(position);
	
	this->title.set_text(std::string(_("Note")) + " - " + position);

	this->on_content_change();

	this->modes[this->active_mode]->make_ready(this->text_view.get_buffer());
	this->status_label.set_text(this->modes[this->active_mode]->get_status());
}

void Libre::NoteBook::set_active_position_and_get_content(const std::string & position) {
	if (this->note_exists(position)) {
		this->get_content_from_existing_note(position);
	} else {
		this->create_new_note_at_position(position);
	}
}

void Libre::NoteBook::get_content_from_existing_note(const std::string & position) {
	rapidxml::xml_node<> * note;
	note = this->notes_file.first_node("notebook")->first_node();
	for (; note && note->first_attribute("name")->value() != position; note = note->next_sibling()) {}
	this->content_buffer->set_text(note->value());
	this->active_position = note;
}

void Libre::NoteBook::create_new_note_at_position(const std::string & position) {
	rapidxml::xml_node<> * note;
	note = this->notes_file.allocate_node(rapidxml::node_element, "note");

	char * name = this->notes_file.allocate_string(position.c_str());

	rapidxml::xml_attribute<> * attr = this->notes_file.allocate_attribute("name", name);
	note->append_attribute(attr);
	this->notes_file.first_node("notebook")->append_node(note);
	this->content_buffer->set_text("");
	this->active_position = note;
}

bool Libre::NoteBook::note_exists(const std::string & pos) {
	rapidxml::xml_node<> * notebook = this->notes_file.first_node("notebook");

	for (rapidxml::xml_node<> * note = notebook->first_node("note"); note; note = note->next_sibling()) {
		if (note->first_attribute("name")->value() == pos) {
			return true;
		}
	}

	return false;
}

void Libre::NoteBook::save_note() {
	this->remove_empty_notes();
	this->m_signal_refresh.emit();
	this->write_to_file();
}

void Libre::NoteBook::remove_empty_notes() {
	std::vector<rapidxml::xml_node<> *> v;
	
	rapidxml::xml_node<> * n = this->notes_file.first_node("notebook")->first_node();
	for (; n; n = n->next_sibling()) {
		if (std::string(n->value()).empty()) {
			v.push_back(n);
		}
	}

	for (int i = 0; i < v.size(); i++) {
		this->notes_file.first_node("notebook")->remove_node(v[i]);
	}
}

void Libre::NoteBook::write_to_file() {
	std::ofstream fout(this->path);
	if (fout.is_open()) {
		fout << this->notes_file;
		fout.close();
	}
}

void Libre::NoteBook::set_file(const std::string & p) {
	if (std::experimental::filesystem::exists(p)) {
		this->read_from_file(p);
	} else {
		this->create_new_note_book_node();
	}

	this->path = p;

	if (this->active_position != nullptr) {
		this->open_note(this->active_position->first_attribute("name")->value());
	} else {
		this->save_note();
	}
}

void Libre::NoteBook::read_from_file(const std::string & p) {
	rapidxml::file<> file(p.c_str());
	char * content = this->notes_file.allocate_string(file.data());
	this->notes_file.parse<rapidxml::parse_no_data_nodes>(content);
}

void Libre::NoteBook::create_new_note_book_node() {
	rapidxml::xml_node<> * notebook = this->notes_file.allocate_node(rapidxml::node_element, "notebook");
	this->notes_file.append_node(notebook);
}

void Libre::NoteBook::export_note(std::string & position, std::string & path, std::string & source) {
	Libre::Exporter exporter(&this->notes_file, path, source, position);
	exporter.export_note();
}
