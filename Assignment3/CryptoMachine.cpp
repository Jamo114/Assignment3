#include "CryptoMachine.h"
template <typename Cipher, typename Mode, typename Pack, typename Group>
CryptoMachine<Cipher, Mode, Pack, Group>::CryptoMachine(Cipher c, Mode g, Pack p, Group g)
{
	this->cipher = c;
	this->mode = m;
	this->pack = p;
	this->group = g;
}

template <typename Cipher, typename Mode, typename Pack, typename Group>
CryptoMachine::~CryptoMachine()
{}

template <typename Cipher, typename Mode, typename Pack, typename Group>
void CryptoMachine<Cipher, Mode, Pack, Group>::Encode(std::istream & in, std::ostream & out)
{
	std::transform(plainText.begin(), plainText.end(), plainText.begin(), ::toupper);

	//sorts out the grouping option
	if (this->group == "yes")
	{
		plainText.erase(
			std::remove_if(plainText.begin(), plainText.end(), std::isspace),
			plainText.end());


		Grouping(plainText);
	}

	//determines what cipher to use
	if (this->cipher == vignere)
	{
		//implement vignere cipher
	}

	else if (this->cipher == xor)
	{
		//implement xor cipher
	}

	//ignore mode for now

	//ignore packing for now

}

template <typename Cipher, typename Mode, typename Pack, typename Group>
void CryptoMachine::Decode(std::istream & in, std::ostream & out)
{

	std::transform(plainText.begin(), plainText.end(), plainText.begin(), ::toupper); 
	
	//sorts out the grouping option
	if (this->group == "yes")
	{
		plainText.erase(
			std::remove_if(plainText.begin(), plainText.end(), std::isspace),
			plainText.end());


		Grouping(plainText);
	}

	//determines what cipher to use
	if (this->cipher == vignere)
	{
		//implement vignere cipher
	}

	else if (this->cipher == xor)
	{
		//implement xor cipher
	}

	//ignore mode for now

	//ignore packing for now
}


//Removes all spaces and adds a space after every fifth character
template <typename Cipher, typename Mode, typename Pack, typename Group>
void CryptoMachine::Grouping(std::string & x)
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
