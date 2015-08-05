// Problem3-LargestPrimeFactor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <cstdint>

bool is_prime(uint64_t  number, const std::vector<uint64_t >& factorsToTest)
{
	bool result = true;
	for (auto iter = factorsToTest.begin(); iter != factorsToTest.end(); ++iter)
	{		
		if (number % *iter == 0)
		{
			result = false;
			break;
		}		
	}
	return result;
	
}

std::vector<uint64_t> get_less_than(std::vector<uint64_t> input, uint64_t number)
{
	std::vector<uint64_t> result;
	for (auto iter = input.begin(); iter != input.end(); ++iter)
	{
		if (*iter <= number)
		{
			result.push_back(*iter);
		}
	}
	return result;
}

std::vector<uint64_t> get_prime_numbers_to_test(uint64_t  number)
{
	std::vector<uint64_t > result;
	if (number > 2)
	{
		result.push_back(2);
	}

	auto maxPrime = static_cast<uint64_t >(sqrt(number) + 0.5);

	for (int i = 3; i <= maxPrime; i = i + 2)
	{
		auto maxi = static_cast<uint64_t>(sqrt(i) + 0.5);
	//	if (is_prime(i, get_prime_numbers_to_test(static_cast<uint64_t >(sqrt(i) + 0.5))))
		if (is_prime(i, get_less_than(get_prime_numbers_to_test(maxi), maxi)))
		{
			result.push_back(i);
		}
	}
	return result;
}

void get_prime_factors(uint64_t  n, std::vector<uint64_t >& primeFactors)
{
	auto primeNumbers = get_prime_numbers_to_test(n);

	auto iter = primeNumbers.begin();
	for ( ; iter != primeNumbers.end(); ++iter)
	{
		if (n % *iter == 0)
		{
			primeFactors.push_back(*iter);

			get_prime_factors(n / *iter, primeFactors);
			break;
		}
	}

	if (iter == primeNumbers.end())
	{
		primeFactors.push_back(n);
	}
}

std::vector<uint64_t > get_prime_factors(uint64_t  n)
{
	std::vector<uint64_t > primeFactors;

	get_prime_factors(n, primeFactors);

	return primeFactors;
}



int _tmain(int argc, _TCHAR* argv[])
{
	auto primeFactors = get_prime_factors(600851475143);

	auto max = *primeFactors.begin();
	for (auto iter = primeFactors.begin(); iter != primeFactors.end(); ++iter)
	{
		std::wcout << *iter << std::endl;
		if (max < *iter)
		{
			max = *iter;
		}
	}
	std::wcout << _T("Maximum = ") << max << std::endl;



	return 0;
}

