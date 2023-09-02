#include <iostream>
#include <cstring>
#include <string>
#include <memory>
#include <fstream>
#include <sstream>

#include "MyMap.hpp"
#include "TrieNode.hpp"

int read_sizes(int *lineCounter, int *maxLength, std::string docFile);
int read_input(MyMap *mymap, TrieNode* trie, std::string docFile);

