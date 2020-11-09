#include "search_engine.hpp"
#include <thread>

bool SearchEngine::search(std::string * text) {
	
	for (int i = 0; i < this->num_threads; ++i) {
		if (this->thread_finished[i] < 1 || this->thread_found[i] > 0) {

			std::cout << 0 << '\n';

			while (this->thread_found[i] == 0 && this->thread_finished[i] == false) { std::this_thread::yield(); }

			std::cout << 1 << '\n';

			bool cont = false;

			while (!(*this->search_mutex)[i].try_lock()) {
				if (this->thread_finished[i] == true && this->thread_found[i] == 0) {
					cont = true;
					break;
				}
			}

			if (cont)
				continue;

			std::cout << 2 << '\n';

			std::string fpos = this->thread_search_results[i].front();
			this->thread_search_results[i].erase(this->thread_search_results[i].begin());

			std::cout << 3 << '\n';

			*text = (*this->file)[fpos];

			if (!this->search_argument.empty()) {
				this->mark_result(fpos, text);
			}

			this->last_search_results.push_back(fpos);

			this->thread_found[i] -= 1;

			std::cout << 4 << '\n';

			(*this->search_mutex)[i].unlock();

			std::cout << 5 << '\n';

			return true;
		}
	}

	this->join_search_threads();

	return false;
}
