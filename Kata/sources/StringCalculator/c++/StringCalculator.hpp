#ifndef STRING_CALCULATOR_HPP
#define STRING_CALCULATOR_HPP

#ifdef KATA_BUILD	
	#ifdef WIN32
		#define UTIL_DECLSPEC __declspec(dllexport)
	#else
		#define UTIL_DECLSPEC __attribute__((visibility("default")))
	#endif
#else
	#ifdef WIN32
		#define UTIL_DECLSPEC __declspec(dllimport)
	#else
		#define UTIL_DECLSPEC
	#endif
#endif

#include <string>

class StringCalculator
{
public: 
	int addition(std::string formatted_naturals);
};

#endif
