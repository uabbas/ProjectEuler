// Project15-LatticePaths.cpp : Defines the entry point for the console application.
//
/* Problem 15:
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, 
there are exactly 6 routes to the bottom right corner.


How many such routes are there through a 20×20 grid?*/


#include "stdafx.h"
#include <iostream>
#include <cstdint>
#include <stack>
#include <utility>
#include <tuple>

void NumberOfRoutesFromHere(int x, int y, int size, bool prevBranched, uint64_t& nrRoutes)
{
	bool currentBranched = false;
	
	if ((x + 1 < size) && (y + 1 < size))
	{
		nrRoutes += prevBranched ? 1 : 2;
		currentBranched = true;
	}

	if (x + 1 < size)
	{		
		NumberOfRoutesFromHere(x + 1, y, size, currentBranched, nrRoutes);
	}

	if (y + 1 < size)
	{
		NumberOfRoutesFromHere(x, y + 1, size, currentBranched, nrRoutes);
	}
}

uint64_t CalculateLatticePaths(int size)
{
	uint64_t nrRoutes = 0;

	NumberOfRoutesFromHere(0, 0, size, false, nrRoutes);

	return nrRoutes;
}

int _tmain(int argc, _TCHAR* argv[])
{
	auto result = CalculateLatticePaths(20);
	std::cout << "Lattice Paths = " << result << std::endl;
	return 0;
}

