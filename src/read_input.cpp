#include "read_input.hpp"
#include "MyMap.hpp"
#include "utils.hpp"


int read_sizes(int *lineCounter, int *maxLength, std::string docFile){
    std::ifstream file(docFile);
    if(!file){
        std::cerr << "Error Opening File\n";
        return -1;
    }
    std::string line;
    while(std::getline(file, line)){
        // > intialization time
        // < memory management
        // maxLength is the length of longest line
        // When we find a line longer than maxLength we update maxLength
        if(*maxLength < (int)line.length()) *maxLength = (int)line.length(); // count how many lines we have
        (*lineCounter)++;
        // line=nullptr;
    }
    file.close();
    if(*lineCounter==0 ||  *maxLength < 6){ // no line or fewer that 6 characters
        std::cerr << "Document is too empty & does not meet requirements.\n";
        return -1;
    }
    return 1;
}

void split(std::string temp, int id, TrieNode* trie, MyMap* mymap){
    std::vector<std::string> tokens = tokenize(temp, " \t");
    // std::cout << tokens[0] << "\n";
    int i = 0;
    for(auto token : tokens){
        i++;
        // std::cout << token << " , ";
        trie->insert(token, id);
    }
    // mymap->setLengths(id, i);
}

int read_input(MyMap *mymap, TrieNode* trie, std::string docFile){
    std::fstream file;
    std::string line;
    std::string temp;
    file.open(docFile, std::ios::in);
    for(int i=0; i<mymap->getsize(); i++){
        std::getline(file, line);
        if(mymap->insert(line, i) == -1){
            std::cerr << "Document does not meet the requirements\n";
            return -1;
        }
        // std::cout << "Document met requirements\n";
        temp = mymap->getDocument(i);
        // std::cout << temp << "\n";
        split(temp, i, trie, mymap);
    }
    file.close();
    std::cout << "Document Processed\n";
    return 1;
}

