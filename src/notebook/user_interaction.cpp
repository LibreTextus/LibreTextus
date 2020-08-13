#include "notebook.hpp"

void Libre::NoteBook::on_content_change() {
	this->write_changes_to_node();

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

void Libre::NoteBook::write_changes_to_node() {
	char * content = this->notes_file.allocate_string(this->content_buffer->get_text().c_str());
	this->active_position->value(content);
}
