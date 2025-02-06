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

        T remove_from_front(){
            if (head == NULL) throw runtime_error("List is Empty");

            //Okay so basically the T cargo is the next element in the Linked List
            T cargo = head->cargo;

            // Pointer front is now the head, or first element
            Node<T>* front = head;

            //the head is now the second element, so the first element is no longer in the list
            head = head->next;
            // delete the pointer
            delete front;
            // reduce the number of nodes
            num_nodes--;
            return cargo;
        }

        string to_str() const{
            string s = "(";
            Node<T>* node = head;
            while (node != NULL){
                
            }
        }




};

