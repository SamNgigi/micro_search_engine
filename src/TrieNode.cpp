#include "TrieNode.hpp"


void TrieNode::insert(std::string token, int id, int idx){
    if(idx == token.length()) return;
    if(value==-1 || value == token[idx]){
        value = token[idx++];
        // std::cout << value << " | ";
        if(token.size() == 1){
            // TODO: Initialize list
            return;
        }else{
            if(child == nullptr) child = std::make_unique<TrieNode>();
            child->insert(token, id, idx);
        }
    }else{
        if(sibling == nullptr) sibling = std::make_unique<TrieNode>();
        sibling->insert(token, id);
    }
}