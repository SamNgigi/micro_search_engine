#include <iostream>
#include <memory>
#include <fstream>

#include "micro_search_engine.hpp"
#include "read_input.hpp"
#include "TrieNode.hpp"
#include "utils.hpp"

int input(std::string input, TrieNode* trie, MyMap* mymap, int k){
    std::vector<std::string> tokens = tokenize(input, "\t\n");
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
    std::cout << "Initialization Finished" << std::endl;
    for(int i=0; i<mymap->getsize(); i++){
        mymap->print(i);
    }
    std::cout << "Linecouter: " << linecounter << std::endl << "MaxLength: " << maxLength << std::endl; 

    return 0;
}