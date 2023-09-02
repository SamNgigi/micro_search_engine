#include "ListNode.hpp"

void ListNode::add(int docId){
    if(docId == id) counter++;
    else{
        if(!next) next = std::make_unique<ListNode>(docId);
        next->add(docId);
    }
}