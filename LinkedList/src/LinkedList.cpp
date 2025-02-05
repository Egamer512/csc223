#include "LinkedList.h"
#include <iostream>
using namespace std;

Node::Node(){
    cargo = 0;
    next=nullptr;

}

Node::Node(int cargo){
    this->cargo = cargo;
    next = nullptr;
}

Node::Node(int cargo, Node* next){
    this->cargo = cargo;
    this->next = next;
}

string Node::to_str() const {
    return to_string(cargo);
}


    string render_list(Node* list) {
    Node* node = list;
    string s = "";
    while (node != nullptr){
        s += node->to_str();
        node = node->next;
        if (node != nullptr)
            s += ", ";
        }
        return s;
    }


string render_list_backward(Node* list, string s=""){
    if(list == nullptr) return "";
    Node* head = list;
    Node* tail = list->next;
    s = render_list_backward(tail, s) + s;
    if(head ->next != nullptr){
        s += ", ";
    }
    s+= head->to_str();
    return s;
}

