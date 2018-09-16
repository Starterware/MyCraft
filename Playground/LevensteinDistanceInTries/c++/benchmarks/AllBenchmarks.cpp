#include "AllBenchmarks.hpp"
#include "DictionaryBenchmarksBuilder.hpp"

#include "Set.hpp"
#include "Trie.hpp"
#include "RecursiveTrie.hpp"
#include "LevensteinDistanceMatrix.hpp"

AllBenchmarks::AllBenchmarks(std::ostream& output_stream) :
	Benchmarks(output_stream)
{
}

void AllBenchmarks::run()
{
	run_dictionary_benchmarks(std::shared_ptr<Dictionary>(new Set()), std::shared_ptr<StringMetricCalculator>(new LevensteinDistanceMatrix), "Set Dictionary");
	run_dictionary_benchmarks(std::shared_ptr<Dictionary>(new Trie()), std::shared_ptr<StringMetricCalculator>(new LevensteinDistanceMatrix), "Trie Dictionary");
	run_dictionary_benchmarks(std::shared_ptr<Dictionary>(new RecursiveTrie()), std::shared_ptr<StringMetricCalculator>(new LevensteinDistanceMatrix), "Recursive Trie Dictionary");
}

void AllBenchmarks::run_dictionary_benchmarks(std::shared_ptr<Dictionary>& dictionary, std::shared_ptr<StringMetricCalculator>& calculator, const std::string& name)
{
	print_banner(name);
	DictionaryBenchmarksBuilder(*output_stream).with_dictionary(dictionary, calculator, name).with_small_set().build()->run();
	print_new_line();
	DictionaryBenchmarksBuilder(*output_stream).with_dictionary(dictionary, calculator, name).with_normal_set().build()->run();
	print_new_line();
	DictionaryBenchmarksBuilder(*output_stream).with_dictionary(dictionary, calculator, name).with_big_set().build()->run();
	print_new_line();
	print_banner(name);
}

void AllBenchmarks::print_banner(const std::string& name)
{
	*output_stream << "=========== " << name << " benchmark tests ===========" << std::endl << std::endl;
}