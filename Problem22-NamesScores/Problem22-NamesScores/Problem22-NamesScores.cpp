// Problem22-NamesScores.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <boost\tokenizer.hpp>
#include <cstdint>
/*

Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/


std::vector<std::string> GetNames()
{
	std::string line;
	std::ifstream namesFile("..\\names.txt");	
	std::vector<std::string> names;

	if (namesFile.is_open())
	{
		std::getline(namesFile, line);

		typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
		boost::char_separator<char> sep{ "\"," };
		tokenizer tok{ line, sep };

		for (const auto &t : tok)
		{
			names.push_back(t);
		}
		std::sort(names.begin(), names.end());
		namesFile.close();
	}
	return names;
}

int GetValue(const std::string& name)
{
	int value = 0;
	for (const auto& c : name)
	{
		int valueOfc = (int)c - (int)'A' + 1;
		value += valueOfc;
	}
	return value;
}

int _tmain(int argc, _TCHAR* argv[])
{
	auto names = GetNames();
	uint64_t totalScore = 0;
	for (int i = 0; i < names.size(); ++i)
	{
		const auto& name = names[i];
		int value = GetValue(name);
		int score = value * (i + 1);
		totalScore += score;
	}

	std::cout << names.size() << " names in total!" << std::endl;
	std::cout << "Total score: "<< totalScore << std::endl;

	return 0;
}

