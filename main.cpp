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

int main(){
    
    Node* node1 = new Node(1, nullptr);
    Node* node2 = new Node(2, nullptr);
    Node* node3 = new Node(3, nullptr);

    node1->next = node2;
    node2->next = node3;

    string render_list(Node* list) {
        Node* node = list;
        string s = "";
        while (node != nullptr){
            s += node.to_string();
            node = node.next;
            if (node != nullptr)
                s += ", ";

        }
        return s;
    };


    cout << node1->to_str() << endl;

    return 0;
}