#include <iostream>
#include <memory>
#include "Trie.hpp"
#include "AllBenchmarks.hpp"

int main(int argc, char **argv) 
{
	std::shared_ptr<Benchmarks> benchmarks(new AllBenchmarks(std::cout));
	benchmarks->run();
	system("pause");
	return 0;
}
