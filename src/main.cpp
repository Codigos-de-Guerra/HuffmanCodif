#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>

#include "huffman.h"

int main(int argc, char **argv)
{
	std::map<size_t, size_t> rep;
	//std::string filename = argv[1];
	std::string filename = "input.dat";
	char c;
	std::ifstream ifs;

	ifs.open(filename.c_str());
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

	std::vector<std::pair<size_t,size_t>> vec_rep;
	for(auto i=rep.begin(); i != rep.end(); i++){
		std::cout << "(" << i->first << " : " << i->second << ") ";
	}
	std::cout << std::endl;

	DigiTree avure;
	avure.add(16);
	std::cout << "----------------------------------\n";
//	avure.add(14);
	std::cout << "----------------------------------\n";
//	avure.add(10);
	std::cout << "----------------------------------\n";
//	avure.add(8);
	std::cout << "----------------------------------\n";

	avure.walk("10000");
	return 0;
}
