#include "project_euler_environment.hpp"

std::vector<int>* compute_primes(int size)
{
	std::vector<int> *v = new std::vector<int>[size + 1];
	bool *is_prime = new bool[size + 1];

	fori(size + 1)
		is_prime[i] = true;

	fori2(2, size + 1) {
		if (is_prime[i]) {
			v->push_back(i);
			
			for (int j = i * 2; j < size + 1; j += i) 
				is_prime[j] = false;
		}
	}

	delete[] is_prime;
	return v;
}

std::unordered_set<int>* compute_prime_factors(int size)
{
	std::unordered_set<int> *set = new std::unordered_set<int>[size + 1];
	bool *is_prime = new bool[size + 1];

	fori(size + 1)
		is_prime[i] = true;

	fori2(2, size + 1) 
	{
		if (is_prime[i]) 
		{
			set[i].insert(i);

			for (int j = i * 2; j < size + 1; j += i) {
				set[j].insert(i);
				is_prime[j] = false;
			}
		}
	}

	delete[] is_prime;
	return set;
}
