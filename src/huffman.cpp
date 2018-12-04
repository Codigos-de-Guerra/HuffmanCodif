#include <algorithm>
#include "huffman.h"

/*
bool dataCompare( const Nodes *a, const Nodes *b )
{
	if( a->freq != b->freq ) return a->freq > b->freq;
	return a->key > b->key;
}*//*}}}*/

/*Constructor{{{*/
CodTree::CodTree(std::vector<Nodes> frequen)
{
	std::priority_queue<
		Nodes*,
		std::vector<Nodes*>,
		bool (*)(const Nodes*, const Nodes*)
		> List_of_Trees(dataCompare);

	for(auto &e : frequen) List_of_Trees.push(new Nodes(e.key, e.freq));

	// For debugging
	printHeap(List_of_Trees);

	// Constructing Codification Tree
	// Implemented in a alternative way, rather than a list of Tree.
	// That's why my heap gets this name :)

	while( List_of_Trees.size() >= 2 )
	{
		Nodes* l_one = List_of_Trees.top();	//!< Left node.
		List_of_Trees.pop();

		Nodes* r_one = List_of_Trees.top();	//!< Right node.
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
}/*}}}*/
/*Destructor{{{*/
CodTree::~CodTree(void)
{
	std::stack<Nodes*> del;			// All nodes need to be deleted
	del.push(this->m_root);

	while( !del.empty() )
	{
		Nodes* current = del.top();
		del.pop();

		if( current->left != nullptr ) del.push(current->left);
		if( current->right != nullptr ) del.push(current->right);

		delete current;
	}
}/*}}}*/
/*Search method{{{*/
bool CodTree::search(char _c, Nodes* root, std::string& path)
{
	if( root != nullptr )
	{
		if( root->key == _c ) return true;
		else if(search(_c, root->left, path))
		{
			path += "0";
			return true;
		}
		else if(search(_c, root->right, path))
		{
			path += "1";
			return true;
		}
		else { return false; }
	}

	return false;
}/*}}}*/
/* Codify method{{{*/
std::string CodTree::codify(char _c)
{
	std::string true_path;
	
	// Now we utilize our search method to keep track on path.	
	if(!search(_c, this->m_root, true_path))
	{
		std::cerr << "Oh shit!\n";
	}

	// Because of recursion, path returns inverted
	// So, we invert it again.
	std::reverse(true_path.begin(), true_path.end());

	return true_path;
}/*}}}*/

/*
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

