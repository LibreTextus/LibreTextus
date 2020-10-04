#include "search_engine.hpp"
#include "source_handler/source_handler.hpp"
#include <mutex>


void SearchEngine::start_search_threads() {
	this->thread_search_results.clear();
	this->thread_progress.clear();
	this->thread_finished.clear();
	this->thread_found.clear();

	std::vector<std::vector<std::array<Libre::BookMap::iterator, 2>>> parts(this->num_threads);

	if (this->positions.size() < this->num_threads) {
		for (std::array<Libre::BookMap::iterator, 2> & i : this->positions) {
			size_t size = std::distance(i[0], i[1]) / this->num_threads;
			Libre::BookMap::iterator b = i[0];
			Libre::BookMap::iterator e = i[0];
			
			for (int j = 0; j < this->num_threads - 1; ++j) {
				b = e;
				for (int k = 0; k < size; ++k) { ++e; }

				parts[j].push_back({b, e});
			}

			parts.back().push_back({e, i[1]});
		}
	} else {
		size_t part_size = this->positions.size() / this->num_threads;
		for (int i = 0; i < this->num_threads - 1; ++i) {
			for (int j = i * part_size; j < (i + 1) * part_size; ++j) {
				parts[i].push_back(this->positions[j]);
			}
		}

		for (int i = (this->num_threads - 1) * part_size; i < this->positions.size(); ++i) {
			parts.back().push_back(this->positions[i]);
		}
	}

	if (this->search_mutex != nullptr) {
		delete this->search_mutex;
	}

	this->search_mutex = new std::vector<std::mutex>(this->num_threads);

	for (int i = 0; i < this->num_threads; ++i) {
		this->thread_search_results.push_back({});
		this->thread_finished.push_back(false);
		this->thread_progress.push_back(0.0f);
		this->thread_found.push_back(0);
		this->search_thread.push_back(new std::thread(&SearchEngine::thread_search, this, parts[i], i));
	}

}

void SearchEngine::thread_search(std::vector<std::array<Libre::BookMap::iterator, 2>> pos, int i) {
	Libre::BookMap::iterator a_v = pos.front()[0];
	int a_v_i = 0;

	unsigned int num_of_verses = 0;
	unsigned int progress = 0;

	for (std::array<Libre::BookMap::iterator, 2> & i : pos) {
		num_of_verses += std::distance(i.front(), i.back());
	}

	while (a_v != pos.back()[1]) {

		boost::regex e("", boost::regex::icase);
		bool found = true;

		for(int j = 0; j < this->search_argument_vector.size(); j++) {
			if (this->search_argument_vector[j].front() == '[' && this->search_argument_vector[j].back() == ']') {
				Libre::StrongMap * s_m = this->source_handler.get_strongs(this->file_path);
				bool found_str = false;

				for (tsl::ordered_map<std::string, std::string>::iterator it = (*s_m)[a_v.key()].begin(); it != (*s_m)[a_v.key()].end(); it++) {
					if(this->search_argument_vector[j].substr(1, this->search_argument_vector[j].size() - 2) == it->second) {
						found_str = true;
						break;
					}
				}

				found &= found_str;

			} else {
				e = boost::regex(this->search_argument_vector[j], boost::regex::icase);
				found &= boost::regex_search(a_v.value(), e);
			}
		}

		bool only_want_range = this->search_argument == "";

		if (found || only_want_range) {

			std::lock_guard<std::mutex> lock((*this->search_mutex)[i]);

			this->thread_search_results[i].push_back(a_v.key());

			this->thread_found[i] += 1;

		}

		progress++;
		a_v++;

		this->thread_progress[i] = progress / num_of_verses;

		if (a_v != pos.back()[1]) {
			if (a_v == pos[a_v_i][1]) {
				a_v_i++;
				a_v = pos[a_v_i][0];
			}
		}
	}

	this->thread_finished[i] = true;
}

void SearchEngine::join_search_threads() {
	for (std::thread * t : this->search_thread) {
		if (t->joinable()) {
			t->join();
			delete t;
		}
	}

	this->search_thread.clear();
}
