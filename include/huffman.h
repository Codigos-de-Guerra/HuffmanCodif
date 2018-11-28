#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

#include <vector>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>

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

struct Node{
	char data;
	Node** children;

	Node( Node* left = nullptr, Node* right = nullptr, char info = '\0'){
		children = new Node*[2];
		children[0] = left;
		children[1] = right;
		data = info;
	}
};

class DigiTree{
	private:
		size_t m_height;
		Node* m_root;

		bool insert(std::string&, Node*&, size_t);

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
			return str;
		}
//		std::pair<std::string,size_t> private_walk(std::string, Node*, std::string&);

		void private_walk(std::string&, Node*,size_t&);

	public:
		DigiTree(void){
			this->m_root = new Node;
			this->m_height = 1;
		}

		~DigiTree(void){/* empty */};
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
		void go_left( Node* &node){
			if( node->children[0] != nullptr ) return;
			node->children[0] = new Node;
		}
		void go_right( Node* &node){
			if( node->children[1] != nullptr ) return;
			node->children[1] = new Node;
		}

};

#endif
