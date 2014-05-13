#ifndef _CRYPTOMACHINE_POLICY_H
#define _CRYPTOMACHINE_POLICY_H

#include "CryptoMachine_traits.h"

template<typename Cipher, typename Mode, typename Pack, typename Group>
class CryptoMachinePolicies
{

};

template<typename Pack>
class CryptoMachinePolicies<Vignere, ECB, Pack, Grouping>
{
public:
	void encode(std::string &x)
	{
		Grouping go;
		go.group(x);
	}
};

#endif