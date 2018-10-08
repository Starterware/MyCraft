#include "DictionaryBenchmarksBuilder.hpp"
#include "BenchmarkWords.hpp"
#include "LevensteinDistanceMatrix.hpp"

DictionaryBenchmarksBuilder::DictionaryBenchmarksBuilder(std::ostream& ostream)
{
	benchmarks = std::shared_ptr<DictionaryBenchmarks>(new DictionaryBenchmarks(ostream));
}

DictionaryBenchmarksBuilder& DictionaryBenchmarksBuilder::with_small_set()
{
	benchmarks->set_size(BenchmarkWords::number_of_words / 100);
	return *this;
}

DictionaryBenchmarksBuilder& DictionaryBenchmarksBuilder::with_normal_set()
{
	benchmarks->set_size(BenchmarkWords::number_of_words / 10);
	return *this;
}

DictionaryBenchmarksBuilder& DictionaryBenchmarksBuilder::with_big_set()
{
	benchmarks->set_size(BenchmarkWords::number_of_words);
	return *this;
}

DictionaryBenchmarksBuilder& DictionaryBenchmarksBuilder::with_dictionary(std::shared_ptr<Dictionary>& dictionary, const std::string& name)
{
	benchmarks->set_name(name);
	benchmarks->set_dictionary(dictionary);
	return *this;
}

DictionaryBenchmarksBuilder& DictionaryBenchmarksBuilder::with_LV()
{
	benchmarks->set_calculator(std::shared_ptr<StringMetricCalculator>(new LevensteinDistanceMatrix));
	return *this;
}

std::shared_ptr<DictionaryBenchmarks> DictionaryBenchmarksBuilder::build()
{
	return benchmarks;
}
