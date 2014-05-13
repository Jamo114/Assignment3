#ifndef _CRYPTOMACHINE_POLICY_H
#define _CRYPTOMACHINE_POLICY_H

#include "CryptoMachine_traits.h"

template<typename Cipher, typename Mode, typename Pack, typename Group>
class CryptoMachinePolicies
{

};

template<typename Pack>
class CryptoMachinePolicies<Vigenere, ECB, Pack, GroupingYes>
{
public:
	void encode(std::string &x, std::string key)
	{
		//Transform all to upper case and removes spaces
		std::transform(x.begin(), x.end(), x.begin(), ::toupper);
		x.erase(
			std::remove_if(x.begin(), x.end(), ::isspace),
			x.end());

		std::string out;
		std::cout << x << std::endl;
		for (int i = 0, j = 0; i < x.length(); ++i)
		{
			char c = x[i];

			if (c >= 'a' && c <= 'z')
				c += 'A' - 'a';
			else if (c < 'A' || c > 'Z')
				continue;

			out += (c + key[j] - 2 * 'A') % 26 + 'A';
			j = (j + 1) % key.length();
		}
		x = out;
		std::cout << x << std::endl;

		Grouping go;
		go.group(x);
	}

	void decode(std::string &x, std::string key)
	{
		//Transform all to upper case and removes spaces
		std::transform(x.begin(), x.end(), x.begin(), ::toupper);
		x.erase(
			std::remove_if(x.begin(), x.end(), ::isspace),
			x.end());

		std::string out;
		std::cout << x << std::endl;
		for (int i = 0, j = 0; i < x.length(); ++i)
		{
			char c = x[i];

			if (c >= 'a' && c <= 'z')
				c += 'A' - 'a';
			else if (c < 'A' || c > 'Z')
				continue;

			out += (c - key[j] + 26) % 26 + 'A';
			j = (j + 1) % key.length();
		}
		x = out;
		std::cout << x << std::endl;

		Grouping go;
		go.group(x);
	}
};

template<typename Pack>
class CryptoMachinePolicies<Vigenere, ECB, Pack, GroupingNo>
{
public:
	void encode(std::string &x, std::string key)
	{
		//Transform all to upper case and removes spaces
		std::transform(x.begin(), x.end(), x.begin(), ::toupper);
		x.erase(
			std::remove_if(x.begin(), x.end(), ::isspace),
			x.end());

		std::string out;
		std::cout << x << std::endl;
		for (int i = 0, j = 0; i < x.length(); ++i)
		{
			char c = x[i];

			if (c >= 'a' && c <= 'z')
				c += 'A' - 'a';
			else if (c < 'A' || c > 'Z')
				continue;

			out += (c + key[j] - 2 * 'A') % 26 + 'A';
			j = (j + 1) % key.length();
		}
		x = out;
		std::cout << x << std::endl;
	}

	void decode(std::string &x, std::string key)
	{
		//Transform all to upper case and removes spaces
		std::transform(x.begin(), x.end(), x.begin(), ::toupper);
		x.erase(
			std::remove_if(x.begin(), x.end(), ::isspace),
			x.end());

		std::string out;
		std::cout << x << std::endl;
		for (int i = 0, j = 0; i < x.length(); ++i)
		{
			char c = x[i];

			if (c >= 'a' && c <= 'z')
				c += 'A' - 'a';
			else if (c < 'A' || c > 'Z')
				continue;

			out += (c - key[j] + 26) % 26 + 'A';
			j = (j + 1) % key.length();
		}
		x = out;
		std::cout << x << std::endl;
	}
};

#endif