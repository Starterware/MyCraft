#include "project_euler_environment.hpp"
#include "prime_utils.hpp"

#define MAX_VALUE 1000000

std::unordered_set<int> *prime_factors;

bool has_common_divider(int i, int j)
{
	forit(prime_factors[i])
		if (prime_factors[j].find(*it) != prime_factors[j].end())
			return true;
	return false;
}

int run()
{
	double best_solution = 0;
	int num = 0;

	fori2(1, MAX_VALUE) {
		forj2(ceil((double)i * 7 / 3), MAX_VALUE) {
			double solution = (double)i / j;

			if (solution <= best_solution || (i == 3 && j == 7))
				break;

			if (!has_common_divider(i, j)) {
				num = i;
				best_solution = solution;
			}
		}
	}

	return num;
}

int main()
{
	prime_factors = compute_prime_factors(MAX_VALUE);

	cout << "Solution: " << run() << endl;

	delete[] prime_factors;
	return 0;
}