#ifndef MYMAP_H
#define MYMAP_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class MyMap{
    int size; // number of documents
    int buffersize; // length of the biggest document;
    std::vector<std::string> documents; // each document
    std::unique_ptr<int> lengths; // length of each map
    public:
        MyMap(int size, int buffersize) : size(size), buffersize(buffersize){
            documents.resize(size);
            lengths = std::make_unique<int>();
            for(int i=0; i<size; i++) documents[i] = std::string(buffersize, '\0');
        }
        int insert(std::string line, int i);
        const int getsize(){return size;}
        const int getbuffersize(){return buffersize; }
        ~MyMap(){}
};
#endif // MYMAP_H