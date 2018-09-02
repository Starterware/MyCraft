#include "Trie.hpp"

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

	for (int i = 0; i < word.length(); i++) {
		if (current_node->children.find(word[i]) == current_node->children.end())
			current_node->children[word[i]] = std::shared_ptr<Node>(new Node);
		current_node = current_node->children[word[i]];
	}

	current_node->is_end_point = true;
}

bool Trie::search(const std::string& word) const
{
	std::shared_ptr<Node> current_node = root;

	for (int i = 0; i < word.length(); i++) {
		if (current_node->children.find(word[i]) == current_node->children.end())
			return false;
		current_node = current_node->children[word[i]];
	}

	return current_node->is_end_point;
}