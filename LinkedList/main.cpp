#include <iostream>
using namespace std;

struct Node {
    int cargo;
    Node* next;

    Node() {
        cargo = 0;
        next = nullptr;
    }

    Node(int cargo) {
        this->cargo = cargo;
        next = nullptr;
    }

    Node(int cargo, Node* next) {
        this->cargo = cargo;
        this->next = next;
    }

    string to_str() const {
        return to_string(cargo);
    }


};

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

// Okay this function is basically making us forget about the second node
Node* remove_second(Node* list){
    Node* first = list;
    Node* second = list->next;

    first->next = second->next;

    second->next = nullptr;
    return second;
}

int main(){
    
    Node* node1 = new Node(1, nullptr);
    Node* node2 = new Node(2, nullptr);
    Node* node3 = new Node(3, nullptr);

    node1->next = node2;
    node2->next = node3;

    cout << render_list(node1) << endl;
    remove_second(node1);
    cout << render_list(node1) << endl;
    return 0;
}