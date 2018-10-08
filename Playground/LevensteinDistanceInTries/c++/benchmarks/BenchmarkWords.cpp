#include "BenchmarkWords.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

const int BenchmarkWords::number_of_words = 466544;
std::shared_ptr<BenchmarkWords::Words> BenchmarkWords::words = std::shared_ptr<BenchmarkWords::Words> (new BenchmarkWords::Words());
std::shared_ptr<BenchmarkWords::WordsToSearch> BenchmarkWords::words_to_search = std::shared_ptr<BenchmarkWords::WordsToSearch> (new BenchmarkWords::WordsToSearch());
std::shared_ptr<BenchmarkWords::WordsToSearchWrongSpelling> BenchmarkWords::words_to_search_wrong_spelling = std::shared_ptr<BenchmarkWords::WordsToSearchWrongSpelling>(new BenchmarkWords::WordsToSearchWrongSpelling());

static std::ifstream open_file(const std::string& file_name)
{
	std::ifstream file;
	file.open(file_name);
	if (!file) {
		std::cerr << "Unable to open file " << file_name;
		exit(1);
	}
	return file;
}

BenchmarkWords::Words::Words()
{
	std::ifstream file = open_file("data/words.txt");
	
	for (std::string line; std::getline(file, line); )
		v.push_back(line);

	file.close();
}

std::string BenchmarkWords::Words::at(size_t i)
{
	if (i >= v.size())
		return "";
	return v[i];
}

size_t BenchmarkWords::Words::size()
{
	return v.size();
}

BenchmarkWords::WordsToSearch::WordsToSearch()
{
	std::ifstream file = open_file("data/words_to_search.txt");

	for (std::string line; std::getline(file, line); )
		v.push_back(line);

	file.close();
}

std::vector<std::string> &BenchmarkWords::WordsToSearch::all()
{
	return v;
}

BenchmarkWords::WordsToSearchWrongSpelling::WordsToSearchWrongSpelling()
{
	std::ifstream file = open_file("data/words_to_search_wrong_spelling.txt");

	for (std::string line; std::getline(file, line); )
	{
		std::string key; 
		std::istringstream iss(line);
		iss >> key;

		m[key] = std::set<std::string>();

		while (!iss.eof()) {
			std::string value;
			iss >> value;
			m[key].insert(value);
		}
	}
}

std::map<std::string, std::set<std::string>>& BenchmarkWords::WordsToSearchWrongSpelling::all()
{
	return m;
}
