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
	searched_word = "";

	m.push_back(std::vector<int>());
	for (int j = 0; j <= this->base_word.length(); j++)
		m[0].push_back(j);
}

void LevensteinDistanceMatrix::pop()
{
	if (m.size() > 1) {
		m.pop_back();
		searched_word.pop_back();
	}
}

void LevensteinDistanceMatrix::clear()
{
	while (m.size() > 1) {
		m.pop_back();
		searched_word.pop_back();
	}
}

void LevensteinDistanceMatrix::push(const char& c)
{
	int row_index = (int)this->m.size();

	searched_word.push_back(c);

	m.push_back(std::vector<int>());
	m[row_index].push_back((int)row_index);

	for (int i = 0; i < this->base_word.length(); i++)
	{
		int subsitution_cost = (base_word[i] == c) ? 0 : 1;
		m[row_index].push_back(std::min(std::min(m[row_index - 1][i] + subsitution_cost, m[row_index - 1][i + 1] + 1), m[row_index][i] + 1));
	}
}

void LevensteinDistanceMatrix::push(const std::string& s)
{
	for (auto& c : s)
		push(c);
}

int LevensteinDistanceMatrix::get_result() const
{
	return m.back().back();
}

std::string LevensteinDistanceMatrix::get_searched_word() const
{
	return searched_word;
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
