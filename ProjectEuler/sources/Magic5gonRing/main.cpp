/*
	Project Euler Problem 68 - Magic 5-gon Ring
*/

#include "project_euler_environment.hpp"

int gon_line_total = 0;
int gon[5][3];
bool used[10];
string best_solution = "0";

void init()
{
	fori(10)
		used[i] = false;
}

void save_solution()
{
	string solution = "";

	fori(5)
		forj(3)
			if (gon[i][j] > 9)
				solution += "10";
			else
				solution += (char)('0' + gon[i][j]);

	if (solution.length() == 16)
	{
		debug (solution);

		if (solution > best_solution)
			best_solution = solution;
	}
}

int line_total(int i)
{
	int total = 0;

	forj(3)
		total += gon[i][j];

	return total;
}

bool set_number_in_gon(int step, int number)
{
	switch (step)
	{
	case 1:
		gon[0][0] = number;
		if (number > 6)
			return false;
		break;
	case 4:
	case 6:
	case 8:
		gon[step/2 - 1][0] = number;
		if (gon[0][0] > number)
			return false;
		break;
	case 10:
		gon[4][0] = number;
		if (gon[0][0] > number || gon_line_total != line_total(4))
			return false;
		break;
	case 2:
		gon[0][1] = gon[4][2] = number;
		break;
	case 3:
		gon[0][2] = gon[1][1] = number;
		gon_line_total = line_total(0);
		break;
	case 5:
		gon[1][2] = gon[2][1] = number;
		if (gon_line_total != line_total(1))
			return false;
		break;
	case 7:
		gon[2][2] = gon[3][1] = number;
		if (gon_line_total != line_total(2))
			return false;
		break;
	case 9:
		gon[3][2] = gon[4][1] = number;
		if (gon_line_total != line_total(3))
			return false;
		break;
	}

	return true;
}

void run(int step)
{
	if (step == 11) {
		save_solution();
		return;
	}

	fori(10)
	{
		if (!used[i] && set_number_in_gon(step, i+1))
		{
			used[i] = true;
			run(step + 1);
			used[i] = false;
		}
	}
}

int main()
{
	init();
	run(1);

	cout << "Solution: " << best_solution << endl;

	return 0;
}