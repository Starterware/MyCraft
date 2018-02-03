/*
	Project Euler Problem 91 - Right Triangle With Integer Coordinates
*/

#include "project_euler_environment.hpp"

#define SIZE 51

bool is_valid(int x, int y, int x2, int y2)
{
	int l1 = x*x + y*y;
	int l2 = x2*x2 + y2*y2;
	int l3 = ((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));

	return l1 + l2 == l3 || l2 + l3 == l1 || l1 + l3 == l2;
}

ll run()
{
	ll count = 0;

	fori2(1, SIZE*SIZE)
		forj2(i+1, SIZE*SIZE)
			if (is_valid(i % SIZE, i / SIZE, j % SIZE, j / SIZE)) 
				count++;

	return count;
}

int main()
{
	cout << "Solution: " << run() << endl;
	return 0;
}
