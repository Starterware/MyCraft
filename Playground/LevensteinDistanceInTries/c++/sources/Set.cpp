#include "Set.hpp"

#include <algorithm>

void Set::insert(const std::string& word)
{
	words.insert(word);
}

void Set::insert(const std::vector<std::string>& words)
{
	this->words.insert(words.begin(), words.end());
}

bool Set::search(const std::string & word) const
{
	return words.find(word) != words.end();
}
int Set::search_best_matches(const std::string & word, std::vector<std::string>& matches)
{
	int best_score = INT32_MAX;

	matches.clear();
	string_metric_calculator->set_base_word(word);

	for (auto& candidate : words) 
	{
		string_metric_calculator->push(candidate);

		int score = string_metric_calculator->get_result();
		if (score <= best_score) 
		{
			if (score < best_score) {
				best_score = score;
				matches.clear();
			}
			matches.push_back(candidate);
		}

		string_metric_calculator->clear();
	}

	return best_score;
}
