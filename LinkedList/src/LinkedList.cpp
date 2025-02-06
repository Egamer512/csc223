#include "LinkedList.h"
#include <iostream>
using namespace std;
/*
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


string render_list_backward(Node* list){
    if(!list) return "";

    if(!list->next) return to_string(list->cargo);

    return render_list_backward(list->next) + ", " + to_string(list->cargo);

    
}

string render_pretty(Node* list, string (*list_renderer)(Node*)) {
    return "(" + list_renderer(list) + ")";
}
*/