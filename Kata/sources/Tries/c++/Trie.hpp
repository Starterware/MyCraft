#ifndef TRIE_HPP
#define TRIE_HPP

#include <vector>
#include <string>
#include <map>
#include <memory>

#define ALPHABET_SIZE 26

class Trie 
{
public:
	Trie();

	void insert(const std::string& word);
	void insert(const std::vector<std::string>& words);
	bool search(const std::string& word) const;

protected:
	struct Node {
		std::map<char, std::shared_ptr<Node>> children;
		bool is_end_point = false;
	};

	std::shared_ptr<Node> root;
};

#endif