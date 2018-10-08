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

bool Set::search(const std::string& word) const
{
	return words.find(word) != words.end();
}

int Set::search_best_matches(StringMetricCalculator& calculator, std::set<std::string>& matches)
{
	int best_score = INT32_MAX;
	matches.clear();

	for (auto& candidate : words)
	{
		calculator.append_string_to_compared_word(candidate);

		int score = calculator.get_result();
		if (score <= best_score)
		{
			if (score < best_score) {
				best_score = score;
				matches.clear();
			}
			matches.insert(candidate);
		}

		calculator.clear_compared_word();
	}

	return best_score;
}
