#ifndef DICTIONARY_BENCHMARKS_HPP
#define DICTIONARY_BENCHMARKS_HPP

#include "StringMetricCalculator.hpp"

#include <set>
#include <string>

class StringMetricCalculatorStub : public StringMetricCalculator
{
public:
	StringMetricCalculatorStub(const std::set<std::string>& best_words, int score);

	virtual void set_base_word(const std::string& word_to_compare_against);

	virtual void pop_last_char_of_compared_word();
	virtual void clear_compared_word();

	virtual void append_char_to_compared_word(const char& c);
	virtual void append_string_to_compared_word(const std::string& s);

	virtual int get_result() const;
	virtual int get_potential_best_result() const;
	virtual std::string get_compared_word() const;

private:
	int score;
	std::string current_word;
	std::set<std::string> best_words;
};

#endif
