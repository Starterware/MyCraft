#ifndef DICTIONARY_BENCHMARKS_BUILDER_HPP
#define DICTIONARY_BENCHMARKS_BUILDER_HPP

#include "DictionaryBenchmarks.hpp"

class DictionaryBenchmarksBuilder
{
public:
	DictionaryBenchmarksBuilder(std::ostream& ofstream);

	DictionaryBenchmarksBuilder& with_small_set();
	DictionaryBenchmarksBuilder& with_normal_set();
	DictionaryBenchmarksBuilder& with_big_set();
	DictionaryBenchmarksBuilder& with_dictionary(std::shared_ptr<Dictionary>& dictionary, std::shared_ptr<StringMetricCalculator>& calculator, const std::string& name);

	std::shared_ptr<DictionaryBenchmarks> build();

protected:
	std::shared_ptr<DictionaryBenchmarks> benchmarks;
};

#endif
