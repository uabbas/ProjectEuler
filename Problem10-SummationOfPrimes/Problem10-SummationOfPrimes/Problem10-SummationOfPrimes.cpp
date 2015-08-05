// Problem10-SummationOfPrimes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <cstdint>
#include <algorithm>

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

std::vector<uint64_t> get_prime_numbers_to_n(uint64_t n)
{
	std::vector<uint64_t > result;
	if (n > 2)
	{
		result.push_back(2);
	}

	for (int i = 3; ; i = i + 2)
	{
		auto maxPrimeFactorOfi = static_cast<uint64_t>(sqrt(i) + 0.5);

		if (is_prime(i, result.begin(), maxPrimeFactorOfi))
		{			
			result.push_back(i);
			if (i >= n)
			{
				result.pop_back();
				break;
			}
		}
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	auto result = get_prime_numbers_to_n(2000000);
	//for (auto iter = result.begin(); iter != result.end(); ++iter)
	//{
	//	std::wcout << *iter << std::endl;
	//}
	uint64_t sum = 0;
	std::for_each(result.begin(), result.end(), [&sum](uint64_t n){sum += n; });
	std::wcout << _T("SUM = ") << sum << std::endl;
	return 0;

}

