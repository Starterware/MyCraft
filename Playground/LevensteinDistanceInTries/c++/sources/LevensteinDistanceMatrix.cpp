#include "LevensteinDistanceMatrix.hpp"

#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <sstream>

LevensteinDistanceMatrix::LevensteinDistanceMatrix()
{
	set_base_word("");
}

void LevensteinDistanceMatrix::set_base_word(const std::string & word_to_compare_against)
{
	base_word = word_to_compare_against;

	m.clear();
	compared_word = "";

	m.push_back(std::vector<int>());
	for (int j = 0; j <= this->base_word.length(); j++)
		m[0].push_back(j);
}

void LevensteinDistanceMatrix::pop_last_char_of_compared_word()
{
	if (m.size() > 1) {
		m.pop_back();
		compared_word.pop_back();
	}
}

void LevensteinDistanceMatrix::clear_compared_word()
{
	while (m.size() > 1) {
		m.pop_back();
		compared_word.pop_back();
	}
}

void LevensteinDistanceMatrix::append_char_to_compared_word(const char& c)
{
	int row_index = (int)this->m.size();

	compared_word.push_back(c);

	m.push_back(std::vector<int>());
	m.back().push_back((int)row_index);

	for (auto column_index = 0; column_index < this->base_word.length(); column_index++) 
		m.back().push_back(compute_min_path_cost(row_index, column_index + 1, c));
}

int LevensteinDistanceMatrix::compute_min_path_cost(const int& i, const int& j, const char& c)
{
	int substitution_cost = (base_word[j - 1] == c) ? 0 : 1;
	return std::min(std::min(
		m[i - 1][j -1] + substitution_cost, // substitution 
		m[i - 1][j] + 1), // deletion 
		m[i][j - 1] + 1); //  insertion 
}

void LevensteinDistanceMatrix::append_string_to_compared_word(const std::string& s)
{
	for (auto& c : s)
		append_char_to_compared_word(c);
}

int LevensteinDistanceMatrix::get_result() const
{
	return m.back().back();
}

int LevensteinDistanceMatrix::get_potential_best_result() const
{
	int best = INT32_MAX;
	for (auto& elem : m.back())
		if (elem < best)
			best = elem;
	return best;
}

std::string LevensteinDistanceMatrix::get_compared_word() const
{
	return compared_word;
}

std::string LevensteinDistanceMatrix::to_string()
{
	std::stringstream ss;

	for (auto& row : m) {
		for (auto& cell : row)
			ss << cell << " ";
		ss << std::endl;
	}

	return ss.str();
}
