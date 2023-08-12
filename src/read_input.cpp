#include "read_input.hpp"

int read_sizes(int *lineCounter, int *maxLength, char *docFile){
    std::fstream file;
    file.open(docFile, std::ios::in); // open file in read mode;
    if(!file){
        std::cerr << "Error Opening File" << std::endl;
        return -1;
    }
    std::string line;
    // int maxLength = 0;
    while(std::getline(file, line)){
        // > intializatin time
        // < memory management
        // maxLength is the length of longest line
        // When we find a line longer than maxLength we update maxLength
        if(*maxLength < (int)line.length()) *maxLength = (int)line.length(); // count how many lines we have
        (*lineCounter)++;
        // line=nullptr;
    }
    file.close();
    if(*lineCounter==0 ||  *maxLength < 6){ // no line or fewer that 6 characters
        std::cout << "Document is too empty & does not meet requirements." << std::endl;
        return -1;
    }
    return 1;
} 


