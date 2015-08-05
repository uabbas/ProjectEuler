// Problem9-SpecialPythagoreanTriplet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <tuple>
#include <algorithm>
#include <array>
#include <iostream>
#include <cstdint>

bool IsPerfectSquare(uint64_t n, uint64_t sqrtn)
{
	bool result = false;
	std::array<int, 7> residues = { 0, 1, 4, 9, 16, 17, 25 };

	uint64_t residue = (n % 32);

	if (std::find(residues.begin(), residues.end(), residue) != -1)
	{
		result = (n == sqrtn * sqrtn);
	}
	return result;
}


std::tuple<uint64_t, uint64_t, uint64_t> FindPythogoreanTriplet()
{
	bool found = false;
	std::tuple<uint64_t, uint64_t, uint64_t> result;
	uint64_t i = 1;
	uint64_t j = 1;
 
	for (i = 1; i < 1000; ++i)
	{
		for (j = 1; j < 1000; ++j)
		{
			int k = i*i + j*j;

			if (i + j + k >= 1000)
			{
				auto sqrtk = std::llroundl(std::sqrt(k));

				if (IsPerfectSquare(k, sqrtk))
				{
					std::cout << "Evaluating .. " << i << " " << j << " " << k << std::endl;
					if (i + j + sqrtk == 1000)
					{
						found = true;
						result = std::tuple<uint64_t, uint64_t, uint64_t>(i, j, sqrtk);
						break;
					}

				}
			}
		}
	}
	return result;
}


int _tmain(int argc, _TCHAR* argv[])
{
	auto result = FindPythogoreanTriplet();
	std::wcout << std::get<0>(result) << " " << std::get<1>(result) << " " << " " << std::get<2>(result) << std::endl;
	
	return 0;

}

