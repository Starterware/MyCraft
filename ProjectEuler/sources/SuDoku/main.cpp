/*
	Project Euler Problem 96 - Su Doku
*/

#include "project_euler_environment.hpp"

#define NUMBER_OF_SUDOKU 50

std::set<int> possibilities;

struct sudo_t
{
	static const int SIZE = 9;

	std::set<int> p[SIZE][SIZE];

	sudo_t() {}
	sudo_t(const sudo_t& other)
	{
		*this = other;
	}

	sudo_t& operator=(const sudo_t& other)
	{
		if (&other != this) 
		{
			fori(SIZE){
				forj(SIZE) {
					this->p[i][j] = other.p[i][j];
				}
			}
		}

		return *this;
	}
};

void init()
{
	fori2(1, sudo_t::SIZE + 1)
		possibilities.insert(i);
}

bool propagate(sudo_t* s, int s_i, int s_j);

bool remove_item(sudo_t* s, int i, int j, int value)
{
	if (s->p[i][j].find(value) != s->p[i][j].end())
	{
		s->p[i][j].erase(value);

		if (s->p[i][j].size() == 0)
			return false;
		else if (s->p[i][j].size() == 1)
			if (!propagate(s, i, j))
				return false;
	}

	return true;
}

bool propagate(sudo_t* s, int s_i, int s_j)
{
	int value = (*s->p[s_i][s_j].begin());

	fori(sudo_t::SIZE)
		if (i != s_i && !remove_item(s, i, s_j, value))
			return false;

	forj(sudo_t::SIZE)
		if (j != s_j && !remove_item(s, s_i, j, value))
			return false;

	int f_i = s_i / 3;
	int f_j = s_j / 3;

	fori2(f_i * 3, (f_i + 1) * 3)
		forj2(f_j * 3, (f_j + 1) * 3)
			if (i != s_i && j != s_j && !remove_item(s, i, j, value))
				return false;

	return true;
}

sudo_t* read_next_sudo()
{
	sudo_t* s = new sudo_t();
	std::vector<int> cells_to_propagate;
	string name, number;
	char c;

	std::cin >> name >> number;

	fori(sudo_t::SIZE) 
	{
		forj(sudo_t::SIZE) 
		{
			std::cin >> c;
			int n = c - '0';

			if (n != 0) {
				cells_to_propagate.push_back(i * sudo_t::SIZE + j);
				s->p[i][j].insert(n);
			}
			else
				s->p[i][j] = possibilities;
		}
	}

	forit(cells_to_propagate)
		propagate(s, (*it) / sudo_t::SIZE, (*it) % sudo_t::SIZE);

	return s;
}

bool is_complete(sudo_t* s)
{
	fori(sudo_t::SIZE)
		forj(sudo_t::SIZE)
			if (s->p[i][j].size() != 1)
				return false;

	return true;
}

int find_next_cell(sudo_t* s)
{
	int best = 10;
	int pos = -1;

	fori(sudo_t::SIZE) {
		forj(sudo_t::SIZE) {
			int size = s->p[i][j].size();
			if (size > 1 && size < best) {
				best = size;
				pos = i * sudo_t::SIZE + j;
			}
		}
	}

	return pos;
}

bool backtrack(sudo_t* s)
{
	if (is_complete(s))
		return true;

	sudo_t saved = *s;

	int next_cell = find_next_cell(s);
	int i = next_cell / sudo_t::SIZE;
	int j = next_cell % sudo_t::SIZE;

	forit(saved.p[i][j]) 
	{
		s->p[i][j].clear();
		s->p[i][j].insert(*it);

		if(propagate(s, i, j) && backtrack(s))
			return true;

		*s = saved;
	}

	return false;
}

ll run()
{
	ll count = 0;

	fori(NUMBER_OF_SUDOKU)
	{
		sudo_t* s = read_next_sudo();
		if(backtrack(s))
			count += (*s->p[0][0].begin()) * 100 + (*s->p[0][1].begin()) * 10 + (*s->p[0][2].begin());
	}

	return count;
}

int main()
{
	init();
	cout << "Solution: " << run() << endl;
	return 0;
}
