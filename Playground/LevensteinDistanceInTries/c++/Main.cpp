#include <gmock/gmock.h>

#include <iostream>
#include <memory>

#include "benchmarks/AllBenchmarks.hpp"

#define BENCHMARK_OPTION "--benchmarks"

void print_usage(const std::string& program_name) 
{
	size_t slash_index = program_name.find_last_of("\\") + 1;
	std::string name = program_name.substr(slash_index, program_name.find_last_of(".") - slash_index);

	std::cout << name << std::endl;
	std::cout << std::endl;
	std::cout << "\t" << "Runs by default the unit tests." << std::endl;
	std::cout << std::endl;

	std::cout << "Synopsis" << std::endl;
	std::cout << std::endl;
	std::cout << "\t" << name << " [" << BENCHMARK_OPTION << "]" << std::endl;
	std::cout << std::endl;

	std::cout << "Options" << std::endl;
	std::cout << std::endl;
	std::cout << "\t" << BENCHMARK_OPTION << "\t\t" << "Runs the benchmarks" << std::endl;
	std::cout << std::endl;
}

void run_benchmarks()
{
	std::shared_ptr<Benchmarks> benchmarks(new AllBenchmarks(std::cout));
	benchmarks->run();
}

int main(int argc, char **argv) 
{
	int result = 0;

	// required here for VS test adapter in order to find the tests
	testing::InitGoogleMock(&argc, argv);

	switch (argc)
	{
	case 1:
		result = RUN_ALL_TESTS();
		break;
	case 2:
		if (std::string(argv[1]) == BENCHMARK_OPTION)
			run_benchmarks();
		else
			print_usage(argv[0]);
		break;
	default:
		print_usage(argv[0]);
		break;
	}

	system("pause");
	return result;
}
