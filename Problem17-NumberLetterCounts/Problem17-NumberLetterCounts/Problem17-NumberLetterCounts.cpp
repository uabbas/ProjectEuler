// Problem17-NumberLetterCounts.cpp : Defines the entry point for the console application.
//

/*Problem 17
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.*/

#include "stdafx.h"
#include <map>
#include <string>
#include <iostream>

namespace
{
	std::map<int, std::string> numberToWord =
	{
		{ 1, "one" },
		{ 2, "two" },
		{ 3, "three" },
		{ 4, "four" },
		{ 5, "five" },
		{ 6, "six" },
		{ 7, "seven" },
		{ 8, "eight" },
		{ 9, "nine" },
		{ 10, "ten" },
		{ 11, "eleven" },
		{ 12, "twelve" },
		{ 13, "thirteen" },
		{ 14, "fourteen" },
		{ 15, "fifteen" },
		{ 16, "sixteen" },
		{ 17, "seventeen" },
		{ 18, "eighteen" },
		{ 19, "nineteen" },
		{ 20, "twenty" },
		{ 30, "thirty" },
		{ 40, "fourty" },
		{ 50, "fifty" },
		{ 60, "sixty" },
		{ 70, "seventy" },
		{ 80, "eighty" },
		{ 90, "ninety" },
		{ 100, "hundred" },
		{ 1000, "thousand" }
	};
}

std::string NumberToWords(int number)
{

	std::string inwords;

	auto nrThousand = number / 1000;
	if (nrThousand >= 1)
	{
		inwords += numberToWord[nrThousand] + numberToWord[1000];
	}

	bool insertAnd = false;
	number = number % 1000;

	auto nrHundred = number / 100;
	if (nrHundred >= 1)
	{
		inwords += numberToWord[nrHundred] + numberToWord[100];
		insertAnd = true;
	}

	number = number % 100;

	auto backUp = number;
	auto nrTen = number / 10;
	if (nrTen >= 1)
	{
		if (insertAnd)
		{
			inwords += "and";
			insertAnd = false;
		}
		if (nrTen == 1)
		{
			inwords += numberToWord[backUp];
		}
		else
		{
			inwords += numberToWord[nrTen * 10];
		}
	}

	if (nrTen == 0 || nrTen > 1)
	{
		number = number % 10;

		auto nrUnit = number;
		if (nrUnit > 0)
		{
			if (insertAnd)
			{
				inwords += "and";
				insertAnd = false;
			}
			inwords += numberToWord[nrUnit];
		}
	}

	return inwords;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int sum = 0;
	for (int i = 1; i <= 1000; ++i)
	{
		auto words = NumberToWords(i);
		sum += words.size();
	}
	std::cout << "Sum = " << sum << std::endl;
	return 0;
}

