#include <iostream>
#include <memory>
#include <fstream>

#include "micro_search_engine.hpp"
#include "read_input.hpp"

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
    
    std::cout << "Initialization Finished" << std::endl;
    std::cout << "Linecouter: " << linecounter << std::endl << "MaxLength: " << maxLength << std::endl; 

    return 0;
}