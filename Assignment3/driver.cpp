#include "driver.h"
inline void mySleep(clock_t sec)
// clock_t is a like typedef unsigned int clock_t. Use clock_t instead of integer in this context
{
	clock_t start_time = clock();
	clock_t end_time = sec * 1000 + start_time;
	while (clock() != end_time);
}

int main()
{
	std::string test = "Beware the Jabberwock, my son! The jaws that bite, the claws that catch!";
	CryptoMachinePolicies<Vigenere, ECB, Pack, GroupingNo> rawr;
	
	rawr.encode(test, "VIGENERECIPHER");
	rawr.decode(test, "VIGENERECIPHER");
	std::cout << test << std::endl;
	mySleep(30);
}

