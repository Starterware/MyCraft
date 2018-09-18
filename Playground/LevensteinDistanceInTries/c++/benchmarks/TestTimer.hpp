#ifndef TEST_TIMER_HPP
#define TEST_TIMER_HPP

#include <string>
#include <chrono>
#include <iostream>

class TestTimer
{
public:
	TestTimer(const std::string& text, std::ostream& output_stream = std::cout) :
		text{ text },
		start{ std::chrono::system_clock::now() },
		os{ &output_stream }
	{
	}

	~TestTimer()
	{
		end = std::chrono::system_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		*os << "  " << text << ": " << elapsed.count() * 0.001 << " ms" << std::endl;
	}

private:
	std::chrono::time_point<std::chrono::system_clock> start;
	std::chrono::time_point<std::chrono::system_clock> end;
	std::chrono::microseconds elapsed;
	std::ostream* os;
	std::string text;
};

#endif
