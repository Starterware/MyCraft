#ifndef LEVENSTEIN_DISTANCE_CALCULATOR_HPP 
#define LEVENSTEIN_DISTANCE_CALCULATOR_HPP

#include "StringMetricCalculator.hpp"

#include <string>
#include <vector>

class LevensteinDistanceMatrix : public StringMetricCalculator
{
public:
	LevensteinDistanceMatrix();

	virtual void set_base_word(const std::string& word_to_compare_against);

	virtual void pop();
	virtual void clear();

	virtual void push(const char& c);
	virtual void push(const std::string& s);

	virtual int get_result() const;
	virtual std::string get_searched_word() const;

	virtual std::string to_string();

private:
	std::string base_word;
	std::string searched_word;
	std::vector<std::vector<int> > m;
};

#endif
