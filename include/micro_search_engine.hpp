#ifndef MICRO_SEARCH_ENGINE_HPP
#define MICRO_SEARCH_ENGINE_HPP

#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>

#include "TrieNode.hpp"
#include "MyMap.hpp"
#include "utils.hpp"


void mysearch(std::vector<std::string> token, TrieNode* trie, MyMap* mymap, int k);
void df(std::vector<std::string> tokens, TrieNode* trie); // ? Returns how many document lines word occurs in 
int tf(std::vector<std::string> token, TrieNode* trie);// ? Returns a word frequency in a document line.
#endif //MICRO_SEARCH_ENGINE_HPP