#include "Trie.hpp"

void Trie::insert(const std::string& word)
{
	root.is_end_point = true;
}

bool Trie::search(const std::string& word) const
{
	return root.is_end_point;
}