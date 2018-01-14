/*
	Project Euler Problem 80: Square Root Digital Expansion
*/

#include "project_euler_environment.hpp"

#define SIZE 100
#define NBR_DECIMALS 100

#define BIG_INT_SIZE 20
#define BIG_INT_CONTAINER_SIZE 1000000

void addition(ll result[BIG_INT_SIZE], ll first[BIG_INT_SIZE], ll second[BIG_INT_SIZE])
{
	ll post = 0;

	fori(BIG_INT_SIZE)
	{
		result[i] = first[i] + second[i] + post;
		post = result[i] / BIG_INT_CONTAINER_SIZE;
		result[i] %= BIG_INT_CONTAINER_SIZE;
	}
}

void addition_scalar(ll result[BIG_INT_SIZE], ll first[BIG_INT_SIZE], ll second)
{
	ll post = second;

	fori(BIG_INT_SIZE)
	{
		result[i] = first[i] + post;
		post = result[i] / BIG_INT_CONTAINER_SIZE;
		result[i] %= BIG_INT_CONTAINER_SIZE;
	}
}

void multiplication(ll result[BIG_INT_SIZE], ll first[BIG_INT_SIZE], ll second)
{
	ll post = 0;

	fori(BIG_INT_SIZE)
	{
		result[i] = first[i] * second + post;
		post = result[i] / BIG_INT_CONTAINER_SIZE;
		result[i] %= BIG_INT_CONTAINER_SIZE;
	}
}

void soustraction(ll result[BIG_INT_SIZE], ll first[BIG_INT_SIZE], ll second[BIG_INT_SIZE])
{
	forri(BIG_INT_SIZE)
	{
		while (first[i] < second[i])
		{
			forj2(i + 1, BIG_INT_SIZE) {
				if (result[j] != 0) {
					result[j]--;
					break;
				}
			}

			first[i] += BIG_INT_CONTAINER_SIZE;
		}

		result[i] = first[i] - second[i];
	}
}

bool bigger_than(ll first[BIG_INT_SIZE], ll second[BIG_INT_SIZE])
{
	forri(BIG_INT_SIZE)
	{
		if (first[i] < second[i])
			return false;
		else if (first[i] > second[i])
			return true;
	}

	return true;
}

void init_big_int(ll number[BIG_INT_SIZE])
{
	fori(BIG_INT_SIZE)
		number[i] = 0;
}

int decimal_addition(int number)
{
	long double x = floor(sqrt(number));
	int addition = x;

	ll y[BIG_INT_SIZE];
	ll p[BIG_INT_SIZE];
	ll c[BIG_INT_SIZE];
	ll tmp[BIG_INT_SIZE];

	init_big_int(y);
	init_big_int(c);
	init_big_int(p);

	addition_scalar(y, y, x*x);
	addition_scalar(c, c, (number - x*x) * 100);
	addition_scalar(p, p, x);

	fori2(1, 100) {
		x = 0;
		do
		{
			x++;
			multiplication(tmp, p, 20);
			addition_scalar(tmp, tmp, x);
			multiplication(tmp, tmp, x);
		} while (bigger_than(c, tmp));

		x--;
		multiplication(y, p, 20);
		addition_scalar(y, y, x);
		multiplication(y, y, x);

		addition += x;

		multiplication(p, p, 10);
		addition_scalar(p, p, x);
		soustraction(c, c, y);
		multiplication(c, c, 100);
	}

	return addition;
}

ll run()
{
	int addition = 0;
	fori2(2, 100)
	{
		double square_root = sqrt(i);
		if (square_root - floor(square_root) > 0.0)
			addition += decimal_addition(i);
	}

	return addition;
}

int main()
{
	cout << "Solution: " << run() << endl;
	return 0;
}
