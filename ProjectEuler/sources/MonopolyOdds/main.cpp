/*
	Project Euler Problem 84 - Monopoly Odds 
*/

#include "project_euler_environment.hpp"
#include "prime_utils.hpp"

#define BOARD_SIZE 40
#define DICE_VALUES 4 
#define PRISON 10
#define TOTAL_TURNS 10000000

ll p[BOARD_SIZE];

void init()
{
	fori(BOARD_SIZE)
		p[i] = 0;
}

int find_highest_p_index()
{
	int index = 0;

	fori2(1, BOARD_SIZE)
		if (p[i] > p[index])
			index = i;

	return index;
}

int result()
{
	int index;
	int result = 0;

	fori(3) {
		index = find_highest_p_index();
		result *= 100;
		result += index;
		p[index] = 0;
	}

	return result;
}

void print()
{
	fori(BOARD_SIZE)
		cout << i << "[" << p[i] << ": " << ((double)p[i] * 100 / TOTAL_TURNS) << "] ";
	cout << endl;
}

int next_index(int index, int t1, int t2)
{
	static int double_count = 0;

	if (t1 == t2)
		double_count++;
	else
		double_count = 0;

	if (double_count == 3) {
		double_count = 0;
		return PRISON;
	}

	int next_index = (index + t1 + t2) % BOARD_SIZE;

	if (next_index == 2 || next_index == 17 || next_index == 33)
	{
		int r = std::rand() % 16;

		if (r == 0)
			next_index = 0;
		else if (r == 1) {
			next_index = PRISON;
			double_count = 0;
		}
	}
	else if (next_index == 30)
	{
		next_index = PRISON;
		double_count = 0;
	}
	else if (next_index == 7 || next_index == 22 || next_index == 36)
	{
		int r = std::rand() % 16;

		if (r == 0)
			next_index = 0;
		else if (r == 1)
			next_index = 5;
		else if (r == 2) {
			next_index = PRISON;
			double_count = 0;
		}
		else if (r == 3)
			next_index = 11;
		else if (r == 4)
			next_index = 24;
		else if (r == 5)
			next_index = 39;
		else if (r == 6)
			next_index = index - 3;
		else {
			if (next_index == 7) {
				if (r == 8 || r == 7)
					next_index = 15;
				else if (r == 9)
					next_index = 12;
			}
			else if (next_index == 22) {
				if (r == 8 || r == 7)
					next_index = 25;
				else if (r == 9)
					next_index = 28;
			}
			else {
				if (r == 8 || r == 7)
					next_index = 5;
				else if (r == 9)
					next_index = 12;
			}
		}
	}

	return next_index;
}

ll run()
{
	srand(time(nullptr));

	int index = 0;

	fori(TOTAL_TURNS)
	{
		int t1 = rand() % DICE_VALUES + 1;
		int t2 = rand() % DICE_VALUES + 1;

		index = next_index(index, t1, t2);
		p[index]++;
	}

	//print();

	return result();
}

int main()
{
	init();
	cout << "Solution: " << run() << endl;
	return 0;
}