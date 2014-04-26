#ifndef CRYPTOMACHINE_H_
#define CRYPTOMACHINE_H_

#include <string>
#include <iostream>
#include <algorithm>
class CryptoMachine
{
public:
	CryptoMachine();
	~CryptoMachine();
	std::string Group(std::string);

	std::string plainText;
};

#endif