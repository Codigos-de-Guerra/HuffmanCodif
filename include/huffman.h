#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

#include "general.h"

/*
std::string to_bin(size_t x){
	std::string str;
	while( x >= 1 ){
		str.append(std::to_string(x%2));
		x = x/2;
	}

	int j = str.size()-1;
	for(int i=0; i < str.size()/2; i++){
		auto temp = str.at(i);
		str.at(i) = str.at(j);
		str.at(j) = temp;
		j--;
	}
					 
//	std::cout << "Binário final: " << str << std::endl;
	return str;
	// Working!!
}
*/

class CodTree {
	private:
		Node* m_root;

	public:
		CodTree(std::vector<Nodes> frequen){
			this->m_root = new Node;

			std::priority_queue<
				Nodes*,
				std::vector<Nodes*>,
				dataCompare
				> List_of_Trees;

			for(auto &e : frequen) List_of_Trees.push(new Nodes(e.key, e.freq));

			// For debugging
			printHeap(List_of_Trees);


			// Constructing Codification Tree
			// Implemented in a alternative way, rather than a list of Tree.
			// That's why my heap gets this name :)

			while( List_of_Trees.size() >= 2 )
			{
				Nodes* r_one = List_of_Trees.top();	//!< Right node.
				List_of_Trees.pop();

				Nodes* l_one = List_of_Trees.top();	//!< Left node.
				List_of_Trees.pop();

				// Both with lowest frequency will be removedi(the 2 on top).

				// This node is to be re-inserted as sum of the removed ones.
				Nodes* top_one = new Nodes;
				top_one->right = r_one;
				top_one->left = l_one;

				// It's frequency will be their sum.
				top_one->freq = r_one->freq + l_one->freq;

				// This node will be placed aboved the other two.
				List_of_Trees.push(top_one);

				// Sets as root.
				m_root = top_one;
			}

		}

		~CodTree(void)
		{
			std::stack<Nodes*> del;
			Nodes* current = this->m_root;
		};
/*
		void walk(std::string str){
			std::string st_ring;
			auto res = private_walk(str, this->m_root, st_ring);
			std::cout << "Path: " << res.first
					  << "\nResults: " << res.second << "\n";
		}
*/
		void walk(std::string str){
			size_t len = str.size();
			private_walk(str, this->m_root, len);
		}
		bool add(size_t c){
			std::string str = to_bin(c);
			return insert(str, this->m_root, c);}

};

#endif
