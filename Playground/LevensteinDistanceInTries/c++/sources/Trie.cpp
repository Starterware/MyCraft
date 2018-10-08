#include "Trie.hpp"

#include <stack>

Trie::Trie()
{
	root = std::shared_ptr<Node>(new Node);
}

void Trie::insert(const std::vector<std::string>& words)
{
	for (auto& word : words)
		insert(word);
}

void Trie::insert(const std::string& word)
{
	std::shared_ptr<Node> current_node = root;

	for (int i = 0; i < word.length(); i++)
	{
		if (current_node->children.find(word[i]) != current_node->children.end())
		{
			if (!has_children(current_node->children.at(word[i]))) 
			{
				if (i == word.length() - 1)
					return;
				current_node->children[word[i]] = std::shared_ptr<Node>(new Node);
				current_node->children[word[i]]->is_end_point = true; 
			}
			current_node = current_node->children.at(word[i]);
		}
		else 
		{
			for (; i < word.length()-1; i++)
			{
				current_node->children[word[i]] = std::shared_ptr<Node>(new Node);
				current_node = current_node->children[word[i]];
			}

			current_node->children[word[i]] = nullptr;
			return;
		}			
	}

	current_node->is_end_point = true;
}

bool Trie::search(const std::string& word) const
{
	std::shared_ptr<Node> current_node = root;

	for (int i = 0; i < word.length(); i++) 
	{
		if (current_node->children.find(word[i]) == current_node->children.end())
			return false;
		
		if (!has_children(current_node->children.at(word[i])) && i != word.length() - 1)
			return false;

		current_node = current_node->children[word[i]];
	}

	return is_end_point(current_node);
}

int Trie::search_best_matches(StringMetricCalculator& calculator, std::set<std::string>& matches)
{
	int best_score = INT32_MAX;
	matches.clear();

	typedef std::map<char, std::shared_ptr<Node>>::iterator map_itertor;
	std::stack<std::pair<map_itertor, map_itertor>> s;

	s.push(std::make_pair(root->children.begin(), root->children.end()));
	while (!s.empty())
	{
		auto p = s.top(); s.pop();

		if (p.first != p.second)
		{
			std::shared_ptr<Node> current_node = p.first->second;
			calculator.append_char_to_compared_word(p.first->first);

			s.push(std::make_pair(++p.first, p.second));

			if (calculator.get_potential_best_result() > best_score) {
				calculator.pop_last_char_of_compared_word();
				continue;
			}

			if (is_end_point(current_node))
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

			if (has_children(current_node)) {
				s.push(std::make_pair(current_node->children.begin(), current_node->children.end()));
				continue;
			}
		}

		calculator.pop_last_char_of_compared_word();
	}

	return best_score;
}

bool Trie::is_end_point(const std::shared_ptr<Node>& node) const
{
	return !has_children(node) || node->is_end_point;
}

bool Trie::has_children(const std::shared_ptr<Node>& node) const
{
	return node != nullptr;
}
