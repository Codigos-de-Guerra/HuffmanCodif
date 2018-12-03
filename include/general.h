#ifndef _GENERAL_H_
#define _GENERAL_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <queue>

typedef unsigned short int bit;

typedef struct CodiffTreeNodes {

	unsigned char key;		//!< The char's key
	bit freq;				//!< Frequency of a given char

	CodiffTreeNodes* left = nullptr;
	CodiffTreeNodes* right = nullptr;

	CodiffTreeNodes( unsigned char info = '\0', bit repeticao = 0 )
	{
		key = info;
		freq = repeticao;
	};
} Nodes;	//!< Just like a BST node, but with frequency counter.
			// It will be easier to create our Codification Tree.

// For a minHeap, it should return true when a comes after b.
bool dataCompare( const Nodes *a, const Nodes *b )
{
	if( a->freq != b->freq ) return a->freq > b->freq;
	return a->key > b->key;
}

template< typename T>
void printHeap(T queue)
{
	std::cout << "[ ";
	while( !queue.empty() )
	{
		std::cout << "(" << queue.top()->key << ", " << queue.top()->freq
				  << "), ";
		queue.pop();
	}
	std::cout << "]\n";
}

std::vector<Nodes> count( std::string file )
{
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

	//std::make_heap(sorted_rep.begin(), sorted_rep.end(), dataCompare);

	return sorted_rep;
}

#endif
