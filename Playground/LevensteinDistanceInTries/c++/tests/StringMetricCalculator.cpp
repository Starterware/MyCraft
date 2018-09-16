#include "StringMetricCalculator.hpp"
#include "StringMetricCalculatorStub.hpp"

StringMetricCalculatorStub::StringMetricCalculatorStub(const std::vector<std::string>& best_words, int score, const std::string & base_word)
{
	this->best_words = best_words;
	this->base_word = base_word;
	this->score = score;
}

void StringMetricCalculatorStub::set_base_word(const std::string& word_to_compare_against)
{
	if (word_to_compare_against != base_word)
		throw std::exception(std::string(word_to_compare_against + " is not the expected base word: " + base_word).c_str());
}

void StringMetricCalculatorStub::pop()
{
	validate_stub();
	if (!current_word.empty())
		current_word.pop_back();
}

void StringMetricCalculatorStub::clear()
{
	validate_stub();
	current_word = "";
}

void StringMetricCalculatorStub::push(const char& c)
{
	validate_stub();
	current_word.push_back(c);
}

void StringMetricCalculatorStub::push(const std::string& s)
{
	validate_stub();
	current_word += s;
}

int StringMetricCalculatorStub::get_result() const
{
	validate_stub();
	if (std::find(best_words.begin(), best_words.end(), current_word) != best_words.end())
		return score;
	return score + 1;
}

std::string StringMetricCalculatorStub::get_searched_word() const
{
	return current_word;
}

void StringMetricCalculatorStub::validate_stub() const
{
	if (base_word.empty())
		throw std::exception("Base word has not been set");
}
