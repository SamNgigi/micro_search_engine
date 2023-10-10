#include "micro_search_engine.hpp"


void mysearch(std::vector<std::string> tokens, TrieNode* trie, MyMap* mymap, int k){
    std::cout << "Not implemented yet" << "\n";
}

void df(TrieNode* trie){
    std::cout << "Not implemented yet" << "\n";
}

int tf(std::vector<std::string> tokens, TrieNode* mytrie){
    // std::vector<std::string> tokens2 = std::vector<std::string>(tokens.begin()+1, tokens.end());
    if(tokens.size() < 2){
        std::cerr << "Not enough arguments. Number & string needed.\n";
        return -1;
    }
    if(!isDigit(tokens[1])){
        std::cerr << "Invalid second arguments: Needs to be a digit.\n";
        return -1;
    }
    int id = std::stoi(tokens[1]);
    if(tokens.size() < 3){
        std::cerr << "Not enough arguments. String needed\n";
        return -1;
    }
    std::cout << "Not implemented yet" << "\n";
    return 0;
}