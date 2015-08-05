// Problem4-LargestPalindromeProduct.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <tuple>
#include <string>
#include <iostream>

bool is_palindrome(const std::string& str)
{
	std::string reverseStr = str;
	std::reverse(reverseStr.begin(), reverseStr.end());

	return str.compare(reverseStr) == 0;
}

std::tuple<int, int> FindLargestPalindrome()
{
	int smallestThreeDigit = 100;
	int largestThreeDigit = 999;
	bool found = false;
	std::tuple<int, int> result;	

	for (int firstNumber = largestThreeDigit; firstNumber >= smallestThreeDigit && !found; --firstNumber)
	{
		for (int secondNumber = largestThreeDigit; secondNumber >= smallestThreeDigit && !found; --secondNumber)
		{
			int product = firstNumber * secondNumber;
			
			auto productStr = std::to_string(product);

			if (is_palindrome(productStr))
			{
				result = std::tuple<int, int>(firstNumber, secondNumber);
				found = true;
			}
		}
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	auto result = FindLargestPalindrome();
	auto first = std::get<0>(result);
	auto second = std::get<1>(result);
	std::wcout << " Larget = " << first * second << " ( " << first << " * " << second << " ) " << std::endl;
	return 0;
}

