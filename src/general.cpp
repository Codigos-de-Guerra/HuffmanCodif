#include "general.h"

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
