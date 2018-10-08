
#ifndef RECURSIVE_TRIE_HPP
#define RECURSIVE_TRIE_HPP

#include "Dictionary.hpp"
#include "StringMetricCalculator.hpp"
#include "LevensteinDistanceInTries.hpp"

#include <map>
#include <unordered_map>
#include <memory>

class RecursiveTrie : public Dictionary
{
public:
	EXPORT_DECLSPEC void insert(const std::string& word);
	EXPORT_DECLSPEC void insert(const std::vector<std::string>& words);
	EXPORT_DECLSPEC bool search(const std::string& word) const;
	EXPORT_DECLSPEC int search_best_matches(StringMetricCalculator& calculator, std::set<std::string>& matches);

private:
	class Node {
	public:
		EXPORT_DECLSPEC Node();

		void insert(const std::string& word);
		bool search(const std::string& word) const;
		void search_best_matches(StringMetricCalculator& calculator, std::set<std::string>& matches, int& best_score);

	private:
		void sort_children(StringMetricCalculator& calculator, std::multimap<int, std::pair<char, std::shared_ptr<Node>>>& sorted_children);
		
	private:
		std::map<char, std::shared_ptr<Node>> children;
		bool is_end_point = false;
	};

	Node root;
};

#endif
