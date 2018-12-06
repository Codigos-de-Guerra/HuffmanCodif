#include "compress.h"
#include <iomanip>
#include <iostream>

int main(int argc, char **argv)
{
	if( argc != 2 && argc != 3 ) {
		std::cerr << "ERR0R: Incorrect number of arguments\n given";
		return -1;
	}

	std::string filename = argv[1];
	std::string compressedFile = "build/compressed.txt";
	if( argc == 3 )
	{
		compressedFile = argv[2];
	}
	std::cout << "\n>>> Compressed file stored as '" << compressedFile << "'\n";

	std::string originalContent;
	std::vector<Nodes> heap = count(filename, originalContent);

	std::cout << ">>> File Original Content:\n" << originalContent << "\n";

	// Constructs Codification Tree
	CodTree tree(heap);

	// Stores bit representation before compression.
	std::string buff_bf;

	printf("\nBefore compression:\n");
	for( auto &c : originalContent )
	{
		std::string temp = to_bin(c);
		buff_bf += temp;
		std::cout << temp << " ";
	}
	std::cout << "\nNumber of bits used: " << buff_bf.size() << "\n";

	std::string *codTable = new std::string[256];

	// Creates our Codification Table. Represented by codTable.
	// Which derivates from our Codification Tree
	printf("\nNew characters representation:\n");
	for( auto &e : heap )
	{
		std::string bin = tree.codify(e.key);
		std::cout << "'" << e.key << "':= " << bin << "\n";

		codTable[e.key] = bin;
	}

	// Stores bit representation after compression.
	std::string buff_af;

	printf("\nAfter compression:\n");
	for( auto &c : originalContent )
	{
		buff_af += codTable[(int)c];
		std::cout << codTable[(int)c] << " ";
	}
	std::cout << "\nNumber of bits used: " << buff_af.size() << "\n";

	std::string cmpContent = compactor(tree);	// Compacting file
	write(compressedFile, cmpContent);			// Writes compression

	std::cout << "O\n";
	std::string decmpContent = decompactor(compressedFile);

	return 0;
}
