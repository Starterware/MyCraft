#include "project_euler_environment.hpp"

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
