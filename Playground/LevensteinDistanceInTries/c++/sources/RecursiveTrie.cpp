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

int RecursiveTrie::search_best_matches(StringMetricCalculator& calculator, std::set<std::string>& matches)
{
	int best_score = INT32_MAX;
	matches.clear();
	root.search_best_matches(calculator, matches, best_score);
	return best_score;
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
			children[word[0]] = nullptr;
			return;
		}
		else {
			children[word[0]] = std::shared_ptr<RecursiveTrie::Node>(new RecursiveTrie::Node());
		}
	}
	else if (children[word[0]] == nullptr)
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

	if (children.at(word[0]) == nullptr)
		return word.length() == 1;

	return children.at(word[0])->search((char*)&word[1]);
}

void RecursiveTrie::Node::search_best_matches(StringMetricCalculator& calculator, std::set<std::string>& matches, int& best_score)
{
	std::multimap<int, std::pair<char, std::shared_ptr<Node>>> sorted_children;
	sort_children(calculator, sorted_children);

	for (auto& sorted_child : sorted_children)
	{
		auto& child = sorted_child.second;
		calculator.append_char_to_compared_word(child.first);

		if (calculator.get_potential_best_result() > best_score) {
			calculator.pop_last_char_of_compared_word();
			break;
		}

		if (child.second == nullptr || child.second->is_end_point) 
		{
			int score = calculator.get_result();

			if (score <= best_score) {
				if (score < best_score) {
					matches.clear();
					best_score = score;
				}
				matches.insert(calculator.get_compared_word());
			}
		}

		if (child.second != nullptr)
			child.second->search_best_matches(calculator, matches, best_score);

		calculator.pop_last_char_of_compared_word();
	}
}

void RecursiveTrie::Node::sort_children(StringMetricCalculator& calculator, std::multimap<int, std::pair<char, std::shared_ptr<Node>>>& sorted_children)
{
	for (auto& child : children)
	{
		calculator.append_char_to_compared_word(child.first);
		sorted_children.insert(std::pair<int, std::pair<char, std::shared_ptr<Node>>>(calculator.get_potential_best_result(), child));
		calculator.pop_last_char_of_compared_word();
	}
}
