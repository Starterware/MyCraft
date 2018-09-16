#include "RecursiveTrie.hpp"

void RecursiveTrie::insert(const std::string& word)
{
	root.insert(word);
}

void RecursiveTrie::insert(const std::vector<std::string>& words)
{
	for (auto& word : words)
		root.insert(word);
}

bool RecursiveTrie::search(const std::string& word) const
{
	return root.search(word);
}

int RecursiveTrie::search_best_matches(const std::string& word, std::vector<std::string>& matches)
{
	matches.clear();
	string_metric_calculator->set_base_word(word);
	return root.search_best_matches(*string_metric_calculator, matches);
}

RecursiveTrie::Node::Node() :
	is_end_point { false }
{
}

void RecursiveTrie::Node::insert(const std::string& word)
{
	if (word.length() == 0)
	{
		is_end_point = true;
		return;
	}
	
	if (children.find(word[0]) == children.end())
	{
		if (word.length() == 1) {
			children[word[0]] = NULL;
			return;
		}
		else {
			children[word[0]] = std::shared_ptr<RecursiveTrie::Node>(new RecursiveTrie::Node());
		}
	}
	else if (children[word[0]] == NULL)
	{
		children[word[0]] = std::shared_ptr<RecursiveTrie::Node>(new RecursiveTrie::Node());
		children[word[0]]->is_end_point = true;
	}

	children[word[0]]->insert((char*)&word[1]);
}

bool RecursiveTrie::Node::search(const std::string& word) const
{
	if (word.length() == 0)
		return is_end_point;

	if (children.find(word[0]) == children.end()) 
		return false;

	if (children.at(word[0]) == NULL)
		return word.length() == 1;

	return children.at(word[0])->search((char*)&word[1]);
}

int RecursiveTrie::Node::search_best_matches(StringMetricCalculator& calculator, std::vector<std::string>& matches)
{
	int best_score = INT32_MAX;

	if (is_end_point) {
		matches.push_back(calculator.get_searched_word());
		best_score = calculator.get_result();
	}

	for (auto& child : children)
	{
		std::vector<std::string> child_matches;

		calculator.push(child.first);
		int score = (child.second == NULL) ? calculator.get_result() : child.second->search_best_matches(calculator, child_matches);

		if (score <= best_score) 
		{
			if (score < best_score) {
				matches.clear();
				best_score = score;
			}
			
			if (child.second == NULL) 
				matches.push_back(calculator.get_searched_word());
			else 
				matches.insert(matches.end(), child_matches.begin(), child_matches.end());
		}

		calculator.pop();
	}

	return best_score;
}
