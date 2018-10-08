#include "StringMetricCalculator.hpp"
#include "StringMetricCalculatorStub.hpp"

StringMetricCalculatorStub::StringMetricCalculatorStub(const std::set<std::string>& best_words, int score)
{
	this->best_words = best_words;
	this->score = score;
}

void StringMetricCalculatorStub::set_base_word(const std::string& word_to_compare_against)
{

}

void StringMetricCalculatorStub::pop_last_char_of_compared_word()
{
	if (!current_word.empty())
		current_word.pop_back();
}

void StringMetricCalculatorStub::clear_compared_word()
{
	current_word = "";
}

void StringMetricCalculatorStub::append_char_to_compared_word(const char& c)
{
	current_word.push_back(c);
}

void StringMetricCalculatorStub::append_string_to_compared_word(const std::string& s)
{
	current_word += s;
}

int StringMetricCalculatorStub::get_result() const
{
	if (best_words.find(current_word) != best_words.end())
		return score;
	return score + 1;
}

int StringMetricCalculatorStub::get_potential_best_result() const
{
	return 0;
}

std::string StringMetricCalculatorStub::get_compared_word() const
{
	return current_word;
}
