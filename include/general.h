#ifndef _GENERAL_H_
#define _GENERAL_H_

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <queue>
#include <algorithm>

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

/*Print queue method{{{*/
template< typename T>
void printHeap(T queue)
{
	std::cout << "[";
	while( !queue.empty() )
	{
		std::cout << "(" << queue.top()->key << ", " << queue.top()->freq;
		if( queue.size() == 1 ) std::cout << ")";
		else { std::cout << "), ";}
		
		queue.pop();
	}
	std::cout << "]\n";
}/*}}}*/

bool dataCompare(const Nodes*, const Nodes*);
std::vector<Nodes> count(std::string, std::string&);
std::string to_bin(size_t);
void write(std::string, std::string);

#endif
