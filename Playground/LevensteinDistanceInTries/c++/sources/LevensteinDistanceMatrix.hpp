#ifndef LEVENSTEIN_DISTANCE_CALCULATOR_HPP 
#define LEVENSTEIN_DISTANCE_CALCULATOR_HPP

#include "StringMetricCalculator.hpp"
#include "LevensteinDistanceInTries.hpp"

#include <string>
#include <vector>

class LevensteinDistanceMatrix : public StringMetricCalculator
{
public:
	EXPORT_DECLSPEC LevensteinDistanceMatrix();

	EXPORT_DECLSPEC virtual void set_base_word(const std::string& word_to_compare_against);

	EXPORT_DECLSPEC virtual void append_char_to_compared_word(const char& c);
	EXPORT_DECLSPEC virtual void append_string_to_compared_word(const std::string& s);
	EXPORT_DECLSPEC virtual void pop_last_char_of_compared_word();
	EXPORT_DECLSPEC virtual void clear_compared_word();

	EXPORT_DECLSPEC virtual int get_result() const; 
	EXPORT_DECLSPEC virtual int get_potential_best_result() const;
	EXPORT_DECLSPEC virtual std::string get_compared_word() const;

	EXPORT_DECLSPEC virtual std::string to_string();

private:
	int compute_min_path_cost(const int& i, const int& j, const char& c);

private:
	std::string base_word;
	std::string compared_word;
	std::vector<std::vector<int> > m;
};

#endif
