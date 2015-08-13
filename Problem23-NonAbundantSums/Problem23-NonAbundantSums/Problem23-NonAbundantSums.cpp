// Problem23-NonAbundantSums.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <set>
/*


A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

*/

std::vector<int> GetDivisors(int n)
{
	std::vector<int> divisors;
	divisors.push_back(1);

	for (int d = 2; d <= n / 2; ++d)
	{
		if (n % d == 0)
		{
			divisors.push_back(d);
		}
	}
	return divisors;
}

bool IsAbundant(int n)
{
	const auto& divisors = GetDivisors(n); 

	int sum = 0;
	for (const auto& divisor : divisors)
		sum += divisor;

	return (sum > n);
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int max = 28123;
	std::vector<int> abudantNumbers;
	std::set<int> result;
	
	

	for (int i = 2; i <= max; ++i)
	{
		if (IsAbundant(i))
		{
			abudantNumbers.push_back(i);
		}
	}

	
	std::set<int>::size_type numberOfAbundantNumbers = abudantNumbers.size();

	for (int i = 2; i <= max; ++i)
	{
		if ((i % 2 == 0) && IsAbundant(i / 2))
		{
			//std::cout << i << " = " << i / 2 << " + " << i / 2 << std::endl;
			continue;
		}
		else
		{
			result.insert(i);
			for (std::set<int>::size_type j = 0; j < abudantNumbers.size(); ++j)
			{
				int first = abudantNumbers[j];
				int second = i - first;

				if (second < abudantNumbers[0])
				{
					// concluded: CANNOT be expressed as sum of two abudant numbers
					break; 
				}
				if (second <= abudantNumbers[numberOfAbundantNumbers - 1])
				{
					if (std::find(abudantNumbers.begin(), abudantNumbers.end(), second) != abudantNumbers.end())
					{
						// concluded: CAN be expressed as sum of two abudant numbers
						//std::cout << i << " = " << first << " + " << second << std::endl;			
						result.erase(i);
						break;
					}
				}

			}
		}
	}

	int sum = 0;
	for (const auto& element : result)	
		sum += element;	

	std::cout << sum << std::endl;

	return 0;
}

