#include "general.h"
#include "huffman.h"

int main(int argc, char **argv)
{
	//std::string filename = argv[1];
	std::string filename = "src/input.dat";
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

	return 0;
}
