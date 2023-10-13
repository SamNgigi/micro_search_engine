#include "ListNode.hpp"

void ListNode::add(int docId){
    if(docId == id)counter++;
    else{
        if(next == nullptr) next = std::make_unique<ListNode>(docId);
        next->add(docId);
    }
}


int ListNode::search(int docId){
    if(docId == id) return counter;
    else {
        if(next == nullptr) return 0;
        else return next->search(docId);
    }
}

int ListNode::volume(){
    if(next != nullptr) return 1 + next->volume();
    else return 1;
}