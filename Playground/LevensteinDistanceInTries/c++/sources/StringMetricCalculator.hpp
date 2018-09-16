#ifndef STRING_METRIC_CALCULATOR_HPP
#define STRING_METRIC_CALCULATOR_HPP

#include <string>

class StringMetricCalculator
{
public:
	virtual void set_base_word(const std::string& word_to_compare_against) = 0;

	virtual void pop() = 0;
	virtual void clear() = 0;

	virtual void push(const char& c) = 0;
	virtual void push(const std::string& s) = 0;

	virtual int get_result() const = 0;
	virtual std::string get_searched_word() const = 0;
};

#endif
