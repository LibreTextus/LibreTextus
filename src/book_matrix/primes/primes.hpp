#ifndef LIBRE_PRIMES_HPP
#define LIBRE_PRIMES_HPP

#include <math.h>
#include <vector>
#include <iostream>

namespace Libre {
	class Primes {
		private:
			static std::vector<unsigned long> primes;
		public:
			Primes() = default;
			~Primes() = default;

			unsigned long get_prime(size_t i);
			void generate(size_t n);
	};
}

#endif
