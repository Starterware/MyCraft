#include "AllBenchmarks.hpp"
#include "DictionaryBenchmarksBuilder.hpp"

#include "Set.hpp"
#include "Trie.hpp"
#include "RecursiveTrie.hpp"

AllBenchmarks::AllBenchmarks(std::ostream& output_stream) :
	Benchmarks(output_stream)
{
}

void AllBenchmarks::run()
{
	run_dictionary_benchmarks(std::shared_ptr<Dictionary>(new Set()), "Set Dictionary");
	run_dictionary_benchmarks(std::shared_ptr<Dictionary>(new Trie()), "Trie Dictionary");
	run_dictionary_benchmarks(std::shared_ptr<Dictionary>(new RecursiveTrie()), "Recursive Trie Dictionary");
}

void AllBenchmarks::run_dictionary_benchmarks(std::shared_ptr<Dictionary>& dictionary, const std::string& name)
{
	print_banner(name);
	DictionaryBenchmarksBuilder(*output_stream).with_dictionary(dictionary, name).with_LV().with_small_set().build()->run();
	print_new_line();
	DictionaryBenchmarksBuilder(*output_stream).with_dictionary(dictionary, name).with_LV().with_normal_set().build()->run();
	print_new_line();
	DictionaryBenchmarksBuilder(*output_stream).with_dictionary(dictionary, name).with_LV().with_big_set().build()->run();
	print_new_line();
	print_banner(name);
}

void AllBenchmarks::print_banner(const std::string& name)
{
	*output_stream << "=========== " << name << " benchmark tests ===========" << std::endl << std::endl;
}