#ifndef TRIE_HPP
#define TRIE_HPP

#include <string>

#define ALPHABET_SIZE 26

class Trie 
{
public:
	void insert(const std::string& word);
	bool search(const std::string& word) const;

protected:
	struct Node {
		Node* children[ALPHABET_SIZE];
		bool is_end_point = false;
	};

	Node root;
};

#endif