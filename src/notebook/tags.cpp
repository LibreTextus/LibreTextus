#include "../notebook.hpp"

void Libre::NoteBook::create_markdown_tags() {
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
}

