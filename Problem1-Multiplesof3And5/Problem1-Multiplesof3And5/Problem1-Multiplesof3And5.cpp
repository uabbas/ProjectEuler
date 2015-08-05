// Problem1-Multiplesof3And5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

namespace
{
	bool is_multiple_of(int number, int multiple)
	{
		return number % multiple == 0;
	}

	template<int number, int multiple> 
	bool is_multiple_of()
	{
		return number % multiple == 0;
	}
	
	
}

template <class Type, int N>
class IsMultiple
{
public:
	IsMultiple()
	{

	}

	bool operator()(const Type& number) const
	{
		return number % N == 0;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	int result = 0;
	for (auto i = 1; i <= 1000; ++i)
	{

		if (is_multiple_of(i, 3) || is_multiple_of(i, 5))
		{
			result += i;
			
		}
	}
	std::wcout << _T(" TOTAL : ") << result << std::endl;
	return 0;
}



