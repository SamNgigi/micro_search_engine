#include "read_input.hpp"


int read_sizes(int *lineCounter, int *maxLength, std::string docFile){
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
        std::cout << "Document is too empty & does not meet requirements.\n";
        return -1;
    }
    return 1;
}


int read_input(std::unique_ptr<MyMap> &mymap, std::string docFile){
    std::fstream file;
    std::string line;
    file.open(docFile, std::ios::in);
    for(int i=0; i<mymap->getsize(); i++){
        std::getline(file, line);
        if(mymap->insert(line, i) == -1){
            std::cout << "Document does not meet the requirements\n";
            file.close();
            return -1;
        }
    }
    file.close();
    return 1;
}

