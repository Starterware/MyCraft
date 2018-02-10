/*
	Project Euler Problem 93 - Arithmetic Expressions
*/

#include "project_euler_environment.hpp"

#define MAX_VAL 10

typedef std::set<double> value_set_t;

size_t consecutives(value_set_t& s)
{
	fori2(1, (int)s.size() + 1) {
		if (s.find(i) == s.end())
			return i - 1;
	}

	return s.size();
}

void compute_2(value_set_t& result, double a, double b)
{
	result.insert(a + b);
	result.insert(a - b);
	result.insert(a * b);
	if (b != 0)
		result.insert(a / b);
	result.insert(b - a);
	if (a != 0)
		result.insert(b / a);
}
value_set_t compute_2(double a, double b)
{
	value_set_t result;
	compute_2(result, a, b);
	return result;
}

void compute_3(value_set_t& result, double a, double b, double c)
{
	value_set_t obtained;
	
	obtained = compute_2(a, b);
	forit(obtained) 
		compute_2(result, c, (*it));

	obtained = compute_2(c, b);
	forit(obtained)
		compute_2(result, a, (*it));

	obtained = compute_2(a, c);
	forit(obtained)
		compute_2(result, b, (*it));
}

value_set_t compute_3(double a, double b, double c)
{
	value_set_t result;
	compute_3(result, a, b, c);
	return result;
}

value_set_t compute_4(double a, double b, double c, double d)
{
	value_set_t result;
	value_set_t obtained;
	value_set_t obtained_2;

	obtained = compute_3(a, b, c);
	forit(obtained)
		compute_2(result, d, (*it));

	obtained = compute_3(a, b, d);
	forit(obtained) 
		 compute_2(result, c, (*it));

	obtained = compute_3(a, d, c);
	forit(obtained) 
		compute_2(result, b, (*it));

	obtained = compute_3(d, b, c);
	forit(obtained) 
		compute_2(result, a, (*it));

	obtained = compute_2(a, b);
	forit(obtained) { 
		obtained_2 = compute_2(c, d);
		forit2(obtained_2) 
			 compute_2(result, (*it2), (*it));
	}

	obtained = compute_2(a, c);
	forit(obtained) {
		obtained_2 = compute_2(b, d);
		forit2(obtained_2) 
			compute_2(result, (*it2), (*it));
	}

	obtained = compute_2(a, d);
	forit(obtained) {
		obtained_2 = compute_2(b, c);
		forit2(obtained_2) 
			compute_2(result, (*it2), (*it));
	}

	return result;
}

std::string run()
{
	int best = 0;
	std::string result;

	fori2(1, MAX_VAL) {
		forj2(i + 1, MAX_VAL) {
			fork2(j + 1, MAX_VAL) {
				forl2(k + 1, MAX_VAL)
				{
					value_set_t computed = compute_4(i, j, k, l);
					int candidate = consecutives(computed);

					if (candidate > best) {
						std::stringstream ss;
						ss << i << j << k << l;
						result = ss.str();
						best = candidate;
					}
				}
			}
		}
	}

	return result;
}

int main()
{
	cout << "Solution: " << run() << endl;
	return 0;
}
