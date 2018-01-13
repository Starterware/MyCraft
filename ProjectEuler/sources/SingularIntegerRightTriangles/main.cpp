/*
	Project Euler Problem 75 - Singular Integer Right Triangles
*/

#include "project_euler_environment.hpp"
#include "prime_utils.hpp"

#define MAX_SIZE 1500000

int length_counter[MAX_SIZE + 1];

void init()
{
	fori(MAX_SIZE + 1)
		length_counter[i] = 0;
}

ll result()
{
	ll count = 0;

	fori (MAX_SIZE)
		if (length_counter[i] == 1)
			count++;

	return count;
}

void update_length_counter(ll l)
{
	for (ll i = l; i <= MAX_SIZE; i += l)
		length_counter[i]++;
}

ll run()
{
	for (ll i = 1; 2 * i*i <= MAX_SIZE; i += 2)
		for (ll j = i + 2; (i + j)*j <= MAX_SIZE; j += 2)
			if (are_coprime(i, j))
				update_length_counter((i + j)*j);

	return result();
}

int main()
{
	init();
	cout << "Solution: " << run() << endl;
	return 0;
}
