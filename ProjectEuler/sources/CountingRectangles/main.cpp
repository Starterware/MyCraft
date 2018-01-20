/*
	Project Euler Problem 85 - Counting Rectangles 
*/

#include "project_euler_environment.hpp"

#define MAX_SIZE 2000000

std::map<int, int> sums;

void init()
{
	int i = 1, v = 1;

	while (v <= MAX_SIZE)
	{
		sums[v] = i;
		i++;
		v += i;
	}
}

ll run()
{
	int best = 0;
	int best_area = 0;

	forit(sums) {
		int length = floor((double)MAX_SIZE / it->first);

		auto bound = sums.upper_bound(length);
		if (bound == sums.begin())
			break;

		bound--;
		int rectangles = it->first * bound->first;

		if (rectangles > best) {
			best = rectangles;
			best_area = it->second * bound->second;
		}
	}

	return best_area;
}

int main()
{
	init();
	cout << "Solution: " << run() << endl;
	return 0;
}