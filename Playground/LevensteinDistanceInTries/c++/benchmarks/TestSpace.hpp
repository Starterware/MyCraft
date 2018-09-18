#ifndef TEST_SPACE_HPP
#define TEST_SPACE_HPP

#include <windows.h>
#include <psapi.h>
#include <string>
#include <iostream>

class TestSpace 
{
public:
	TestSpace(const std::string& text, std::ostream& output_stream = std::cout) :
		text{ text },
		os{ &output_stream }
	{
		PROCESS_MEMORY_COUNTERS_EX pmc;
		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
		start_used_memory = pmc.PrivateUsage; 
	}

	~TestSpace()
	{
		PROCESS_MEMORY_COUNTERS_EX pmc;
		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
		double used_memory_kb = (pmc.PrivateUsage - start_used_memory) / 1024.0;
		*os << "  " << text << ": " << used_memory_kb << " kB" << std::endl;
	}

private:
	size_t start_used_memory;
	std::ostream* os;
	std::string text;
};

#endif
