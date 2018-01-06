/*
	Project Euler Problem 74 - Digit Factorial Chains
*/

#include "project_euler_environment.hpp"

int factorial[10];

void init()
{
	factorial[0] = 1;
	fori2(1, 10)
		factorial[i] = factorial[i - 1] * i;
}

int compute_next_term(int number)
{
	int next = 0;

	while (number > 0) {
		next += factorial[number % 10];
		number /= 10;
	}

	return next;
}

int count_non_repeating_terms(int number)
{
	unordered_set<int> used_numbers;
	used_numbers.insert(number);

	while (used_numbers.size() < 61) { 
		number = compute_next_term(number);
		if (used_numbers.find(number) != used_numbers.end())
			break;
		used_numbers.insert(number);
	}

	return used_numbers.size();
}

int run()
{
	int count = 0;

	fori(1000000)
		if (count_non_repeating_terms(i) == 60)
			count++;

	return count;
}

int main()
{
	init();

	cout << "Solution: " << run() << endl;

	return 0;
}