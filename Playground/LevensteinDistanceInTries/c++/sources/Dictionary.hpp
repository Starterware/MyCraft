#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <string>
#include <vector>
#include <set>
#include <memory>

#include "StringMetricCalculator.hpp"

class Dictionary
{
public:
	virtual void insert(const std::string& word) = 0;
	virtual void insert(const std::vector<std::string>& words) = 0;
	virtual bool search(const std::string& word) const = 0;
	virtual int search_best_matches(StringMetricCalculator& calculator, std::set<std::string>& matches) = 0;
};

#endif
