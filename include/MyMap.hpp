#ifndef MYMAP_H
#define MYMAP_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <memory>

class MyMap{
    // int size; // number of documents
    // int buffersize; // length of the biggest document;
    std::vector<std::string> documents; // each document
    std::vector<int> lengths; // length of each map
    public:
        /* MyMap(int size, int buffersize) : size(size), buffersize(buffersize){
            documents.resize(size);
            lengths = std::make_unique<int>();
            for(int i=0; i<size; i++) documents[i] = std::string(buffersize, '\0');
        } */
        MyMap(int size): documents(size), lengths(size){}
        int insert(const std::string &line, int i);
        void setLengths(int id, int length){lengths[id] = length;}
        int getLengths(int id){return lengths[id];}
        void print(int i){std::cout << " " << documents[i] << "\n";}
        const int getsize(){return (int)documents.size();}
};
#endif // MYMAP_H