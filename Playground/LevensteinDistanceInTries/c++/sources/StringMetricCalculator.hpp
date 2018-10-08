#ifndef STRING_METRIC_CALCULATOR_HPP
#define STRING_METRIC_CALCULATOR_HPP

#include "LevensteinDistanceInTries.hpp"

#include <string>

class StringMetricCalculator
{
public:
	virtual void set_base_word(const std::string& word_to_compare_against) = 0;

	virtual void pop_last_char_of_compared_word() = 0;
	virtual void clear_compared_word() = 0;

	virtual void append_char_to_compared_word(const char& c) = 0;
	virtual void append_string_to_compared_word(const std::string& s) = 0;

	virtual int get_result() const = 0;
	virtual int get_potential_best_result() const = 0;
	virtual std::string get_compared_word() const = 0;
};

#endif
