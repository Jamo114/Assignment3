#ifndef CRYPTOMACHINE_H_
#define CRYPTOMACHINE_H_

#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
template <typename Cipher, typename Mode, typename Pack, typename Group>
class CryptoMachine
{
public:
	typedef Cipher cipher;
	typedef Mode mode;
	typedef Pack pack;
	typedef Group group;

	CryptoMachine(Cipher, Mode, Pack, Group);
	~CryptoMachine();
	void Encode(std::istream &, std::ostream &);
	void Decode(std::istream &, std::ostream &);
	void Grouping(std::string&);

	std::string plainText;
	std::string key;
};

#endif