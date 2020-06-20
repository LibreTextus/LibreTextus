#include "notebook.hpp"
#include <rapidxml/rapidxml.hpp>

// LIBRE::NOTEBOOX::NOTEBOOX ---------------------------------------------------
// CUNSTRUCTOR FOR THE NOTEBOOK WIDGET
// -----------------------------------------------------------------------------

Libre::NoteBook::NoteBook() {

	// ------------------------------------------
	// SET TEXTVIEW PROPERTIES
	// ------------------------------------------

	this->set_name("text_view");
	this->text_view.set_border_width(10);
	this->content_buffer = Gtk::TextBuffer::create();
	this->text_view.set_buffer(this->content_buffer);
	this->text_view.set_name("text_view");
	this->text_view.set_wrap_mode(Gtk::WRAP_WORD);
	this->text_view.set_sensitive(false);

	this->scrolled_window.add(this->text_view);

	// ------------------------------------------
	// CONNECT BUFFER SIGNALS
	// ------------------------------------------
	this->content_buffer->signal_end_user_action().connect(sigc::mem_fun(this, &Libre::NoteBook::on_content_change));

	// ------------------------------------------
	// CREATE TAGS
	// ------------------------------------------

	this->tag_bold = this->content_buffer->create_tag("bold");
	this->tag_bold->property_weight() = PANGO_WEIGHT_BOLD;

	this->tag_italic = this->content_buffer->create_tag("italic");
	this->tag_italic->property_style() = Pango::STYLE_ITALIC;

	this->tag_strikethrough = this->content_buffer->create_tag("strikethrough");
	this->tag_strikethrough->property_strikethrough() = true;

	this->tag_hidden = this->content_buffer->create_tag("hidden");
	this->tag_hidden->property_weight() = PANGO_WEIGHT_ULTRALIGHT;

	this->tag_h1 = this->content_buffer->create_tag("h1");
	this->tag_h1->property_scale() = 2;

	this->tag_h2 = this->content_buffer->create_tag("h2");
	this->tag_h2->property_scale() = 1.8;

	this->tag_h3 = this->content_buffer->create_tag("h3");
	this->tag_h3->property_scale() = 1.6;

	this->tag_h4 = this->content_buffer->create_tag("h4");
	this->tag_h4->property_scale() = 1.4;

	this->tag_h5 = this->content_buffer->create_tag("h5");
	this->tag_h5->property_scale() = 1.2;

	this->tag_h6 = this->content_buffer->create_tag("h6");
	this->tag_h6->property_scale() = 1.05;

	this->tag_blockquotes = this->content_buffer->create_tag("blockquotes");
	this->tag_blockquotes->property_indent() = 5;

	// ------------------------------------------
	// CREATE HEADER TITLE
	// ------------------------------------------
	this->active_position = nullptr;

	this->title.set_text("");
	this->title.set_name("note_header_title");

	// ------------------------------------------
	// SET PROPERTIES FOR THE CLOSE_BUTTON
	// ------------------------------------------

	this->close_button.set_name("close_button");

	// ------------------------------------------
	// SET PROPERTIES FOR THE HEADER
	// ------------------------------------------
	this->header.set_name("note_header");
	this->header.set_border_width(0);

	// ------------------------------------------
	// PACK WIDGETS TO HEADER
	// ------------------------------------------
	this->header.pack_end(this->close_button, Gtk::PACK_SHRINK, 0);
	this->header.pack_start(this->title, Gtk::PACK_SHRINK, 0);

	// ------------------------------------------
	// PACK HEADER AND SCROLLED_WINDOW TO MAIN
	// ------------------------------------------
	this->pack_start(this->header, Gtk::PACK_SHRINK, 0);
	this->pack_start(this->scrolled_window, Gtk::PACK_EXPAND_WIDGET, 0);

}

// LIBRE::NOTEBOOK:~NOTEBOOK ---------------------------------------------------
// THIS IS THE DESTRUCTOR OF THE NOTBOOK WIDGET IT SAVES THE OPEN NOTE
// -----------------------------------------------------------------------------

Libre::NoteBook::~NoteBook() {
	this->save_note();
}

// LIBRE::NOTEBOOK::SAVE_NOTE --------------------------------------------------
// THIS FUNCTION WRITES THE NOTES TO THE YAML FILE
// -----------------------------------------------------------------------------

