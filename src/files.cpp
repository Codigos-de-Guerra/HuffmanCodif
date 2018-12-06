#include "files.h"

// Identifies how many times each character ocurred
/* Count method{{{*/
std::vector<Nodes> count( std::string filename, std::string &content )
{
	// Opens file containg string to be shortened
	std::ifstream ifs;
	ifs.open(filename.c_str());

	char c;
	std::map<unsigned char, bit> rep;

	while(ifs.good())
	{
		c = ifs.get();
		if( c == EOF || c == '\n' ) break;
		try{
			rep[c] += 1;
		} catch (...) {
			rep[c] = 1;
		}

		content += c;
	}

	std::vector<Nodes> ocur;
	for( auto &e : rep )
	{
		Nodes temp;
		temp.key = e.first;
		temp.freq = e.second;
		ocur.push_back(temp);
	}

	return ocur;
}/*}}}*/
/* Write function{{{*/
void write( std::string filename, std::string content )
{
	std::ofstream ofs;
	ofs.open(filename.c_str());

	ofs << content;

	ofs.close();
}
/*}}}*/
/* Read Function{{{*/
std::string read( std::string filename )
{
	std::string content;
	std::ifstream ifs;
	ifs.open(filename.c_str());

	char c;
	while(ifs.good())
	{
		c = ifs.get();
		if( c != '\0') content += c;
	}

	ifs.close();
	
	return content;
}/*}}}*/
