// Problem24-LexicographicPermutations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <tuple>
#include <map>
#include <queue>
#include <ctime>

/*

Problem 24

A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

*/


std::vector<std::vector<int>> GetCombinations(const std::vector<int>& input)
{
	if (input.size() == 1)
	{
		return { input };
	}
	if (input.size() == 2)
	{
		return 
		{
			{input[0], input[1]},
			{input[1], input[0]}
		};
	}

	std::vector<std::vector<int>> result;
	for (const auto& element : input)
	{
		std::vector<int> diffSet = input;
		diffSet.erase(std::find(diffSet.begin(), diffSet.end(), element));

		auto& arrangements = GetCombinations(diffSet);
		for (auto& arrangement : arrangements)
		{
			arrangement.insert(arrangement.begin(), element);
			result.push_back(arrangement);
		}
	}
	return result;
}

std::vector<std::vector<int>> GetCombinationsIterative(const std::vector<int>& input)
{
	typedef std::vector<std::vector<int>> ResultType;
	typedef std::vector<int> InputType;
	typedef std::vector<std::tuple<int, InputType>> ProblemType;
	typedef std::map<int, ProblemType> ProblemListType;
	typedef std::queue<InputType> LevelResultsType;

	ResultType result;
	
	ProblemListType problemTree;

	int currentLevel = input.size();
	int startLevel = currentLevel;
	problemTree[currentLevel] = ProblemType
	{ 
		std::tuple<int, InputType> {0, input}
	};
	InputType temp = input;
	int nodeNr = 1;
	while (currentLevel > 2)
	{
		problemTree[currentLevel - 1] = ProblemType{};
		const auto& nodes = problemTree[currentLevel];
		for (const auto& node : nodes)
		{
			temp = std::get<1>(node);
			for (const auto& element : temp)
			{
				std::vector<int> diffSet = temp;
				diffSet.erase(std::find(diffSet.begin(), diffSet.end(), element));
				problemTree[currentLevel - 1].push_back(std::make_tuple(element, diffSet));
			}
		}
		currentLevel = currentLevel - 1;
	}

	LevelResultsType resultsCurrentLevel;
	LevelResultsType resultsPreviousLevel;
	
	while (currentLevel < startLevel)
	{
		resultsCurrentLevel = {};
		const auto& nodes = problemTree[currentLevel];
		int partitionSize = currentLevel == 2 ? 2 : resultsPreviousLevel.size() / nodes.size();
		for (const auto& node : nodes)
		{
			temp = std::get<1>(node);
			if (temp.size() == 2)
			{
				resultsPreviousLevel.push({ temp[0], temp[1] });
				resultsPreviousLevel.push({ temp[1], temp[0] });
			}
			for (int i = 0; i < partitionSize ; ++i)
			{
				auto& previousLevelResult = resultsPreviousLevel.front();
				previousLevelResult.insert(previousLevelResult.begin(), std::get<0>(node));
				resultsCurrentLevel.push(resultsPreviousLevel.front());
				resultsPreviousLevel.pop();
			}
		}
		resultsPreviousLevel = resultsCurrentLevel;
		++currentLevel;
	}

	while (!resultsCurrentLevel.empty())
	{
		result.push_back(resultsCurrentLevel.front());
		resultsCurrentLevel.pop();
	}

	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<int> input = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	clock_t begin = clock();
	auto result = GetCombinations(input);
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << elapsed_secs << std::endl;
	std::cout << "1 millions lexicographic permutation is :" ;
	const auto& oneMilliont = result[1000000];
	for (const auto& digit : oneMilliont)
	{
		std::cout << digit << " , ";
	}	
	std::cout << "\nTotal number of permutations is " << result.size() << std::endl;

	return 0;
}

