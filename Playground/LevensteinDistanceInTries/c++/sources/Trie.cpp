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
			if (current_node->children.at(word[i]) == NULL) 
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

			current_node->children[word[i]] = NULL;
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
		if (current_node->children.find(word[i]) == current_node->children.end() || (current_node->children[word[i]] == NULL && i != word.length() - 1))
			return false;

		current_node = current_node->children[word[i]];
	}

	return current_node == NULL || current_node->is_end_point;
}

int Trie::search_best_matches(const std::string & word, std::vector<std::string>& matches)
{
	matches.clear();
	string_metric_calculator->set_base_word(word);

	int best_score = INT32_MAX;
	std::shared_ptr<Node> current_node = root;
	std::stack<std::pair<std::shared_ptr<Node>, std::map<char, std::shared_ptr<Node> >::iterator> > s;

	s.push(std::make_pair(current_node, current_node->children.begin()));
	while (!s.empty())
	{
		std::pair<std::shared_ptr<Node>, std::map<char, std::shared_ptr<Node> >::iterator> p = s.top(); s.pop();

		if (p.second != p.first->children.end())
		{
			current_node = p.second->second;
			string_metric_calculator->push(p.second->first);

			if (current_node == NULL || current_node->is_end_point) 
			{
				int score = string_metric_calculator->get_result();
				if (score <= best_score)
				{
					if (score < best_score) {
						matches.clear();
						best_score = score;
					}

					matches.push_back(string_metric_calculator->get_searched_word());
				}
			}

			p.second++;
			s.push(std::make_pair(p.first, p.second));
			if (current_node != NULL) 
				s.push(std::make_pair(current_node, current_node->children.begin()));
			else
				string_metric_calculator->pop();
		}
		else
		{
			string_metric_calculator->pop();
		}
	}

	return best_score;
}
