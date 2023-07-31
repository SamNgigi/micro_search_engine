#include <iostream>
#include <memory>
#include <fstream>

#include "micro_search_engine.hpp"

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
    
    std::fstream file;
    file.open(argv[2], std::ios::in); // open in read mode
    if(!file) std::cerr << "Error opening file" << std::endl; 
    file.close();
    return 0;
}