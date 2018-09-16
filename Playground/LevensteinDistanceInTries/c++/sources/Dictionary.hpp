#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <string>
#include <vector>
#include <memory>

#include "StringMetricCalculator.hpp"

class Dictionary
{
public:
	virtual void insert(const std::string& word) = 0;
	virtual void insert(const std::vector<std::string>& words) = 0;
	virtual bool search(const std::string& word) const = 0;
	virtual int search_best_matches(const std::string& word, std::vector<std::string>& matches) = 0;
	virtual void set_string_metric_calculator(std::shared_ptr<StringMetricCalculator>& calculator);

protected: 
	std::shared_ptr<StringMetricCalculator> string_metric_calculator;
};

#endif
