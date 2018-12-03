#include "general.h"

int main(int argc, char **argv)
{
	//std::string filename = argv[1];
	std::string filename = "src/input.dat";
	std::ifstream ifs;

	std::vector<Nodes> heap = count(filename);

	// Printing heap
	std::cout << "\n@ Heap:\n";
	for(auto &e : heap )
	{
		std::cout << "(" << e.key << ", " << e.freq << ")\n";
	}

	return 0;
}
