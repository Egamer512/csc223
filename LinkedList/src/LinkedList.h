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

template <class T>
class LinkedList{
    int num_nodes;
    Node<T> head;

    public:
        LinkedList(){
            num_nodes = 0;
            head = nullptr;
        }

        LinkedList(T cargo){
            num_nodes = 1;
            head = new Node<T>(cargo, NULL);
        }

        void insert_at_front(T cargo){
            Node<T>* front = new Node<T>(cargo, head);
            head = front;
            num_nodes++;
        }


};

