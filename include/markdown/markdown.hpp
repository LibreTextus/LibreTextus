#ifndef MARKDOWN_HPP
#define MARKDOWN_HPP

#include <iostream>
#include <memory>
#include <string>
#include "tagged_char.hpp"

namespace MD {
	class String {
	private:
		std::string raw_text;
		std::allocator<MD::tagged_char> alloc;
		MD::tagged_char * tagged_chars;
		size_t size_;

		void parse(const std::string & text) {

			this->raw_text = text;

			this->size_ = text.size();
			this->tagged_chars = this->alloc.allocate(this->size_);

			int active_tags = 0;

			for (int c = 0; c < text.size(); c++) {
				if (text[c] == '*' || text[c] == '_') {
					if (text[c + 1] == text[c]) {
						active_tags ^= MD::STYLE::BOLD;
						this->alloc.construct(this->tagged_chars + c, text[c], MD::STYLE::HIDDEN);
						this->alloc.construct(this->tagged_chars + c + 1, text[c + 1], MD::STYLE::HIDDEN);
						c++;
						continue;
					} else {
						active_tags ^= MD::STYLE::ITALIC;
						this->alloc.construct(this->tagged_chars + c, text[c], MD::STYLE::HIDDEN);
						continue;
					}
				} else if (text[c] == '~') {
					active_tags ^= MD::STYLE::STRIKETHROUGH;
					this->alloc.construct(this->tagged_chars + c, text[c], MD::STYLE::HIDDEN);
					continue;
				}

				this->alloc.construct(this->tagged_chars + c, text[c], active_tags);
			}

			active_tags = 0;

			for (int c = 0; c < this->size_; c++) {
				if (tagged_chars[c - 1].c == '\n' || c == 0) {
					if (tagged_chars[c].c == '#') {

						int header_type = MD::STYLE::H1;

						for (int i = 1; tagged_chars[c + i].c == '#' && i < 6; i++) {
							header_type *= 2;
							tagged_chars[c + i].tag = MD::STYLE::HIDDEN;
						}

						active_tags |= header_type;
						tagged_chars[c].tag |= MD::STYLE::HIDDEN;
					}

					if (tagged_chars[c].c == '>') {
						active_tags |= MD::STYLE::BLOCKQUOTES;
						tagged_chars[c].tag |= MD::STYLE::HIDDEN;
					}
				}

				if (tagged_chars[c].c == '\n') {
					active_tags = 0;
				}

				tagged_chars[c].tag |= active_tags;
			}
		}

	public:
		String(const std::string & text) {
			this->parse(text);
		}

		String() {
			this->size_ = 0;
			this->size_ = 0;
		};

		virtual ~String() {
			for (size_t i = 0; i < this->size_; i++) {
				this->alloc.destroy(this->tagged_chars + i);
			}
			this->alloc.deallocate(this->tagged_chars, this->size_);
		}

		void set_text(std::string text) {
			for (size_t i = 0; i < this->size_; i++) {
				this->alloc.destroy(this->tagged_chars + i);
			}

			this->alloc.deallocate(this->tagged_chars, this->size_);

			this->parse(text);
		}

		std::string get_text() {
			std::string s;
			for (int i = 0; i < this->size_; i++) {
				s += this->tagged_chars[i].c;
			}
			return s;
		}

		std::string get_raw_text() {
			return this->raw_text;
		}

		class iterator;

		iterator begin() {
			return iterator(this->tagged_chars);
		}

		iterator end() {
			return iterator(this->tagged_chars + this->size_);
		}

		size_t size() {
			return this->size_;
		}

		MD::tagged_char & operator[](int i) {
			return this->tagged_chars[i];
		}

		struct iterator {
			MD::tagged_char * p_;

			iterator(MD::tagged_char * other) {
				p_ = other;
			}

			iterator() = default;
			virtual ~iterator() = default;

			bool operator==(iterator other) {
				return (p_ == other.p_);
			}

			bool operator!=(iterator other) {
				return !(p_ == other.p_);
			}

			void operator++() {
				p_++;
			}

			void operator++(int) {
				p_++;
			}

			void operator--() {
				p_--;
			}

			void operator--(int) {
				p_--;
			}

			char & operator*() {
				return p_->c;
			}

			MD::tagged_char * operator->() {
				return this->p_;
			}
		};
	};
}

#endif
