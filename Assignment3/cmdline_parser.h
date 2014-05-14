#ifndef CMDLINE_PARSER_H_
#define CMDLINE_PARSER_H_

#include <iostream>
#include <list>
#include <string>

#include <boost/program_options.hpp>

//---------------------------------------------------------------------------//
class cmdline_parser
{
public:
    //-----------------------------------------------------------------------//
	// Constructor
	cmdline_parser(void); 

	// Member function that parses command line options
	bool process_cmdline(int argc, char * argv[]);
	// Return the input filename
	std::string get_input_filename(void) const;
	// Return the output filename
	std::string get_output_filename(void) const;
	// Get the number of threads
	int get_number_threads(void);
	
	void encode(void);
	void decode(void);
	std::string get_vigenere_key(void) const;
	std::string get_xor_key(void) const;
	std::string get_initialization_vector(void) const;
	std::string get_mode(void) const;
	void grouping(void);
	void packing(void);

	void print_errors(std::ostream & out) const;

	bool should_print_help(void) const;
	// Output help to the specified output stream
	void print_help(std::ostream & out) const;

private:
    //-----------------------------------------------------------------------//
	// Member variables
	boost::program_options::variables_map vm;
	boost::program_options::options_description od;
	std::list<std::string> errors;

    //-----------------------------------------------------------------------//
	// Static string variables
	static const std::string INPUTFILE;
	static const std::string OUTPUTFILE;
	static const std::string NUMBERTHREADS;
	static const std::string XORKEY;
	static const std::string VIGENEREKYE
	static const std::string INITIALIZATIONVECTOR;
	static const std::string MODE;
};

#endif /* CMDLINE_PARSER_H_ */
