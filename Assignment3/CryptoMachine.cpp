#include "CryptoMachine.h"

using namespace std;
CryptoMachine::CryptoMachine()
{
}


CryptoMachine::~CryptoMachine()
{
}

//Removes all spaces and adds a space after every fifth character
string CryptoMachine::Group(string x)
{
	plainText = x;
	int i = 0;
	int j = 0;
	while (i < plainText.length())
	{
		if (plainText[i] == ' ') plainText.erase(i, 1);
		else i++;
	}
	i = 0;
	j = 0;
	int count = 0;
	string plainTextTemp;
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
