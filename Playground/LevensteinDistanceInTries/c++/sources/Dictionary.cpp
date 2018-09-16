#include "Dictionary.hpp"

void Dictionary::set_string_metric_calculator(std::shared_ptr<StringMetricCalculator>& calculator)
{
	string_metric_calculator = calculator;
}
