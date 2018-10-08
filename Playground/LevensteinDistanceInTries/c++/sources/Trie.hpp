#ifndef TRIE_HPP
#define TRIE_HPP

#include "Dictionary.hpp"
#include "LevensteinDistanceInTries.hpp"

#include <vector>
#include <string>
#include <map>
#include <memory>

#define ALPHABET_SIZE 26

class Trie : public Dictionary
{
private:
	struct Node {
		std::map<char, std::shared_ptr<Node>> children;
		bool is_end_point = false;
	};

public:
	EXPORT_DECLSPEC Trie();

	EXPORT_DECLSPEC void insert(const std::string& word);
	EXPORT_DECLSPEC void insert(const std::vector<std::string>& words);
	EXPORT_DECLSPEC bool search(const std::string& word) const;
	EXPORT_DECLSPEC int search_best_matches(StringMetricCalculator& calculator, std::set<std::string>& matches);

private:
	bool is_end_point(const std::shared_ptr<Node>& node) const;
	bool has_children(const std::shared_ptr<Node>& node) const;

	std::shared_ptr<Node> root;
};

#endif
