/*
	Project Euler Problem 77 - Prime Summations
*/

#include "project_euler_environment.hpp"
#include "prime_utils.hpp"

#define MAX_SIZE 1000000

std::vector<int>* primes;
int prime_additions[MAX_SIZE];

ll run()
{
	prime_additions[0] = 1;

	fori2(1, MAX_SIZE)
		prime_additions[i] = 0;

	int max = MAX_SIZE;
	forit((*primes)) {
		fori2(*it, max) {
			prime_additions[i] += prime_additions[i - *it];
			
			if (prime_additions[i] > 5000)
				max = i;
		}
	}
	
	fori(MAX_SIZE)
		if (prime_additions[i] > 5000)
			return i;

	return -1;
}

int main()
{
	primes = compute_primes(MAX_SIZE);

	cout << "Solution: " << run() << endl;

	delete primes;
	return 0;
}
