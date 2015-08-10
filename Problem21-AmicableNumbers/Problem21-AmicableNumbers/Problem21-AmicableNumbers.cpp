// AmicableNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <tuple>
#include <iostream>
#include <vector>
#include <map>

/*
Problem 21
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

*/

namespace
{
	std::map<int, int>  AmicableNumbers = {};
}

int SumOfElements(std::vector<int> elements)
{
	int sum = 0;
	for (auto& element : elements)
	{
		sum += element;
	}
	return sum;
}

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
bool CheckAmicability(int n, int& secondNumber)
{
	auto firstDivisors = GetDivisors(n);
	secondNumber = SumOfElements(firstDivisors);
	auto secondDivisors = GetDivisors(secondNumber);
	auto firstNumber = SumOfElements(secondDivisors);

	bool amicable = ((firstNumber == n) && (firstNumber != secondNumber));
	if (amicable)
	{
		std::cout << firstNumber << " and " << secondNumber << " are amicable!" << std::endl;
	}
	return (amicable);
}

void FindAmicableNumbers()
{
	for (int i = 2; i <= 10000; ++i)
	{
		if (AmicableNumbers.find(i) == AmicableNumbers.end())
		{
			int secondNumber = 0;
			if (CheckAmicability(i, secondNumber))
			{
				AmicableNumbers[i] = secondNumber;
				AmicableNumbers[secondNumber] = i;
			}
		}
	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	FindAmicableNumbers();

	int sum = 0;
	for (auto& amicable : AmicableNumbers)
	{
		sum += amicable.first;
	}
	std::cout << "Total Sum = " << sum << std::endl;
	return 0;
}


