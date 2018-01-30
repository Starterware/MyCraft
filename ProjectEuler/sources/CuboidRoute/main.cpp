/*
	Project Euler Problem 86 - Cuboid Route
*/

#include "project_euler_environment.hpp"

#define MAX_LENGTH 10000
#define TARGET 1000000

ll saved[MAX_LENGTH];

void init()
{
	fori(MAX_LENGTH) 
		saved[i] = 0;
}

bool is_square(ll value)
{
	double s = sqrt(value);
	int int_s = floor(s);

	return (s - int_s) == 0;
}

ll run()
{
	int finished = 0;
	int i = 1;

	while(true) {
		forj2(1, i) {
			ll length = i*i + j*j;
			if (is_square(length)) {
 				saved[i] += floor(j / 2);
				if (i > j && i <= j * 2)
					saved[j] += floor((j - (i - j)) / 2) + 1;
			}
		}
		
		if (i % 2 == 0) {
			finished = floor(i / 2);
			saved[finished] += saved[finished - 1];
			if (saved[finished] >= TARGET)
				break;
		}

		i++;
	}

	return finished;
}

int main()
{
	init();
	cout << "Solution: " << run() << endl;
	return 0;
}
