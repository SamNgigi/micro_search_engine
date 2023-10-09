#include <iostream>
#include <memory>
#include <fstream>
#include <string>

#include "micro_search_engine.hpp"
#include "read_input.hpp"
#include "TrieNode.hpp"
#include "utils.hpp"

/* int input(std::string input, TrieNode* trie, MyMap* mymap, int k){
    std::vector<std::string> tokens = tokenize(input, "\t\n");
    return 1;
} */

int input_manager(std::string input, TrieNode* mytrie, MyMap* mymap, int k){
    // char* token = strtok(input.data(), " \t\n");
    std::vector<std::string> tokens = tokenize(input, " \t\n");
    if(tokens[0].compare("/search") == 0) mysearch(tokens, mytrie, mymap, k);
    else if(tokens[0].compare("/df") == 0) df(mytrie);
    else if(tokens[0].compare("/tf") == 0){
        if(tf(tokens, mytrie) == -1) return -1;
    }
    else  if(tokens[0].compare("/exit") ==0 ){
        std::cout << "Exiting ..." << "\n";
        return 2;
    } else return -1;
    
    return 1;
}

int main(int argc, char **argv){
    std::cout << "Hello World!" << std::endl;

    if(argc!=5 || std::strcmp(argv[1], "-d") || std::strcmp(argv[3], "-k")){
        std::cout << "Wrong Arguments" << std::endl;
        return -1;
    }
    std::cout << "Please Wait..." << std::endl;
    int linecounter = 0;
    int maxLength = -1;
    int k = std::atoi(argv[4]);
    if(read_sizes(&linecounter, &maxLength, argv[2]) == -1) return -1;
    
    auto mymap = std::make_unique<MyMap>(linecounter); // initializes map size to lines in document e.g 3 for sample data
    auto mytrie = std::make_unique<TrieNode>();
    if(read_input(mymap.get(), mytrie.get(), argv[2]) == -1){
        return -1;
    }
    std::cout << "Database Ready" << std::endl;
    std::string input = "";
    size_t input_len = 0;
    while(1){
        std::getline(std::cin, input);
        int result = input_manager(input, mytrie.get(), mymap.get(), k);
        if(result == -1) std::cout << "Wrong input" << std::endl;
        else if(result == 2) break;

    }

    return 0;
}