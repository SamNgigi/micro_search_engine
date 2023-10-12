#ifndef TRIENODE_H
#define TRIENODE_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <sstream>

#include "ListNode.hpp"

class TrieNode{
    char value;
    std::unique_ptr<TrieNode> sibling;
    std::unique_ptr<TrieNode> child;
    std::unique_ptr<ListNode> list;

    // list node; std::vector<std::unique_ptr<TrieNode>> list_nodes;j
    public:
        TrieNode(): value(-1), sibling(nullptr), child(nullptr), list(nullptr){}
        void insert(std::string token, int id, int idx=0);
        int searchWord(int id, std::string word, int current);
        static void printTrie(TrieNode* node, std::string currentWord="");

};

#endif // TRIENODE_H

