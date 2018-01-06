/*
	Project Euler Problem 73 - Counting Fractions In A Range
*/

#include "project_euler_environment.hpp"
#include "prime_utils.hpp"

#define MAX_VALUE 12000 

std::unordered_set<int> *prime_factors;

bool has_no_common_factor(int i, int j)
{
	forit(prime_factors[i])
	{
		if (prime_factors[j].find(*it) != prime_factors[j].end())
			return false;
	}

	return true;
}

ll run()
{
	ll count = 0;

	fori2(2, MAX_VALUE) // n
	{
		int max_d = i * 3;
		int min_d = i * 2;

		if (max_d > MAX_VALUE)
			max_d = MAX_VALUE + 1;

		forj2(min_d + 1, max_d)
			if (has_no_common_factor(i, j))
				count++;
	}

	return count;
}

int main()
{
	prime_factors = compute_prime_factors(MAX_VALUE);

	cout << "Solution: " << run() << endl;

	delete[] prime_factors;
	return 0;
}
