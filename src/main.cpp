#include <iostream>

#include "micro_search_engine.hpp"

int main(int argc, char **argv){
    std::cout << "Hello World!" << std::endl;

    if(argc!=5)
        std::cout << "Wrong Arguments" << std::endl;
    else 
        std::cout << "Correct Arguments" << std::endl;   
    return 0;
}