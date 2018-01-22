/*
	Project Euler Problem X -  
*/

#include "project_euler_environment.hpp"

static map<std::string, int> roman_numbers_map {{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}};
static map<int, std::string> arabic_numbers_map {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};


int convert_to_arabic(std::string roman)
{
	int arabic = 0;

	fori((int)roman.length()) {
		if (i + 1 < (int)roman.length() && roman_numbers_map.find(roman.substr(i, 2)) != roman_numbers_map.end())
			arabic += roman_numbers_map[roman.substr(i++, 2)];
		else
			arabic += roman_numbers_map[roman.substr(i, 1)];
	}

	return arabic;
}

std::string convert_to_roman(int arabic)
{
	std::string roman = "";

	for (auto rit = arabic_numbers_map.rbegin(); rit != arabic_numbers_map.rend(); ++rit)
		for (; arabic - rit->first >= 0; arabic -= rit->first)
			roman += rit->second;

	return roman;
}

int difference(std::string roman)
{
	int size = roman.length();
	int arabic = convert_to_arabic(roman);
	return size - convert_to_roman(arabic).length();
}

ll run()
{
	int count = 0;
	std::string number;

	fori(1000) {
		cin >> number;
		count += difference(number);
	}

	return count;
}

int main()
{
	cout << "Solution: " << run() << endl;
	return 0;
}
