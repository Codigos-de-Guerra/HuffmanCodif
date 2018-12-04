#include "general.h"

/* Count method{{{*/
std::vector<Nodes> count( std::string file )
{
	// Opens file containg string to be shortened
	std::ifstream ifs;
	ifs.open(file.c_str());

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
