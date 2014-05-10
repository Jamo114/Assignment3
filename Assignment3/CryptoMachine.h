#ifndef CRYPTOMACHINE_H_
#define CRYPTOMACHINE_H_

#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

class CryptoMachine
{
public:
	CryptoMachine(std::string, std::string);
	~CryptoMachine();
	void Encode();
	void Decode();
	void Group(std::string&);

	std::string plainText;
	std::string key;
};

#endif