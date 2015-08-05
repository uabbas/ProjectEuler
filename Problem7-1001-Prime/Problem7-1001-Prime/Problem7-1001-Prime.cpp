// Problem7-1001-Prime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <cstdint>

bool is_prime(uint64_t  number, std::vector<uint64_t>::const_iterator begin, uint64_t maxValue)
{
	bool result = true;
	for (auto iter = begin; *iter < maxValue; ++iter)
	{
		if (number % *iter == 0)
		{
			result = false;
			break;
		}
	}
	return result;

}

std::vector<uint64_t> get_n_prime_numbers(int n)
{
	std::vector<uint64_t > result;
	int ni = 0;
	if (n > 2)
	{
		result.push_back(2);
		++ni;
	}

	for (int i = 3; ni < n; i = i + 2)
	{
		auto maxPrimeFactorOfi = static_cast<uint64_t>(sqrt(i) + 0.5);
		
		if (is_prime(i, result.begin(), maxPrimeFactorOfi))
		{
			++ni;
			result.push_back(i);
		}
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	auto result = get_n_prime_numbers(10001);
	for (auto iter = result.begin(); iter != result.end(); ++iter)
	{
		std::wcout << *iter << std::endl;		
	}
	return 0;
}

