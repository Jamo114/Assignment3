#include "driver.h"
inline void mySleep(clock_t sec)
// clock_t is a like typedef unsigned int clock_t. Use clock_t instead of integer in this context
{
	clock_t start_time = clock();
	clock_t end_time = sec * 1000 + start_time;
	while (clock() != end_time);
}

int main(int argc, char* argv[])
{
	cmdline_parser parser;

	if (!parser.process_cmdline(argc, argv))
	{
		std::cerr << "Couldn't process command line arguments" << std::endl;
		return 1;
	}

	if (parser.should_print_help())
		parser.print_help(std::cout);

	std::string test = "Beware the Jabberwock, my son! The jaws that bite, the claws that catch!";
	CryptoMachinePolicies<XOR, ECB, Pack, GroupingNo> rawr;
	std::cout << test << std::endl;
	rawr.encode(test, "VIGENERECIPHER");
	rawr.decode(test, "VIGENERECIPHER");
	std::cout << test << std::endl;
	mySleep(30);
}

