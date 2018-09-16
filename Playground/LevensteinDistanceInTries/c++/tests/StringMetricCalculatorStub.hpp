#ifndef DICTIONARY_BENCHMARKS_HPP
#define DICTIONARY_BENCHMARKS_HPP

#include "StringMetricCalculator.hpp"

#include <vector>
#include <string>

class StringMetricCalculatorStub : public StringMetricCalculator
{
public:
	StringMetricCalculatorStub(const std::vector<std::string>& best_words, int score, const std::string& base_word);

	virtual void set_base_word(const std::string& word_to_compare_against);

	virtual void pop();
	virtual void clear();

	virtual void push(const char& c);
	virtual void push(const std::string& s);

	virtual int get_result() const;
	virtual std::string get_searched_word() const;

private:
	void validate_stub() const;

private:
	int score;
	std::string current_word;
	std::string base_word;
	std::vector<std::string> best_words;
};

#endif
