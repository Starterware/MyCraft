#ifndef BENCHMARKS_HPP
#define BENCHMARKS_HPP

#include <iostream>

class Benchmarks
{
public:
	Benchmarks(std::ostream& output_stream) :
		output_stream {&output_stream}
	{}

	virtual void run() = 0;

protected:
	void print_new_line();

protected:
	std::ostream* output_stream;
};

#endif 
