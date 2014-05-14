James Oosterbaan - OSTJAM002.
Assignment 3 - Template Specialization and STL.
-----------------------------------------------

*Due to compiler issues on the nightmare PC's (g++ version not 4.7) I was not able to
implement the command line parser. I did try do some work on the "cmdline_parser.cpp/.h"
files though.*

After the project is "made", when you run it it will do the unit tests. They are in this
order:

1) Testing the encoding of the Vigenere Cipher.
2) Testing the decoding of the Vigenere Cipher;
3) Testing the grouping option.
4) Testing the encoding of the XOR Cipher in ECB mode.
5) Testing the decoding of the XOR Cipher in ECB mode.

(I was not able to implement the other mode, CBC, for the XOR Cipher. In addition to this,
I was also not able to get the bit packing working. This is why there are no unit tests for these cases.
Due to this, the functionality of the XOR Cipher will be erratic/wrong.)

Files:
	-	driver.cpp
	-	driver.h
	-	Simple_types.h
	-	Simple_types.cpp
	-	CryptoMachine_traits.h
	-	CryptoMachine_traits.cpp
	-	CryptoMachine_policy.h
	-	CryptoMachine_policy.cpp
	-	catch.hpp
	-	Makefile
	-	Readme.txt
	-	ciphertext.txt
	-	plaintext.txt
	-	newplaintext.txt