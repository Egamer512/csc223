#include <iostream>
using namespace std;

template <class T>
class Node{
    T cargo;
    Node<T>* next;

    public:
        Node(T cargo, Node<T>* next){
            this->cargo = cargo;
            this->next = next;
        }
};

