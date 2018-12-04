#include "huffman.h"

int main(int argc, char **argv)
{
	if( argc != 2 ) {
		std::cerr << "ERR0R: No input file given\n";
		return -1;
	}
	std::string filename = argv[1];
	std::ifstream ifs;

	std::vector<Nodes> heap = count(filename);

	// Printing heap
	std::cout << "Before Sorting\n@ Vector:\n[";
	for(auto &e : heap )
	{
		std::cout << " (" << e.key << ", " << e.freq << "),";
	}
	std::cout << "]\n";

	std::cout << "After Sorting\n@ Heap:\n";
	CodTree avure(heap);


	// Creates our Codification Table
	// Which derivates from our Codification Tree
	for( auto &e : heap )
	{
		std::string bin = avure.codify(e.key);
		//TODO
	}

	return 0;
}
