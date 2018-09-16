#ifndef SET_HPP
#define SET_HPP

#include "Dictionary.hpp"

#include <set>

class Set : public Dictionary
{
public:
	void insert(const std::string& word);
	void insert(const std::vector<std::string>& words); 
	bool search(const std::string& word) const;
	int search_best_matches(const std::string& word, std::vector<std::string>& matches);

private:
	std::set<std::string> words;
};

#endif