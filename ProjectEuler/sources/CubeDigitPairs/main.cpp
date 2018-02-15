/*
	Project Euler Problem 90 - Cube Digit Pairs
*/

#include "project_euler_environment.hpp"

#define SQUARE_SIZE 9
#define DICE_SIZE 6

std::vector<std::pair<int, int> > squares = { { 0, 1 }, { 0, 4 }, { 0, 9 }, { 1, 6 }, { 2, 5 }, { 3, 6 }, { 4, 9 }, { 6, 4 }, { 8, 1 } };
std::set<std::set<int> > s;

void generate(std::set<int>& a, int start)
{
	if (a.size() == DICE_SIZE)
	{
		s.insert(a);
		return;
	}

	fori2(start, 10)
	{
		a.insert(i);
		generate(a, i + 1);
		a.erase(i);
	}
}

void init()
{
	std::set<int> a;
	generate(a, 0);
}

bool contains(const std::set<int>& a, const std::set<int>& b, int val_a, int val_b)
{
	return (a.find(val_a) != a.end() && b.find(val_b) != b.end()) || (a.find(val_b) != a.end() && b.find(val_a) != b.end());
}

bool is_valid(const std::set<int>& a, const std::set<int>& b)
{
	forit(squares) 
	{
		if (contains(a, b, it->first, it->second))
			continue;

		if (it->first == 9 && (contains(a, b, 6, it->second) || (it->second == 6 && contains(a, b, 6, 9)) || (it->second == 9 && contains(a, b, 6, 6))))
				continue;

		if (it->first == 6 && (contains(a, b, 9, it->second) || (it->second == 9 && contains(a, b, 6, 6)) || (it->second == 6 && contains(a, b, 6, 9))))
				continue;

		if (it->second == 9 && contains(a, b, it->first, 6))
				continue;

		if (it->second == 6 && contains(a, b, it->first, 9))
				continue;

		return false;
	}

	return true;
}

ll run()
{
	int count = 0;
	forit(s)
		for(std::set<std::set<int> >::iterator it2 = it; it2 != s.end(); it2++)
			if (is_valid(*it, *it2))
				count++;

	return count;
}

int main()
{
	init();
	cout << "Solution: " << run() << endl;
	return 0;
}
