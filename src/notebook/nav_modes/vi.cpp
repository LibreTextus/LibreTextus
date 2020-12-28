#include "vi.hpp"
#include "glibmm/refptr.h"
#include "gtkmm/clipboard.h"

void NavMode::VI::make_ready(Glib::RefPtr<Gtk::TextBuffer> buffer) {
	if (!buffer->get_text().empty()) {
	Gtk::TextBuffer::iterator curs_pos = buffer->begin();

	Gtk::TextBuffer::iterator sel_end = curs_pos;
	sel_end.forward_char();
	buffer->select_range(curs_pos, sel_end);

	this->active_mode = Modes::NORMAL;
	} else {
		this->active_mode = Modes::INSERT;
	}

	this->last_pressed = 0;
	this->close_notebook = false;
}

bool NavMode::VI::process_navigation(GdkEventKey * event, Glib::RefPtr<Gtk::TextBuffer> buffer) {
	switch (active_mode) {
		case Modes::NORMAL: return this->process_normal(event, buffer);
		case Modes::INSERT: return this->process_insert(event, buffer);
		case Modes::VISUAL: return this->process_visual(event, buffer);
	}

	return false;
}

bool NavMode::VI::process_insert(GdkEventKey * event, Glib::RefPtr<Gtk::TextBuffer> buffer) {
	if (event->keyval == GDK_KEY_Escape) {
		this->active_mode = Modes::NORMAL;
		Gtk::TextBuffer::iterator curs_pos = buffer->get_insert()->get_iter();
		if (curs_pos.ends_line())
			curs_pos.backward_char();
		Gtk::TextBuffer::iterator sel_end = curs_pos;
		sel_end.forward_char();
		buffer->select_range(curs_pos, sel_end);
		return true;
	}

	return false;
}

bool NavMode::VI::process_normal(GdkEventKey * event, Glib::RefPtr<Gtk::TextBuffer> buffer) {
	Gtk::TextBuffer::iterator curs_pos = buffer->get_insert()->get_iter();

	if (event->keyval == GDK_KEY_h) {
		if (!curs_pos.starts_line()) {
			curs_pos.backward_char();
		}
		this->last_pressed = 0;

	} else if (event->keyval == GDK_KEY_j) {
		if (curs_pos.get_line() < buffer->get_line_count() - 1) {
			int offsetx = curs_pos.get_line_offset();
			curs_pos.forward_line();
			if (curs_pos.get_chars_in_line() - 1 < offsetx)
				offsetx = curs_pos.get_chars_in_line() - 1;
			curs_pos.forward_chars(offsetx);
		}
		this->last_pressed = 0;

	} else if (event->keyval == GDK_KEY_k) {
		int offsetx = curs_pos.get_line_offset();
		curs_pos.backward_line();
		if (curs_pos.get_chars_in_line() - 1 < offsetx)
			offsetx = curs_pos.get_chars_in_line() - 1;
		curs_pos.forward_chars(offsetx);
		this->last_pressed = 0;

	} else if (event->keyval == GDK_KEY_l) {
		curs_pos.forward_char();
		if (curs_pos.ends_line())
			curs_pos.backward_char();
		this->last_pressed = 0;

	} else if (event->keyval == GDK_KEY_i) {
		this->active_mode = Modes::INSERT;
		buffer->select_range(curs_pos, curs_pos);
		this->last_pressed = 0;

	} else if (event->keyval == GDK_KEY_a) {
		this->active_mode = Modes::INSERT;
		curs_pos.forward_char();
		buffer->select_range(curs_pos, curs_pos);
		this->last_pressed = 0;

	} else if (event->keyval == GDK_KEY_A) {
		this->active_mode = Modes::INSERT;
		if (curs_pos.get_line() < buffer->get_line_count() - 1) {
			curs_pos.set_line_offset(curs_pos.get_chars_in_line() - 1);
		} else {
			curs_pos.set_line_offset(curs_pos.get_chars_in_line());
		}
		buffer->select_range(curs_pos, curs_pos);
		this->last_pressed = 0;

	} else if (event->keyval == GDK_KEY_I) {
		this->active_mode = Modes::INSERT;
		curs_pos.set_line_offset(0);
		buffer->select_range(curs_pos, curs_pos);
		this->last_pressed = 0;
	} else if (event->keyval == GDK_KEY_G) {
		curs_pos = buffer->end();
		curs_pos.set_line_offset(0);
		this->last_pressed = 0;

	} else if (event->keyval == GDK_KEY_o) {
		curs_pos.forward_to_line_end();
		buffer->insert(curs_pos, "\n");
		curs_pos = buffer->get_insert()->get_iter();
		curs_pos.forward_line();
		buffer->select_range(curs_pos, curs_pos);
		this->active_mode = Modes::INSERT;
		this->last_pressed = 0;

	} else if (event->keyval == GDK_KEY_g) {
		if (this->last_pressed == GDK_KEY_g) {
			curs_pos = buffer->begin();
			this->last_pressed = 0;
		} else {
			this->last_pressed = event->keyval;
		}

	} else if (event->keyval == GDK_KEY_dollar) {
		if (curs_pos.get_line() < buffer->get_line_count() - 1) {
			curs_pos.set_line_offset(curs_pos.get_chars_in_line() - 2);
		} else {
			curs_pos.set_line_offset(curs_pos.get_chars_in_line() - 1);
		}

	} else if (event->keyval == GDK_KEY_x) {
		buffer->erase_selection();
		curs_pos = buffer->get_insert()->get_iter();
		if (curs_pos.ends_line())
			curs_pos.backward_char();
	} else if (event->keyval == GDK_KEY_d) {
		if (this->last_pressed == GDK_KEY_d) {
			curs_pos.set_line_offset(0);
			Gtk::TextBuffer::iterator end = curs_pos;
			end.forward_to_line_end();
			curs_pos.backward_char();
			buffer->erase(curs_pos, end);
			curs_pos = buffer->get_insert()->get_iter();
			curs_pos.backward_char();
			this->last_pressed = 0;
		} else {
			this->last_pressed = GDK_KEY_d;
		}
	} else if (event->keyval == GDK_KEY_v) {
		this->active_mode = Modes::VISUAL;
		this->selection_begin = curs_pos;

	} else if (event->keyval == GDK_KEY_p) {
		Glib::RefPtr<Gtk::Clipboard> clipboard = Gtk::Clipboard::get();
		buffer->insert_at_cursor(clipboard->wait_for_text());
		curs_pos = buffer->get_insert()->get_iter();

	} else if (event->keyval == GDK_KEY_Z) {
		if (this->last_pressed == GDK_KEY_Z) {
			this->close_notebook = true;
			this->last_pressed = 0;
		} else {
			this->last_pressed = event->keyval;
		}
	}

	if (this->active_mode == Modes::NORMAL) {
		Gtk::TextBuffer::iterator sel_end = curs_pos;
		sel_end.forward_char();
		buffer->select_range(curs_pos, sel_end);
	}

	return true;
}

