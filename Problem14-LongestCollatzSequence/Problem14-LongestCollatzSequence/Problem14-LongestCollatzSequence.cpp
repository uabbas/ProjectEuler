// Problem14-LongestCollatzSequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <omp.h>

/*Problem 14:
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.*/

std::vector<int> GetCollatzSequence(int start)
{
	std::vector<int> result;

	int n = start;

	result.push_back(n);

	while (n != 1)
	{
		if (n % 2 == 0)
		{
			n = n / 2;
		}
		else
		{
			n = 3 * n + 1;
		}
		result.push_back(n);
	}
	return result;
}

std::vector<int> LongestCollatzSequenceUnderN(int n)
{
	int size = 0;
	std::vector<int> longest;

//#pragma omp parallel num_threads(4)
	{
		for (int i = n; i >= 2; --i)
		{
			auto result = GetCollatzSequence(i);
			if (result.size() > size)
			{
				longest = result;
				size = result.size();
			}
		}
	}

	return longest;
}

int _tmain(int argc, _TCHAR* argv[])
{	
	auto result = LongestCollatzSequenceUnderN(100000);

	std::for_each(result.begin(), result.end(), [](int n){std::cout << n << " -> "; });
	
	std::cout << "\nSize = " << result.size() << std::endl;
	return 0;
}

