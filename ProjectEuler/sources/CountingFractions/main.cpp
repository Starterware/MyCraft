/*
	Project Euler Problem 72 - Counting Fractions
*/

#include "project_euler_environment.hpp"
#include "prime_utils.hpp"

#define MAX_VALUE 1000000 

std::unordered_set<int> *prime_factors;
#define ITERATOR std::unordered_set<int>::iterator

ll number_of_occurences(ITERATOR factors_begin, ITERATOR factors_end, int selected_factors_count, int max_to_select, int range, int value)
{
	ll count = 0;

	if (selected_factors_count == max_to_select) // enough factors selected
		return floor(range / value); // compute number of numbers dividable by value (= multiplication of factors)

	if (selected_factors_count + std::distance(factors_begin, factors_end) >= max_to_select) // not enough numbers left in factors
		for (auto it = factors_begin; it != factors_end; it++) // for all available factors
			count += number_of_occurences(std::next(it), factors_end, selected_factors_count + 1, max_to_select, range, value*(*it));

	return count;
}

ll run()
{
	ll count = MAX_VALUE - 1;

	fori2(2, MAX_VALUE) // n
	{
		ll factor = -1;
		ll range = MAX_VALUE - i; // possible d values from n to max

		count += range; // assume all d values are ok
		forj2(1, (int)prime_factors[i].size() + 1) 
		{
			count += factor * number_of_occurences(prime_factors[i].begin(), prime_factors[i].end(), 0, j, range, 1);
			factor *= -1;
		}
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
