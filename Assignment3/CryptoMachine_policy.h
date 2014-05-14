#ifndef _CRYPTOMACHINE_POLICY_H
#define _CRYPTOMACHINE_POLICY_H

#include "CryptoMachine_traits.h"

template<typename Cipher, typename Mode, typename Pack, typename Group>
class CryptoMachinePolicies
{
	std::string key;
};

template<typename Pack>
class CryptoMachinePolicies<Vigenere, ECB, Pack, GroupingYes>
{
public:
	std::string key;
	void encode(std::istream & in, std::ostream & out)
	{
		std::string Str;
		std::getline(in, Str);
		//Transform all to upper case and removes spaces
		std::transform(Str.begin(), Str.end(), Str.begin(), ::toupper);
		Str.erase(
			std::remove_if(Str.begin(), Str.end(), ::isspace),
			Str.end());

		std::string temp;
		for (int i = 0, j = 0; i < Str.length(); ++i)
		{
			char c = Str[i];

			if (c >= 'a' && c <= 'z')
				c += 'A' - 'a';
			else if (c < 'A' || c > 'Z')
				continue;

			temp += (c + key[j] - 2 * 'A') % 26 + 'A';
			j = (j + 1) % key.length();
		}
		Str = temp;

		GroupingYes go;
		go.group(Str);
		out << Str;
	}

	void decode(std::istream &in, std::ostream &out)
	{
		std::string Str;
		std::getline(in, Str);
		//Transform all to upper case and removes spaces
		std::transform(Str.begin(), Str.end(), Str.begin(), ::toupper);

		std::string temp;
		std::cout << Str << std::endl;
		for (int i = 0, j = 0; i < Str.length(); ++i)
		{
			char c = Str[i];

			if (c >= 'a' && c <= 'z')
				c += 'A' - 'a';
			else if (c < 'A' || c > 'Z')
				continue;

			temp += (c - key[j] + 26) % 26 + 'A';
			j = (j + 1) % key.length();
		}
		Str = temp;

		GroupingYes go;
		go.group(Str);
		out << Str;
	}
};

template<typename Pack>
class CryptoMachinePolicies<Vigenere, ECB, Pack, GroupingNo>
{
public:
	std::string key;
	void encode(std::istream & in, std::ostream & out)
	{
		std::string Str;
		std::getline(in, Str);
		//Transform all to upper case and removes spaces
		std::transform(Str.begin(), Str.end(), Str.begin(), ::toupper);
		Str.erase(
			std::remove_if(Str.begin(), Str.end(), ::isspace),
			Str.end());

		std::string temp;
		for (int i = 0, j = 0; i < Str.length(); ++i)
		{
			char c = Str[i];

			if (c >= 'a' && c <= 'z')
				c += 'A' - 'a';
			else if (c < 'A' || c > 'Z')
				continue;

			temp += (c + key[j] - 2 * 'A') % 26 + 'A';
			j = (j + 1) % key.length();
		}
		Str = temp;
		out << Str;
	}

	void decode(std::istream & in, std::ostream & out)
	{
		std::string Str;
		std::getline(in, Str);
		//Transform all to upper case and removes spaces
		std::transform(Str.begin(), Str.end(), Str.begin(), ::toupper);

		std::string temp;
		for (int i = 0, j = 0; i < Str.length(); ++i)
		{
			char c = Str[i];

			if (c >= 'a' && c <= 'z')
				c += 'A' - 'a';
			else if (c < 'A' || c > 'Z')
				continue;

			temp += (c - key[j] + 26) % 26 + 'A';
			j = (j + 1) % key.length();
		}
		Str = temp;
		out << Str;
	}
};

template<typename Pack>
class CryptoMachinePolicies<XOR, ECB, Pack, GroupingYes>
{
public:
	std::string key;
	void encode(std::istream & in, std::ostream & out)
	{
		std::string Str;
		std::getline(in, Str);
		//Transform all to upper case and removes spaces
		std::transform(Str.begin(), Str.end(), Ste.begin(), ::toupper);
		std::string temp;
		for (int i = 0, j = 0; i < Ste.size(); ++i)
		{
			temp += Str[i] ^ key[j];
			j = (j + 1) % key.length();
		}
		Str = temp;
		GroupingYes go;
		go.group(Str);
		out << Str;
	}

	void decode(std::istream & in, std::ostream & out)
	{
		//Transform all to upper case and removes spaces
		std::transform(x.begin(), x.end(), x.begin(), ::toupper);
		std::string out;
		for (int i = 0, j = 0; i < x.size(); ++i)
		{
			out += x[i] ^ key[j];
			j = (j + 1) % key.length();
		}
		GroupingYes go;
		go.group(out);
		x = out;
	}
};

template<typename Pack>
class CryptoMachinePolicies<XOR, ECB, Pack, GroupingNo>
{
public:
	std::string key;
	void encodeDecode(std::istream & in, std::ostream & out)
	{
		std::string Str;
		std::getline(in, Str);
		//Transform all to upper case and removes spaces
		//std::transform(Str.begin(), Str.end(), Str.begin(), ::toupper);
		std::string temp;
		for (int i = 0, j = 0; i < Str.size(); ++i)
		{
			if (Str[i] < 'A' || Str[i] > 'Z')
				//continue;
			temp += Str[i] ^ key[j];
			j = (j + 1) % key.length();
		}
		Str = temp;
		out << Str;
	}
};
#endif