#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

#include "general.h"
#include <stack>

class CodTree {
	private:
		Nodes* m_root;

		/*
		 * @brief Internal auxiliar function of 'pre-order'.
		 * @param Receives tree's root, and a savable string.
		 */
		void i_pre_ord(Nodes*, std::string&);

		bool reCreate(std::string, Nodes*&, size_t&, size_t&);
	public:

		/*
		 * @brief Default Constructor. Used on Decompactor.
		 */
		CodTree(std::string header)
		{
				//TODO
			this->m_root = new Nodes;
			size_t leafs = 0;
			size_t cont = 0;
			for( auto &c : header )
			{
				if( c != '1' and c != '0' )
				{
					leafs++;
				}
			}

			// Recreates original CodTree
			/* bool res = */reCreate(header, this->m_root, cont, leafs);
		}

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
