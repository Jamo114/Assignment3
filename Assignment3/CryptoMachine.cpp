#include "CryptoMachine.h"

CryptoMachine::CryptoMachine(std::string key, std::string plainText)
{
	this->key = key;
	this->plainText = plainText;
}


CryptoMachine::~CryptoMachine()
{}

void CryptoMachine::Encode()
{
	plainText.erase(
		std::remove_if(plainText.begin(), plainText.end(), std::isspace),
		plainText.end());

	std::transform(plainText.begin(), plainText.end(), plainText.begin(), ::toupper);

	Group(plainText);

}

void CryptoMachine::Decode()
{
	plainText.erase(
		std::remove_if(plainText.begin(), plainText.end(), std::isspace),
		plainText.end());

	std::transform(plainText.begin(), plainText.end(), plainText.begin(), ::toupper);

	Group(plainText);

}


//Removes all spaces and adds a space after every fifth character
void CryptoMachine::Group(std::string& x)
{
	std::string temp;
	//adds in the spaces every 5 characters
	int i = 0;
	int j = 0;
	int count = 0;
	int newSize = x.length() + (x.length() / 5);
	temp.resize(newSize, ' ');
	while (i < x.length())
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
	x = temp;
}
