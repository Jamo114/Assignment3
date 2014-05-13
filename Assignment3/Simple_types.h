#ifndef _SIMPLE_TYPES_H
#define _SIMPLE_TYPES_H

#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>


class Vignere
{
public:
	std::string key;
	void setKey(std::string x)
	{
		key = x;
	}
};

class Xor
{
public:
	std::string key;
	void setKey(std::string x)
	{
		key = x;
	}
};

class ECB
{};

class CBC
{};

class Grouping
{
public:
	void group(std::string &plainText)
	{
		std::transform(plainText.begin(), plainText.end(), plainText.begin(), ::toupper);

		plainText.erase(
			std::remove_if(plainText.begin(), plainText.end(), ::isspace),
			plainText.end());

		std::string temp;
		//adds in the spaces every 5 characters
		unsigned int i = 0;
		int j = 0;
		int count = 0;
		int newSize = plainText.length() + (plainText.length() / 5);
		temp.resize(newSize, ' ');
		while (i < plainText.length())
		{
			if (count == 5)
			{
				temp[j] = ' ';
				++j;
				count = 0;
			}
			else
			{
				temp[j] = plainText[i];
				++i;
				++j;
				++count;
			}
		}
		plainText = temp;
	}	
};

class Pack
{};
#endif