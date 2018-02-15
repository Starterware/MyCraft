/*
	Project Euler Problem 98 - 	Anagramic Squares
*/

#include "project_euler_environment.hpp"

#define MAX_WORD_LENGTH 9

typedef std::map<std::string, std::set<std::string> > dic_t;
typedef std::map<int, std::set<int> > squares_t;

dic_t dic;
squares_t squares;

void read_file()
{
	std::string word;
	std::string sorted;

	fori(1786) {
		std::cin >> word;

		sorted = word;
		std::sort(sorted.begin(), sorted.end());

		dic[sorted].insert(word);
	}

	dic_t::iterator to_delete;
	for (dic_t::iterator it = dic.begin(); it != dic.end(); ) 
	{
		to_delete = (it->second.size() < 2) ? it : dic.end();
		++it;
		if (to_delete != dic.end())
			dic.erase(to_delete);
	}
}

void init() 
{
	int min_v = 10;
	int digits = 1;

	for (int i = 1; ; i++) 
	{
		int s = i*i;

		if (s > min_v) {
			++digits;
			min_v *= 10;

			if (digits > MAX_WORD_LENGTH)
				break;
		}

		squares[digits].insert(s);
	}
}

ll compute(int square, const std::string& a, const std::string& b)
{
	int value_1 = 0;
	int value_2 = 0;
	int alpha[26];
	bool used[10];

	fori(10)
		used[i] = false;

	fori(26) 
		alpha[i] = -1;

	// map square to first word
	forri(a.size()) {
		int pos = a[i] - 'A';
		int v = square % 10;

		if ((alpha[pos] != -1 && alpha[pos] != v ) || (alpha[pos] == -1 && used[v])) {
			return -1;
		}

		alpha[pos] = v;
		value_1 *= 10 + v;
		square /= 10;
		used[v] = true;
	}

	// verify square of second word with first word mapping
	fori((int)b.size()) 
		value_2 = value_2 * 10 + alpha[b[i] - 'A'];

	if (squares[a.size()].find(value_2) != squares[a.size()].end())
		return (value_1 > value_2) ? value_1 : value_2;

	return  -1;
}

ll compute(const std::string& a, const std::string& b) 
{
	int best = 0;

	forit(squares[a.size()])
	{
		int candidate = compute(*it, a, b);
		if (candidate > best)
			 best = candidate;
	}

	return best;
}

ll compute(std::set<string>& s) 
{
	int best = 0;
	std::set<string>::iterator it2;

	forit(s) {
		it2 = it;
		while (++it2 != s.end()) {
			int candidate = compute(*it, *it2);
			if (candidate > best)
				best = candidate;
		}
	}

	return best;
}

ll run()
{
	ll best = 0;

	read_file();

	forrit(dic) {
		ll candidate = compute(it->second);
		if (candidate > best)
			best = candidate;
	}

	return best;
}

int main()
{
	init();
	cout << "Solution: " << run() << endl;
	return 0;
}
