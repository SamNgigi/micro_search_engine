#ifndef TRIENODE_H
#define TRIENODE_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "ListNode.hpp"

class TrieNode{

    char value;
    std::unique_ptr<TrieNode> sibling;
    std::unique_ptr<TrieNode> child;
    // list node; std::vector<std::unique_ptr<TrieNode>> list_nodes;j
    public:
        TrieNode(): value(-1), sibling(nullptr), child(nullptr){}
        void insert(std::string token, int id, int idx=0);

};

#endif // TRIENODE_H

