#include "huffman.h"
#include <iomanip>

int main(int argc, char **argv)
{
	if( argc != 3 ) {
		std::cerr << "ERR0R: Not enough arguments given\n";
		return -1;
	}
	std::string filename = argv[1];
	std::string outputFile = argv[2];

	std::string file_content;
	std::vector<Nodes> heap = count(filename, file_content);

	std::cout << "File content:\n" << file_content << "\n";
	// Printing for debugging heap
/*	std::cout << "Before Sorting\n@ Vector:\n[";
	for(auto &e : heap )
	{
		std::cout << " (" << e.key << ", " << e.freq << "),";
	}
	std::cout << "]\n";

	std::cout << "After Sorting\n@ Heap:\n";
*/
	CodTree avure(heap);

	// Bits counter before. For visualization purposes
	std::string buff_bf;

	printf("\nBefore compression:\n");
	for( auto &c : file_content )
	{
		std::string temp = to_bin(c);
		buff_bf += temp;
		std::cout << temp << " ";
	}
	printf("\nNumber of bits used: %d\n", buff_bf.size());

	std::string *codTable = new std::string[256];

	// Creates our Codification Table. Represented by codTable.
	// Which derivates from our Codification Tree
	printf("\nNew characters representation:\n");
	for( auto &e : heap )
	{
		std::string bin = avure.codify(e.key);
		std::cout << "'" << e.key << "':= " << bin << "\n";

		codTable[e.key] = bin;
	}

	// Bits counter after. Also visualization purposes.
	// Show new representations.
	std::string buff_af;


	printf("\nAfter compression:\n");
	for( auto &c : file_content )
	{
		buff_af += codTable[(int)c];
		std::cout << codTable[(int)c] << " ";
	}
	printf("\nNumber of bits used: %d\n", buff_af.size());

	write(outputFile, buff_af);
	// Now we create our compacted file.
	return 0;
}
