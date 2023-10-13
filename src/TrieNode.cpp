#include "TrieNode.hpp"


void TrieNode::insert(std::string token, int id, int idx){
    if (value == -1 || value == token[idx]) {
        value = token[idx];
        if (idx == token.length()-1) {
            if (!list) list = std::make_unique<ListNode>(id);
            list->add(id);
        } else {
            if (!child) child = std::make_unique<TrieNode>();
            child->insert(token, id, idx+1);
        }
    } else {
        if (!sibling) sibling = std::make_unique<TrieNode>();
        sibling->insert(token, id, idx);
    }
}

void TrieNode::printTrie(TrieNode* node, std::string currentWord){
    if(node == nullptr) return;

    if(node->value != -1) currentWord += node->value;

    if(node->list != nullptr)
        std::cout << "Word:: " << currentWord << "\nID:: " << node->list->id << "\n";

    printTrie(node->child.get(), currentWord);
    printTrie(node->sibling.get(), currentWord.substr(0, currentWord.length() - 1));
}

int TrieNode::searchWord(int id, std::string word, int current){
    // if char in word exists in trie, traverse it
    if(word[current] == value){
        // if we are at the end of the word
        if(current == word.length()-1){
            // continue traversing listnode if we are not at its end
            if(list != nullptr) return list->search(id);
            else return 0;
        } else { // if we are not at the end of the word
            // recursively traverse throught the trie children
            if(child != nullptr) return child->searchWord(id, word, current+1);
            else return 0;
        }
    } else { // if word is not in trie children check sibling
        if(sibling != nullptr) return sibling->searchWord(id, word, current);
        else return 0;
    }
    return 0;
}

int TrieNode::docSearchWord(std::string word, int current){

    if(word[current] == value){
        if(current == word.length()-1){
            if(list != nullptr) return list->volume();
            else return 0;
        }else{
            if(child != nullptr) return child->docSearchWord(word, current+1);
            else return 0;
        }
    }else {
        if(sibling != nullptr) return sibling->docSearchWord(word, current);
        else return 0;
    }

    return 0;
}