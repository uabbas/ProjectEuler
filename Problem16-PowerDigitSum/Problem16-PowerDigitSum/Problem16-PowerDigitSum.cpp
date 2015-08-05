// Problem16-PowerDigitSum.cpp : Defines the entry point for the console application.
//
/*Problem 16
215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 21000?*/
#include "stdafx.h"
#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> GetDigits(uint64_t number)
{
	auto i = number;
	std::vector<int> result;

	while (i > 0)
	{			
		result.push_back(i % 10);
		i = i / 10;
	}
	return result;
}

std::vector<int> Multiply(std::vector<int> digits, uint64_t number)
{
	uint64_t carry = 0;
	std::vector<int> result;
	for (auto digit : digits)
	{
		auto product = digit * number + carry;
		result.push_back(product % 10);
		carry = product / 10;
	}
	auto carryDigits = GetDigits(carry);
	for (auto carryDigit : carryDigits)
	{
		result.push_back(carryDigit);
	}
	return result;
}

std::vector<int> ComputePower(uint64_t x, uint64_t y)
{	
	auto number = static_cast<uint64_t>(pow(2, 32));
	std::vector<int> result;

	auto numberOfMultiplications = (y - 1) / 32;
	auto digits = GetDigits(x);

	if (numberOfMultiplications > 1)
	{
		uint64_t carry = 0;
		for (int i = 0; i < numberOfMultiplications; ++i)
		{
			auto currentResult = Multiply(digits, number);
			digits = currentResult;
		}
	}

	auto remaining = (y - 1) - numberOfMultiplications * 32;

	if (remaining >= 0)
	{
		result = Multiply(digits, static_cast<uint64_t>(pow(2, remaining)));
	}
	return result;
}




int _tmain(int argc, _TCHAR* argv[])
{
	auto result = ComputePower(2, 1000);
	uint64_t sum = 0;
	std::for_each(result.rbegin(), result.rend(), [&sum](int resultDigit)
	{
		std::cout << resultDigit;
		sum += resultDigit;
	});
	std::cout << std::endl;

	std::cout << "Sum = " << sum << std::endl;
	return 0;
}

