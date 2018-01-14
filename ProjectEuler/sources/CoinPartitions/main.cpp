/*
	Project Euler Problem X: 
*/

#include "project_euler_environment.hpp"
#define MAX_SIZE 100000
#define K_SIZE 1000

vector<ll> p;
ll k1[K_SIZE];
ll k2[K_SIZE];

void init()
{
	p.push_back(1);

	fori2(1, MAX_SIZE) {
		k1[i] = i * (i * 3 - 1) / 2;
		k2[i] = i * (i * 3 + 1) / 2;

		if (k1[i] > MAX_SIZE)
			break;
	}
}

ll compute_p_for(int n)
{
	int factor = 1;
	ll value = 0;

	fori2(1, n + 1)
	{
		if (k1[i] > n)
			break;

		value += factor * p[n - k1[i]];

		if (k2[i] <= n)
			value += factor * p[n - k2[i]];

		factor *= -1;
	}

	return value;
}

ll run()
{
	fori2(1, MAX_SIZE)
	{
		p.push_back(compute_p_for(i));

		p[i] %= 1000000;
		if (p[i] == 0)
			return i;

	}

	return -1;
}

int main()
{
	init();
	cout << "Solution: " << run() << endl;
	return 0;
}
