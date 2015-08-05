// Problem6-SumSquareDifference.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<int> integers100;

	for (int i = 1; i <= 100; ++i)
	{
		integers100.push_back(i);
	}

	int sumOfSquares = 0;
	int sum = 0;
	std::for_each(
		integers100.begin(), integers100.end(),
		[&sum, &sumOfSquares](int n) {sumOfSquares += n*n; sum += n; });

	int difference = sum*sum - sumOfSquares;
	std::wcout << "Difference = " << difference << std::endl;
	

	return 0;
}

