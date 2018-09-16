
#ifndef RECURSIVE_TRIE_HPP
#define RECURSIVE_TRIE_HPP

#include "Dictionary.hpp"
#include "StringMetricCalculator.hpp"

#include <map>
#include <memory>

class RecursiveTrie : public Dictionary
{
public:
	void insert(const std::string& word);
	void insert(const std::vector<std::string>& words);
	bool search(const std::string& word) const;
	int search_best_matches(const std::string& word, std::vector<std::string>& matches);

private:
	class Node {
	public:
		Node();

		void insert(const std::string& word);
		bool search(const std::string& word) const;
		int search_best_matches(StringMetricCalculator& calculator, std::vector<std::string>& matches);

	private:
		std::map<char, std::shared_ptr<Node>> children;
		bool is_end_point = false;
	};

	Node root;
};

#endif
