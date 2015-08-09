// Problem20-FactorialDigitSum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdint>
#include <vector>
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

uint64_t Factorial(uint64_t n)
{
	uint64_t i = n;
	uint64_t factorialn = 1;
	while (i > 1)
	{
		factorialn *= i;
		--i;
	}
	return factorialn;
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

std::vector<int> FactorialAsDigits(int n)
{
	std::vector<int> digits;

	if (n <= 65)
	{
		uint64_t result = Factorial(n);
		digits = GetDigits(result);
	}
	else
	{
		uint64_t result = Factorial(65);
		digits = GetDigits(result);

		for (int m = 66; m <= n; ++m)
		{
			digits = Multiply(digits, m);
		}
	}

	std::for_each(
		digits.rbegin(),
		digits.rend(),
		[](int n) { std::cout << n; });

	std::cout << std::endl;

	return digits;
}

uint64_t SumofDigits(const std::vector<int>& input)
{
	uint64_t sum = 0;
	std::for_each(
		input.begin(),
		input.end(),
		[&](int n) {sum += n; });

	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	auto result = FactorialAsDigits(100);
	auto sum = SumofDigits(result);
	std::cout << "Sum of digits of 100! = " << sum << std::endl;
}

