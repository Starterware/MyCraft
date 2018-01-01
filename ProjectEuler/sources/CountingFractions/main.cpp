#include "project_euler_environment.hpp"
#include "prime_utils.hpp"

#define MAX_VALUE 1000000 

std::unordered_set<int> *prime_factors;
#define ITERATOR std::unordered_set<int>::iterator

ll test(ITERATOR position_in_primes, ITERATOR end_position_in_primes, int number_of_selected_primes, int number_of_primes_to_select, int range, int current_value)
{
	ll count = 0;

	if (number_of_selected_primes == number_of_primes_to_select) 
		return floor(range / current_value);

	if (number_of_selected_primes + std::distance(position_in_primes, end_position_in_primes) >= number_of_primes_to_select)
		for (auto it = position_in_primes; it != end_position_in_primes; it++)
			count += test(std::next(it), end_position_in_primes, number_of_selected_primes + 1, number_of_primes_to_select, range, current_value*(*it));

	return count;
}

ll run()
{
	ll count = MAX_VALUE - 1;

	fori2(2, MAX_VALUE)
	{
		ll factor = -1;
		ll range = MAX_VALUE - i;

		count += range;

		forj2(1, (int)prime_factors[i].size() + 1) 
		{
			count += factor * test(prime_factors[i].begin(), prime_factors[i].end(), 0, j, range, 1);
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