void Libre::NoteBook::save_note() {

	std::vector<rapidxml::xml_node<> *> v;
	
	for (rapidxml::xml_node<> * i = this->notes_file.first_node("notebook")->first_node(); i; i = i->next_sibling()) {
		if (std::string(i->value()).empty()) {
			v.push_back(i);
		}
	}

	for (int i = 0; i < v.size(); i++) {
		this->notes_file.first_node("notebook")->remove_node(v[i]);
	}
	
	this->m_signal_refresh.emit(0);

	std::ofstream fout(this->path);
	if (fout.is_open()) {
		fout << this->notes_file;
		fout.close();
	}
}

// LIBRE::NOTEBOOK::OPEN_NOTE --------------------------------------------------
// THIS FUNCTION OPENS THE ASKED NOTE FROM THE YAML NOTE
// -----------------------------------------------------------------------------

void Libre::NoteBook::open_note(const std::string & position) {
	this->text_view.set_sensitive(true);

	this->save_note();

	rapidxml::xml_node<> * note;

	if (this->note_exists(position)) {

		note = this->notes_file.first_node("notebook")->first_node();

		for (; note && note->first_attribute("name")->value() != position; note = note->next_sibling()) {}

		this->content_buffer->set_text(note->value());
	} else {
		note = this->notes_file.allocate_node(rapidxml::node_element, "note");
		char * name = this->notes_file.allocate_string(position.c_str());
		rapidxml::xml_attribute<> * attr = this->notes_file.allocate_attribute("name", name);
		note->append_attribute(attr);
		this->notes_file.first_node("notebook")->append_node(note);
		this->content_buffer->set_text("");
	}

	this->active_position = note;
	this->title.set_text(std::string(_("Note")) + " - " + position);

	this->on_content_change();
}

// LIBRE::NOTEBOOK::ON_CONTENT_CHANGE ------------------------------------------
// THIS FUNCTION IS CALLED WHEN THE USER CHANGES THE CONTENT OF THE BUFFER
// -----------------------------------------------------------------------------

void Libre::NoteBook::on_content_change() {
	char * content = this->notes_file.allocate_string(this->content_buffer->get_text().c_str());
	this->active_position->value(content);

	this->markdown_text.set_text(std::string(this->content_buffer->get_text()));

	this->content_buffer->remove_all_tags(this->content_buffer->begin(), this->content_buffer->end());

	Gtk::TextBuffer::iterator p_b = this->content_buffer->begin();
	Gtk::TextBuffer::iterator p_e = ++this->content_buffer->begin();

	for (int i = 0; i < this->markdown_text.size(); i++) {

		if (this->markdown_text[i].has_tag(MD::STYLE::ITALIC)) {
			this->content_buffer->apply_tag(this->tag_italic, p_b, p_e);
		}

		if (this->markdown_text[i].has_tag(MD::STYLE::BOLD)) {
			this->content_buffer->apply_tag(this->tag_bold, p_b, p_e);
		}

		if (this->markdown_text[i].has_tag(MD::STYLE::STRIKETHROUGH)) {
			this->content_buffer->apply_tag(this->tag_strikethrough, p_b, p_e);
		}

		if (this->markdown_text[i].has_tag(MD::STYLE::HIDDEN)) {
			this->content_buffer->apply_tag(this->tag_hidden, p_b, p_e);
		}

		if (this->markdown_text[i].has_tag(MD::STYLE::H1)) {
			this->content_buffer->apply_tag(this->tag_h1, p_b, p_e);
		}

		if (this->markdown_text[i].has_tag(MD::STYLE::H2)) {
			this->content_buffer->apply_tag(this->tag_h2, p_b, p_e);
		}

		if (this->markdown_text[i].has_tag(MD::STYLE::H3)) {
			this->content_buffer->apply_tag(this->tag_h3, p_b, p_e);
		}

		if (this->markdown_text[i].has_tag(MD::STYLE::H4)) {
			this->content_buffer->apply_tag(this->tag_h4, p_b, p_e);
		}

		if (this->markdown_text[i].has_tag(MD::STYLE::H5)) {
			this->content_buffer->apply_tag(this->tag_h5, p_b, p_e);
		}

		if (this->markdown_text[i].has_tag(MD::STYLE::H6)) {
			this->content_buffer->apply_tag(this->tag_h6, p_b, p_e);
		}

		if (this->markdown_text[i].has_tag(MD::STYLE::BLOCKQUOTES)) {
			this->content_buffer->apply_tag(this->tag_blockquotes, p_b, p_e);
		}

		p_b++;
		p_e++;
	}
}
