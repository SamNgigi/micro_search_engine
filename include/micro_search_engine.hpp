#ifndef MICRO_SEARCH_ENGINE_HPP
#define MICRO_SEARCH_ENGINE_HPP

#include <iostream>
#include <cstring>
#include <vector>

#include "TrieNode.hpp"
#include "MyMap.hpp"


void mysearch(std::vector<std::string> token, TrieNode* trie, MyMap* mymap, int k);
void df(TrieNode* trie); // ? Depth-First traversal?
int tf(std::vector<std::string> token, TrieNode* trie);// ? What does this function do?
#endif //MICRO_SEARCH_ENGINE_HPP