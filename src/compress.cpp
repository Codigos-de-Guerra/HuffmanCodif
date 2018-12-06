#include "compress.h"

/*Compact Function{{{*/
std::string compactor( CodTree& tree)
{
	std::string content = "a";
	std::string header = tree.pre_ord();

	//TODO
	// transform header into bits
	std::string body = " ";
	//Treat bits
	content = header + body;	

	return content;

}/*}}}*/
/*Decompact Function{{{*/
std::string decompactor(std::string name)
{
	std::string compressedForm = read(name);

//	CodTree avure(compressedForm);		// Re-creation of Codification Tree
	
	// With CodTree, search for each key.
	std::string content = /*TODO*/ "0";
	//TODO

	return content;

}
/*}}}*/
