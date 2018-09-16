#ifndef DICTIONARY_BENCHMARKS_HPP
#define DICTIONARY_BENCHMARKS_HPP

#include "Benchmarks.hpp"
#include "Dictionary.hpp"

#include <memory>

class DictionaryBenchmarks : public Benchmarks
{
public:
	DictionaryBenchmarks(std::ostream& output_stream);

	void set_dictionary(std::shared_ptr<Dictionary>& dictionary, std::shared_ptr<StringMetricCalculator>& calculator);
	void set_name(const std::string& name);
	void set_size(int size);

	void run();

private:
	void run_creation();
	void run_search();
	void run_search_best_matches();
	void print_banner();

protected:
	void insert_words_for_searches();

protected:
	std::shared_ptr<Dictionary> dictionary;
	std::string name;
	int size;
};

#endif
