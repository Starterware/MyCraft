#include "DictionaryBenchmarks.hpp"
#include "BenchmarkWords.hpp"
#include "TestTimer.hpp"
#include "TestSpace.hpp"

#include <sstream>
#include <string>

DictionaryBenchmarks::DictionaryBenchmarks(std::ostream& output_stream) :
	Benchmarks(output_stream)
{
}

void DictionaryBenchmarks::set_dictionary(std::shared_ptr<Dictionary>& dictionary, std::shared_ptr<StringMetricCalculator>& calculator)
{
	this->dictionary = dictionary;
	this->dictionary->set_string_metric_calculator(calculator);
}

void DictionaryBenchmarks::set_name(const std::string & name)
{
	this->name = name;
}

void DictionaryBenchmarks::set_size(int size)
{
	this->size = size;
}

void DictionaryBenchmarks::run()
{
	print_banner();
	run_creation();
	insert_words_for_searches();
	run_search();
	run_search_best_matches();
}

void DictionaryBenchmarks::run_creation()
{
	TestSpace space("Used Memory", *output_stream);
	TestTimer timer("Creation", *output_stream);

	size_t step = BenchmarkWords::words->size() / size;
	for (size_t i = 0; i < BenchmarkWords::words->size(); i += step)
	{
		dictionary->insert(BenchmarkWords::words->at(i));
	}
}

void DictionaryBenchmarks::insert_words_for_searches()
{
	for (auto& word : BenchmarkWords::words_to_search->all())
		dictionary->insert(word);

	for (auto& word_it : BenchmarkWords::words_to_search_wrong_spelling->all())
		for (auto& word : word_it.second)
			dictionary->insert(word);
}

void DictionaryBenchmarks::run_search()
{
	int times = 10000;
	std::stringstream ss;
	ss << "Search (" << times << " times "
		<< BenchmarkWords::words_to_search->all().size() << " findable words and "
		<< BenchmarkWords::words_to_search_wrong_spelling->all().size() << " not found words)";

	TestTimer timer(ss.str(), *output_stream);

	for (int i = 0; i < times; i++) {
		for (auto& word : BenchmarkWords::words_to_search->all())
			if (!dictionary->search(word))
				throw std::exception(std::string("Benchmark failed due to failing search on word: " + word).c_str());

		for (auto& word_it : BenchmarkWords::words_to_search_wrong_spelling->all())
			if (dictionary->search(word_it.first))
				throw std::exception(std::string("Benchmark failed due to succeeding search on word: " + word_it.first).c_str());
	}
}

void DictionaryBenchmarks::run_search_best_matches()
{
	std::stringstream ss;
	ss << "Search best matches (" << BenchmarkWords::words_to_search->all().size() << " words)";

	TestTimer timer(ss.str(), *output_stream);
	for (auto& word_it : BenchmarkWords::words_to_search_wrong_spelling->all())
	{
		std::vector<std::string> matches;
		dictionary->search_best_matches(word_it.first, matches);
		if (matches != word_it.second) 
			throw std::exception(std::string("Unexpected results for search best matches on word " + word_it.first).c_str());
	}
}

void DictionaryBenchmarks::print_banner()
{
	*output_stream << "----- " << name << " estimated times [" << size << " entries]" << " -----" << std::endl << std::endl;
}
