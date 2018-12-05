#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

#include "general.h"
#include <stack>

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
		Nodes* m_root;

		/*
		 * @brief Internal auxiliar function of 'pre-order'.
		 * @param Receives tree's root, and a savable string.
		 */
		void i_pre_ord(Nodes*, std::string&);
	public:

		/*
		 * @brief Default Constructor. Used on Decompactor.
		 */
		CodTree(std::string);

		/*
		 * @brief Constructor from vector
		 */
		CodTree(std::vector<Nodes> frequen);

		/*
		 * @brief Destructor
		 */
		~CodTree(void);

		/*
		 * @brief Searchs for given char. Saves path.
		 * @param _c, root, path. Char to search, current Node, string gets path
		 * @returns True if is found. False otherwise
		 */
		bool search(char _c, Nodes* root, std::string& path);

		/*
		 * @brief Shortens bin corresponding to given char.
		 * @param _c. Char to be codified.
		 * @returns String type containing path encoded
		 */
		std::string codify(char _c);

		/*
		 * @brief Saves a pre-order sequence over tree nodes.
		 */
		std::string pre_ord(void)
		{
			std::string header;
			i_pre_ord(this->m_root, header);
			return header;
		}
};

#endif
