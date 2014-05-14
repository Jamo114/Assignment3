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

	/*if (!parser.process_cmdline(argc, argv))
	{
		std::cerr << "Couldn't process command line arguments" << std::endl;
		return 1;
	}

	if (parser.should_print_help())
		parser.print_help(std::cout);*/

	CryptoMachinePolicies<Vigenere, ECB, Pack, GroupingYes> rawr;
	rawr.key = "ABCDABCDABCDABCDABCDABCDABCD";
	rawr.encode(std::cin, std::cout);
	rawr.decode(std::cin, std::cout);
	mySleep(30);
}

/*TEST_CASE("TESTV", "")
{
	INFO("Test Vignere encoad");
	//Vignere vi;
	//vi.setKey("LEMON");
	CryptoMachinePolicies<Vigenere, ECB, Pack, GroupingYes> CM;
	std::string outputFileName = "ciphertext.txt";
	std::string inputFileName = "plaintext.txt";
	CM.encode(inputFileName, outputFileName);
	std::ifstream in("ciphertext.txt");
	std::string line;
	std::getline(in, line);
	REQUIRE(line == "LXFOPVEFRNHR,OGEEOYNEHMKA");
}*/

