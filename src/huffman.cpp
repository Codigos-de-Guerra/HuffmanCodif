#include "huffman.h"
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
					 
	return str;
}

size_t from_bin(std::string str){
	size_t len = str.size();
	size_t result = 0;

	int i = 0;
	std::cout << "Size: " << len << std::endl;
	while( len > 0 ){
		result += (str.at(i)-48) * pow(2,len-1);
		i++;
		len--;
		std::cout << "re " << result << " ";
	}

	std::cout << "Result: " << result << "\n";
	if( to_bin(result).size() < str.size() ){

	return result;
}

std::pair<std::string, size_t> DigiTree::private_walk(std::string str, Node* root, std::string& a){
	
	if(root->children[0] != nullptr ){
		std::cout << "WEWW\n";
		str.erase(0,1);
		a.push_back('0');
		this->private_walk(str, root->children[0], a);
	}
	else if(root->children[1] != nullptr ){
		std::cout << "WW!111\n";
		str.erase(0,1);
		a.push_back('1');
		this->private_walk(str, root->children[1], a);
	}
	if( root->children[0] == nullptr && root->children[1] == nullptr ){
//	std::pair<std::string, size_t> foo;
		return std::make_pair(a, root->data);
	}
}
*/
void DigiTree::private_walk(std::string& str, Node* root, size_t& len){
	if(len == 0){
	std::cout << "Path: " << str << "\nData: "
			  << root->data << "\n";
	return;
	}
	size_t lor = str.front()-48;
	std::cout << lor;
	if(root->children[lor] != nullptr ){
		std::cout << "WEWW\n";
		str.push_back(str.front());
		str.erase(0,1);
		len--;
		lor = str.front()-48;
		std::cout << lor << std::endl;
//		system("man git");
		this->private_walk(str, root->children[lor], len);
	}

	else {
		std::cerr << "Path IS NOT avaiable!\n";
		
//		return;
//		str.erase(0,1);
//		str.push_back('1');
//		len--;
//		this->private_walk(str, root->children[1], len);
	}
	if( root->children[0] == nullptr && root->children[1] == nullptr){
		std::cout << "Path: " << str << "\nData: "
				  << root->data << "\n";
	}
}

bool DigiTree::insert(std::string& str, Node* &root, size_t original){
	std::cout << "Bin: " << str << std::endl;
//	std::cin.ignore();
	while( !str.empty() ){
		printf("Size: %d\n", str.size());
		if(str.front() == '0'){
			go_left(root);
//			if( str.size() == 1 ){
//				root->children[0]->data = original;
//				return true;
//			}
			str.erase(0,1);
			this->insert(str, root->children[0], original);
		}
		else if(str.front() == '1'){
			go_right(root);
//			if( str.size() == 1){
//				root->children[1]->data = original;
//				return true;
//			}
			str.erase(0,1);
			this->insert(str, root->children[1], original);
		}
	}
	if( root->children[0] == nullptr and root->children[1] == nullptr) root->data = original;
	return true;
}
