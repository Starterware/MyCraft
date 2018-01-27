/*
	Project Euler Problem 87 - Prime Power Triples
*/

#include "project_euler_environment.hpp"
#include "prime_utils.hpp"
#define MAX_VECTOR_SIZE 1000
#define MAX_VALUE 50000000

int vector_size;
int squares[MAX_VECTOR_SIZE];
int cubes[MAX_VECTOR_SIZE];
int fourth_powers[MAX_VECTOR_SIZE];

void init()
{
	std::vector<int> *primes = compute_primes(sqrt(MAX_VALUE) + 1);

	for (vector_size = 0; vector_size < (int)primes->size(); vector_size++)
	{
		squares[vector_size] = (*primes)[vector_size] * (*primes)[vector_size];
		cubes[vector_size] = squares[vector_size] * (*primes)[vector_size];
		fourth_powers[vector_size] = cubes[vector_size] * (*primes)[vector_size];
	}

	delete primes;
}

ll run()
{
	std::unordered_set<int> generated;

	fori(vector_size) {
		forj(vector_size) {
			if (squares[i] + cubes[j] > MAX_VALUE)
				break;

			fork(vector_size) {
				int value = squares[i] + cubes[j] + fourth_powers[k];
				if (value > MAX_VALUE)
					break;

				generated.insert(value);
			}
		}
	}

	return generated.size();
}

int main()
{
	init();
	cout << "Solution: " << run() << endl;
	return 0;
}
