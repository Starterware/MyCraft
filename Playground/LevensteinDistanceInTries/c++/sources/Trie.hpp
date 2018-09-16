#ifndef TRIE_HPP
#define TRIE_HPP

#include "Dictionary.hpp"

#include <vector>
#include <string>
#include <map>
#include <memory>

#define ALPHABET_SIZE 26

class Trie : public Dictionary
{
public:
	Trie();

	void insert(const std::string& word);
	void insert(const std::vector<std::string>& words);
	bool search(const std::string& word) const;
	int search_best_matches(const std::string& word, std::vector<std::string>& matches);

protected:
	struct Node {
		std::map<char, std::shared_ptr<Node>> children;
		bool is_end_point = false;
	};

	std::shared_ptr<Node> root;
};

#endif