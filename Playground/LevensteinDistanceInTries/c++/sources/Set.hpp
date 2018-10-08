#ifndef SET_HPP
#define SET_HPP

#include "Dictionary.hpp"

#include <set>

class Set : public Dictionary
{
public:
	EXPORT_DECLSPEC void insert(const std::string& word);
	EXPORT_DECLSPEC void insert(const std::vector<std::string>& words);
	EXPORT_DECLSPEC bool search(const std::string& word) const;
	EXPORT_DECLSPEC int search_best_matches(StringMetricCalculator& calculator, std::set<std::string>& matches);

private:
	std::set<std::string> words;
};

#endif
