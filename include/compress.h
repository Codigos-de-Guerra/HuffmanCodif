#ifndef _COMPRESS_H_
#define _COMPRESS_H_

#include "files.h"
#include "huffman.h"

std::string compactor(CodTree&);
std::string decompactor(std::string);

#endif