bool NavMode::VI::process_visual(GdkEventKey * event, Glib::RefPtr<Gtk::TextBuffer> buffer) {
	Gtk::TextBuffer::iterator curs_pos;
	Gtk::TextBuffer::iterator p1;
	Gtk::TextBuffer::iterator p2;

	buffer->get_selection_bounds(p1, p2);

	if (this->selection_begin == p1)
		curs_pos = p2;
	else 
		curs_pos = p1;

	if (event->keyval == GDK_KEY_h) {
		if (!curs_pos.starts_line()) {
			curs_pos.backward_char();
		}
		this->last_pressed = 0;

	} else if (event->keyval == GDK_KEY_j) {
		if (curs_pos.get_line() < buffer->get_line_count() - 1) {
			int offsetx = curs_pos.get_line_offset();
			curs_pos.forward_line();
			if (curs_pos.get_chars_in_line() - 1 < offsetx)
				offsetx = curs_pos.get_chars_in_line() - 1;
			curs_pos.forward_chars(offsetx);
		}
		this->last_pressed = 0;

	} else if (event->keyval == GDK_KEY_k) {
		int offsetx = curs_pos.get_line_offset();
		curs_pos.backward_line();
		if (curs_pos.get_chars_in_line() - 1 < offsetx)
			offsetx = curs_pos.get_chars_in_line() - 1;
		curs_pos.forward_chars(offsetx);
		this->last_pressed = 0;

	} else if (event->keyval == GDK_KEY_l) {
		if (!curs_pos.ends_line())
			curs_pos.forward_char();
		this->last_pressed = 0;
	} else if (event->keyval == GDK_KEY_x) {
		buffer->erase_selection();
		this->active_mode = Modes::NORMAL;
		curs_pos = buffer->get_insert()->get_iter();

	} else if (event->keyval == GDK_KEY_Escape) {
		this->active_mode = Modes::NORMAL;
		
	} else if (event->keyval == GDK_KEY_y) {
		this->active_mode = Modes::NORMAL;
		Glib::ustring text;
		if (this->selection_begin == p1)
			text = buffer->get_text(selection_begin, curs_pos);
		else
			text = buffer->get_text(curs_pos, selection_begin);

		Glib::RefPtr<Gtk::Clipboard> clipboard = Gtk::Clipboard::get();
		clipboard->set_text(text);
	} else if (event->keyval == GDK_KEY_dollar) {
			curs_pos.set_line_offset(curs_pos.get_chars_in_line() - 1);
	}

	if (this->active_mode == Modes::VISUAL)
		if (this->selection_begin == p1)
			buffer->select_range(selection_begin, curs_pos);
		else
			buffer->select_range(curs_pos, selection_begin);
	else if (this->active_mode == Modes::NORMAL) {
		Gtk::TextBuffer::iterator sel_end = curs_pos;
		if (curs_pos.ends_line())
			curs_pos.backward_char();
		else
			sel_end.forward_char();
		buffer->select_range(curs_pos, sel_end);
	}
	return true;
}

std::string NavMode::VI::get_status() {
	return this->status_string[this->active_mode];
}

bool NavMode::VI::close() {
	return this->close_notebook;
}
