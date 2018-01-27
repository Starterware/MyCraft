/*
	Project Euler Problem 100 - Arranged Probability 
*/

#include "project_euler_environment.hpp"

#define MIN_VALUE 1e12

void compute_continued_fraction(std::vector<ll>& a, ll& num, ll& den)
{
	ll save;

	num = 0;
	den = 1;

	for (int i = a.size() - 1; i >= 0; i--) {
		save = den;
		den = a[i] * den + num;
		num = save;
	}

	save = num;
	num = den;
	den = save;
}

/*
	n = #disks
	a = #blue disks
	=> (2n - 1)^2 - 2 (2a - 1)^2 = 0
	=> X^2 - 2Y^2 = -1 (pell's equation)
*/
ll run()
{
	std::vector<ll> a;
	int round = 0; // ignore delta equal to 1 only take equal to -1
	ll num, den;

	a.push_back(1); // continued fraction of sqrt(2) = 1, 2, 2, ...
	do {
		a.push_back(2);
		compute_continued_fraction(a, num, den);
		round++;
	} while (num < 2 * MIN_VALUE - 1 || round % 2 != 0);

	return (den + 1) / 2;
}

int main()
{
	cout << "Solution: " << run() << endl;
	return 0;
}

