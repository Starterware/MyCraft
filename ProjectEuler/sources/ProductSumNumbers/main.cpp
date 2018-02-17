/*
	Project Euler Problem 88 - Product-Sum Numbers
*/

#include "project_euler_environment.hpp"

#define NUMBER_SIZE 13000
#define K_MAX_SIZE 12000

int product_sum[K_MAX_SIZE + 1];

void init()
{
	fori(K_MAX_SIZE + 1)
		product_sum[i] = NUMBER_SIZE;
}

ll result()
{
	ll count = 0;
	std::set<int> used;

	fori2(2, K_MAX_SIZE + 1) {
		if (used.find(product_sum[i]) == used.end()) {
			count += product_sum[i];
			used.insert(product_sum[i]);
		}
	}

	return count;
}

void compute(int n, int k, int product, int sum)
{
	int real_k = k + product - sum;
	if (real_k > K_MAX_SIZE || n > NUMBER_SIZE)
		return;

	if (real_k > 1 && product_sum[real_k] > product)
		product_sum[real_k] = product;

	fori2(n + 1, NUMBER_SIZE) 
	{
		int cur_product = product;
		int cur_sum = sum;
		int cur_k = k;

		while (true)
		{
			cur_product *= i;
			cur_sum += i;
			cur_k++;

			if (cur_product > NUMBER_SIZE)
				break;

			compute(i, cur_k, cur_product, cur_sum);
		}
	}
}

ll run()
{
	compute(1, 0, 1, 0);
	return result();
}

int main()
{
	init();
	cout << "Solution: " << run() << endl;
	return 0;
}
