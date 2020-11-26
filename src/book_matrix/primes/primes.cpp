#include "primes.hpp"

std::vector<unsigned long> Libre::Primes::primes{};

unsigned long Libre::Primes::get_prime(size_t i) {
	return this->primes[i];
}

void Libre::Primes::generate(size_t n) {
	if (n <= this->primes.size())
		return;

	this->primes.clear();

	size_t s = n * log(n) * 2;

	bool * pt = new bool[s]{false};

	std::cout << "GEN PRIMES\n";

	for (unsigned long i = 2; i < s;) {
		primes.push_back(i);

		for (unsigned long j = i * 2; j < s; j += i)
			pt[j] = true;

		for (++i; pt[i]; ++i) {}
	}

	std::cout << "SIZE: " << primes.size() << '\n';
	std::cout << "DEMANDED: " << n << '\n';

	delete [] pt;
}
