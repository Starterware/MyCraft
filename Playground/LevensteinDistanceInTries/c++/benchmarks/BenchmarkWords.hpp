#ifndef BENCHMARK_WORDS_HPP
#define BENCHMARK_WORDS_HPP

#include <vector>
#include <string>
#include <map>
#include <memory>

class BenchmarkWords
{
public:
	class Words
	{
	public:
		Words();
		std::string at(size_t i);
		size_t size();
	private:
		std::vector<std::string> v;
	};

	class WordsToSearch
	{
	public:
		WordsToSearch();
		std::vector<std::string> &all();
	private:
		std::vector<std::string> v;
	}; 
	
	class WordsToSearchWrongSpelling
	{
	public:
		WordsToSearchWrongSpelling();
		std::map<std::string, std::vector<std::string> >& all();
	private:
		std::map<std::string, std::vector<std::string> > m;
	};

public:
	static const int number_of_words;
	static std::shared_ptr<Words> words;
	static std::shared_ptr<WordsToSearch> words_to_search;
	static std::shared_ptr<WordsToSearchWrongSpelling> words_to_search_wrong_spelling;
};

#endif