#include "general.h"

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

	std::vector<Nodes> sorted_rep;
	for( auto &e : rep )
	{
		Nodes temp;
		temp.key = e.first;
		temp.freq = e.second;
		sorted_rep.push_back(temp);
	}

	return sorted_rep;
}/*}}}*/
/*Compare function{{{*/
// For a minHeap, it should return true when a comes after b.
bool dataCompare( const Nodes *a, const Nodes *b )
{
	if( a->freq != b->freq ) return a->freq > b->freq;
	return a->key > b->key;
}/*}}}*/
/*Transform into binary function{{{*/
std::string to_bin(size_t ascii)
{
	std::string result;
	while( ascii >= 1 )
	{
		result.append(std::to_string(ascii%2));
		ascii /= 2;
	}

	std::reverse(result.begin(), result.end());
	while( result.size() < 8 ) result = std::to_string(0).append(result);

	return result;
}/*}}}*/
/* Compactor function{{{*/
void compactor(std::string output, std::string header, std::string body)
{
	std::ofstream ofs;
	ofs.open(output.c_str());

	// Header inserted.
	ofs << header;
	ofs << "\n";	// Separate header from body.
	ofs << body <</*Indicating end of sequence*/ (char)3;

	ofs.close();
}
/*}}}*/
/*Decompactor{{{*/
void decompactor(std::string file_to_descompact)
{
	std::ifstream ifs;
	ifs.open(file_to_descompact.c_str());
}
/*}}}*/
