#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
#include <string>
#include <vector>

class ListNode{
    std::unique_ptr<ListNode> next; // next list item;
    int id;                         // document id 
    int counter;                    // how many time string appears to specific doc (line entry)

    public:
        ListNode(int docId): id(docId), counter(0), next(nullptr){}
        void add(int docId);

};

#endif //LISTNODE_H