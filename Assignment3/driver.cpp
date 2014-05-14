#include "driver.h"
inline void mySleep(clock_t sec)
// clock_t is a like typedef unsigned int clock_t. Use clock_t instead of integer in this context
{
	clock_t start_time = clock();
	clock_t end_time = sec * 1000 + start_time;
	while (clock() != end_time);
}

//int main(int argc, char* argv[])
//{
//	CryptoMachinePolicies<XOR, ECB, Pack, GroupingNo> CM;
//	CM.key = "ABCDABCDABCDABCDABCDABCDABCD";
//	std::ofstream output;
//	output.open("ciphertext.txt");
//	std::ifstream input;
//	input.open("plaintext.txt");
//	CM.encodeDecode(input, output);
//	output.close();
//	input.close();
//	input.open("ciphertext.txt");
//	output.open("newplaintext.txt");
//	CM.encodeDecode(input, output);
//	system("pause");
//}

TEST_CASE("TESTVE", "")
{
	INFO("Test Vignere encoding");
	CryptoMachinePolicies<Vigenere, ECB, Pack, GroupingNo> CM;
	CM.key = "ABCDABCDABCDABCDABCDABCDABCD";
	std::ofstream output;
	output.open("ciphertext.txt");
	std::ifstream input;
	input.open("plaintext.txt");
	CM.encode(input, output);
	output.close();
	input.close();
	output.open("newplaintext.txt");
	input.open("ciphertext.txt");
	CM.decode(input, output);
	output.close();
	input.close();
	input.open("ciphertext.txt");
	std::string cipherText;
	std::getline(input, cipherText);
	REQUIRE(cipherText == "CSASTPKVSIQUTGQUCSASTPIUAQJB");
};

TEST_CASE("TESTVD", "")
{
	INFO("Test Vignere decoding");
	CryptoMachinePolicies<Vigenere, ECB, Pack, GroupingNo> CM;
	CM.key = "ABCDABCDABCDABCDABCDABCDABCD";
	std::ofstream output;
	output.open("ciphertext.txt");
	std::ifstream input;
	input.open("plaintext.txt");
	CM.encode(input, output);
	output.close();
	input.close();
	output.open("newplaintext.txt");
	input.open("ciphertext.txt");
	CM.decode(input, output);
	output.close();
	input.close();
	input.open("newplaintext.txt");
	std::string plainText;
	std::getline(input, plainText);
	REQUIRE(plainText == "CRYPTOISSHORTFORCRYPTOGRAPHY");
};


TEST_CASE("TESTG", "")
{
	INFO("Test grouping");
	GroupingYes gr;
	std::string x = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	gr.group(x);
	REQUIRE(x == "ABCDE FGHIJ KLMNO PQRST UVWXY Z");
};

TEST_CASE("TESTX", "")
{
	INFO("Test XOR encoding");
	CryptoMachinePolicies<XOR, ECB, Pack, GroupingNo> CM;
	CM.key = "ABCDABCDABCDABCDABCDABCDABCD";
	std::ofstream output;
	output.open("ciphertext.txt");
	std::ifstream input;
	input.open("plaintext.txt");
	CM.encodeDecode(input, output);
	output.close();
	input.close();
	input.open("ciphertext.txt");
	std::string cipherText;
	std::getline(input, cipherText);
	REQUIRE(cipherText == "CSASTPKVSIQUTGQUCSASTPIUAQJB");
}