#include "huffman.h"

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

