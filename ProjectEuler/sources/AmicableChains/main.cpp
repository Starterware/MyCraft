/*
	Project Euler Problem 95 - Amicable Chains  
*/

#include "project_euler_environment.hpp"
 
#define SIZE 1000000

int divisors[SIZE+1];
bool used[SIZE+1];

int best = 0;
int smallest = SIZE;

void init()
{
	fori(SIZE + 1)
		divisors[i] = 0;

	fori2(1, SIZE+1)
	{
		for (int j = i*2; j < SIZE; j += i) {
			divisors[j] += i;
		}
	}

	fori(SIZE+1)
		used[i] = false;
}

int get_smallest(std::vector<int>& v)
{
	int search = v.back();
	int smallest = v.back();

	forri(v.size() - 1) {
		if (v[i] == search)
			break;

		if (v[i] < smallest)
			smallest = v[i];
	}

	return smallest;
}

void save(std::vector<int>& v)
{
	if (best > (int)v.size())
		return;

	if (best == (int)v.size())
	{
		int candidate = get_smallest(v);
		if (candidate < smallest)
			smallest = candidate;
	}
	else
	{
		smallest = get_smallest(v);
		best = v.size();
	}
}

bool find_cycle(std::vector<int>& v)
{
	bool found_cycle = false;

	do
	{
		if (v.back() > SIZE || used[v.back()])
			break;

		used[v.back()] = true;
		v.push_back(divisors[v.back()]);
		found_cycle = std::find(v.begin(), --v.end(), v.back()) != --v.end();
	} 
	while (!found_cycle);

	return found_cycle;
}

ll run()
{
	std::vector<int> v;

	fori2(1, SIZE+1) 
	{
		v.clear();
		v.push_back(i);

		if (find_cycle(v))
			save(v);
	}

	return smallest;
}

int main()
{
	init();
	cout << "Solution: " << run() << endl;
	return 0;
}
