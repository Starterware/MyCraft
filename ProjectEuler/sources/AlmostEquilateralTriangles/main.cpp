/*
	Project Euler Problem 94 - Almost Equilateral Triangles 
*/

#include "continued_fractions.hpp"

#define SIZE 1000000000

ll run()
{
	int i = 0;
	double a, area;
	std::vector<ll> continued_fraction;
	ll count = 0;

	continued_fraction.push_back(1);
	continued_fraction.push_back(1);

	while (true)
	{
		ll num, den;

		// continued fraction of sqrt(3) = [1;1,2,1,2,...]: only take positives
		continued_fraction.push_back(2);
		continued_fraction.push_back(1);
		compute_continued_fraction(continued_fraction, num, den);

		a = (double)(2 * num - 1) / 3;
		if (a * 3 - 1 > SIZE)
			break;

		area = (double)(a - 1) * den / 2;
		if (a == (ll)a && area == (ll)area)
			count += a * 3 - 1;

		a = (double)(2 * num + 1) / 3;
		if (a * 3 + 1 > SIZE)
			break;

		area = (double)(a + 1) * den / 2;
		if (a == (ll)a && area == (ll)area)
			count += a * 3 + 1;

		i++;
	}

	return count;
}

int main()
{
	cout << "Solution: " << run() << endl;
	return 0;
}
