#ifndef _CRYPTOMACHINE_TRAITS_H
#define _CRYPTOMACHINE_TRAITS_H

#include "Simple_types.h"

template<typename Cipher, typename Mode, typename Pack, typename Group>
class CryptoMachineTraits
{};

template<typename Pack>
class CryptoMachineTraits<Vigenere, ECB, Pack, GroupingYes>
{};

template<typename Pack>
class CryptoMachineTraits<Vigenere, ECB, Pack, GroupingNo>
{};

template<typename Pack>
class CryptoMachineTraits<XOR, ECB, Pack, GroupingYes>
{};

#endif