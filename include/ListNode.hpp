#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
#include <string>
#include <vector>

class ListNode{

    friend class TrieNode;

    int id;                         // document id 
    int counter;                    // how many time string appears to specific doc (line entry)
    std::unique_ptr<ListNode> next; // next list item;

    public:
        ListNode(int docId): id(docId), counter(0), next(nullptr){}
        void add(int docId);
        int search(int id);

};

#endif //LISTNODE_H