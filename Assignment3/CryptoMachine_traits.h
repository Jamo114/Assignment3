#ifndef _CRYPTOMACHINE_TRAITS_H
#define _CRYPTOMACHINE_TRAITS_H

#include "Simple_types.h"

template<typename Cipher, typename Mode, typename Pack, typename Group>
class CryptoMachineTraits
{
	typedef Cipher cipher;
	typedef Mode mode;
	typedef Pack pack;
	typedef Group group;
};

template<typename Pack>
class CryptoMachineTraits<Vigenere, ECB, Pack, GroupingYes>
{
	typedef Vigenere cipher;
	typedef ECB mode;
	typedef GroupingYes group;
};

template<typename Pack>
class CryptoMachineTraits<Vigenere, ECB, Pack, GroupingNo>
{
	typedef Vigenere cipher;
	typedef ECB mode;
	typedef GroupingNo group;
};

#endif