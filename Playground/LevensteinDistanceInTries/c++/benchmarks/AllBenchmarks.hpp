#ifndef ALL_BENCHMARKS_HPP
#define ALL_BENCHMARKS_HPP

#include "Benchmarks.hpp"
#include "Dictionary.hpp"

#include <memory>

class AllBenchmarks : public Benchmarks
{
public:
	AllBenchmarks(std::ostream& output_stream);	
	
	void run();

private:
	void run_dictionary_benchmarks(std::shared_ptr<Dictionary>& dictionary, const std::string& name);
	void print_banner(const std::string& name);
};

#endif 
