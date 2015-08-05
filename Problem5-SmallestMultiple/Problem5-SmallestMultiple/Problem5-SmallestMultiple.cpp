// Problem5-SmallestMultiple.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <cstdint>

uint64_t  SmallestMultiple(uint64_t number1, uint64_t number2)
{
	uint64_t  biggerNumber = std::max(number1, number2);
	uint64_t  otherNumber = biggerNumber == number1 ? number2 : number1;

	uint64_t  multiple = 2;	
	uint64_t  lcm = biggerNumber;
	
	while (lcm % otherNumber != 0)
	{
		lcm = biggerNumber * multiple;
		++multiple;
	}
	return lcm;
}

template<uint64_t  n>
uint64_t  SmallestMultiple(const std::array<uint64_t , n>& elements)
{
	auto iter = elements.begin();
	uint64_t  lcm = 1;
	
	while (iter != elements.end())
	{
		lcm = SmallestMultiple(lcm, *iter);
		++iter;
	}
	return lcm;
}

int _tmain(uint64_t  argc, _TCHAR* argv[])
{
	std::array<uint64_t, 20> elements = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	std::sort(elements.begin(), elements.end(), [](uint64_t  i, uint64_t  j) { return i > j; });
	auto lcm = SmallestMultiple(elements);

	std::wcout << "LCM = " << lcm << std::endl;

	return 0;
}

