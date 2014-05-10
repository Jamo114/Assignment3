#include "CryptoMachine.h"

CryptoMachine::CryptoMachine()
{}


CryptoMachine::~CryptoMachine()
{}

//Removes all spaces and adds a space after every fifth character
std::string CryptoMachine::Group(std::string x)
{
	std::string plainText;
	std::string plainTextTemp;
	plainText = x;
	int i = 0;
	int j = 0;

	plainText.erase(std::remove_if(plainText.begin(), plainText.end(), std::isspace), plainText.end());
	/*
	while (i < plainText.length())
	{
		if (plainText[i] == ' ') plainText.erase(i, 1);
		else ++i;
	}
	*/
	std::transform(plainText.begin(), plainText.end(), plainText.begin(), ::toupper);
	
	//adds in the spaces every 5 characters
	i = 0;
	j = 0;
	int count = 0;
	int newSize = plainText.length() + (plainText.length() / 5);
	plainTextTemp.resize(newSize, ' ');
	while (i < plainText.length())
	{
		if (count == 5)
		{
			plainTextTemp[j] = ' ';
			++j;
			count = 0;
		}
		else
		{
			plainTextTemp[j] = plainText[i];
			++i;
			++j;
			++count;
		}
	}
	plainText = plainTextTemp;
	return plainText;
}
