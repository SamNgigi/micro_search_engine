#include "micro_search_engine.hpp"


void mysearch(std::vector<std::string> tokens, TrieNode* trie, MyMap* mymap, int k){
    std::cout << "Not implemented yet" << "\n";
}

void df(std::vector<std::string> tokens, TrieNode* trie){
    /**
     * @brief Returns how many document lines our word is in
     * 
     */
   

    if(tokens.size() == 2){
        std::string token = tokens[1]; // retrieve work after command
        std::cout << token << " " << trie->docSearchWord(token, 0) << "\n";
    }
    else{

        std::string buffer(256, '\0');
        trie->docSearchAll(buffer, 0);
    }

    // std::cout << "Not implemented yet" << "\n";
}

int tf(std::vector<std::string> tokens, TrieNode* mytrie){
    /**
     * @brief Returns the frequency of a token in a given document
     * 
     */
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
    std::cout << "Line #" << id << " " << tokens[2] <<  " " << mytrie->searchWord(id, tokens[2], 0) << "\n";
    return 0;
}