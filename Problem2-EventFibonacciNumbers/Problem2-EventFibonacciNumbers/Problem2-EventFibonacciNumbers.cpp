// Problem2-EventFibonacciNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

namespace
{
	int get_next_fibonacci(int p, int p_1)
	{
		return p + p_1;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int max = 4000000; //4-million
	int fib_i = 1, fib_i_1 = 0;
	int sum = 0;
	while (fib_i <= max)
	{
		int temp = fib_i;
		fib_i = get_next_fibonacci(fib_i, fib_i_1);
		fib_i_1 = temp;
		if (fib_i % 2 == 0)
		{
			sum += fib_i;
		}
	}
	std::wcout << _T("Result = ") << fib_i << std::endl;
	return 0;
}

