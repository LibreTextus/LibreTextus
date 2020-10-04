#include "search_engine.hpp"

bool SearchEngine::search(std::string * text) {
	
	for (int i = 0; i < this->num_threads; ++i) {
		if (this->thread_finished[i] < 1 || this->thread_found[i] > 0) {

			while (this->thread_found[i] == 0 && this->thread_finished[i] < 1) { std::this_thread::yield(); }

			if (this->thread_finished[i] == 1 && this->thread_found[i] == 0) {
				continue;
			}
			
			std::lock_guard<std::mutex> lock((*this->search_mutex)[i]);


			std::string fpos = this->thread_search_results[i].front();
			this->thread_search_results[i].erase(this->thread_search_results[i].begin());


			*text = (*this->file)[fpos];

			if (!this->search_argument.empty()) {
				this->mark_result(fpos, text);
			}

			this->last_search_results.push_back(fpos);

			this->thread_found[i] -= 1;

			return true;
		}
	}

	this->join_search_threads();

	return false;
}
