// Problem19-CountingSundays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <cstdint>
#include <iostream>
#include <map>
#include <string>

/*

Problem 19:

You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

*/

namespace
{
	std::map<int, std::string> WDayMap =
	{
		{ 0, "Sunday" },
		{ 1, "Monday" },
		{ 2, "Tuesday" },
		{ 3, "Wednesday" },
		{ 4, "Thursday" },
		{ 5, "Friday" },
		{ 6, "Saturday" }
	};
}


int GetY(int mm, int yyyy)
{
	if (mm == 1 || mm == 2)
	{
		return yyyy - 1;
	}
	return yyyy;
}

std::vector<int> GetDigits(int number)
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

void Getyc(int yyyy, int& y, int& c)
{
	auto digits = GetDigits(yyyy);
	
	y = 0; // last 2-digits
	c = 0; // first 2-digits

	while (digits.size() < 4)
	{
		digits.push_back(0);
	}

	c = digits[3] * 10 + digits[2];
	y = digits[1] * 10 + digits[0];
}

int Getm(int mm)
{
	int m = mm - 2;
	if (m < 0)
	{
		return m + 12;
	}
	return m;
}



int GetDay(int dd, int mm, int yyyy)
{
	/*
	https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
	Disparate variation

	Another variation of the above algorithm likewise works with no lookup tables. A slight disadvantage is the unusual month and year counting convention. The formula is

	w = (d + \lfloor 2.6m - 0.2 \rfloor + y + \left\lfloor\frac{y}{4}\right\rfloor + \left\lfloor\frac{c}{4}\right\rfloor - 2c) \bmod 7,

	where

	Y is the year minus 1 for January or February, and the year for any other month
	y is the last 2 digits of Y
	c is the first 2 digits of Y
	d is the day of the month (1 to 31)
	m is the shifted month (March=1,...,February=12)
	w is the day of week (0=Sunday,...,6=Saturday)
	*/

	auto Y = GetY(mm, yyyy);
	int y = 0, c = 0;
	Getyc(Y, y, c);
	int m = Getm(mm);

	double w1 = (dd + std::floor(2.6*m - 0.2) + y + std::floor(y * 0.25) + std::floor(c * 0.25) - 2 * c);
	int w = static_cast<int>(w1) % 7;

	//std::cout << WDayMap[w] << std::endl;
	return w;
}

int CountSundaysOnFirstOfMonth()
{
	int yearStart = 1901;
	int yearEnd = 2000;
	int nrSundays = 0;

	for (int yyyy = yearStart; yyyy <= yearEnd; ++yyyy)
	{
		for (int mm = 1; mm <= 12; ++mm)
		{
			if (GetDay(1, mm, yyyy) == 0)
			{
				++nrSundays;
			}
		}
	}
	return nrSundays;
}


int _tmain(int argc, _TCHAR* argv[])
{
	/*GetDay(1, 1, 2000);
	GetDay(31, 12, 2000);*/
	std::cout << "Number of Sundays on the first of a month between 1-Jan-1901 and 31-Dec-2000 are : " << CountSundaysOnFirstOfMonth() << std::endl;
	return 0;
}

