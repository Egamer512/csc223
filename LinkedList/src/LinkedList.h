#include <iostream>
using namespace std;

template <class T>
class Node{
    
    public:

    T cargo;
    Node<T>* next;

        Node(){
            //Empty Node
        }

        Node(T cargo, Node<T>* next){
            this->cargo = cargo;
            this->next = next;
        }

        T get_cargo() const{
            return cargo;
        }

        Node<T>* get_next() const{
            return next;
        }

        string to_str() const{
            return to_string(cargo);
        }
};

template <class T>
class LinkedList{
    int num_nodes;
    Node<T>* head;

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
            if (head == nullptr) throw runtime_error("List is Empty");
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

        T remove_item(int pos){
            if (head == NULL) throw runtime_error("List is Empty");
            if (pos == 1) return remove_from_front(); //if we're at the 1st position, just use the func we use already
            Node<T>* current = head;
            for(int i = 1; i < pos-1; i++){ // traversal right before the node we wanna remove
                current = current->next;
            }
            Node<T>* target = current->next;
            T cargo = target->cargo;
            current->next = target->next;
            delete target;
            num_nodes--;
            return cargo;            
        }

        string to_str() const{
            if (head == nullptr) return "Empty List";

            string s = "(";
            Node<T>* node = head;
            while (node != nullptr){
                s+= to_string(node->get_cargo());
                node = node->get_next();
                if (node != NULL) s+= ", ";
            }
            return s + ")";
        }

        int length() const{
            return num_nodes;
        }

        T get_item(int pos){
            Node<T>* target = head; //setting the pointer to the head
            for(int i = 0; i < pos; i++){
                target = target->next; //going through the linkedlist until the position we want
            }
            return target->cargo; // get the cargo
        }

        void insert_item(T cargo, int pos){
            Node<T>* start_node = head;
            for(int i = 0; i < pos; i++){
                start_node = start_node->next;
            }
            Node<T>* node = new Node<T>(cargo, start_node->next);
            start_node->next = node;

        }
   


};

/* 
template <class T>
class CLIST{
    int num_nodes;
    Node<T>* head;


    public:
    CLIST(){
        num_nodes = 0;
        head = nullptr;
    }

        void insert_at_front(T cargo){
        Node<T>* front = new Node<T>(cargo, head);
        head = front;
        num_nodes++;

        if(num_node > 1){
            NOde<T>* tail = head;
            while(tail->next != head->next){
                tail = tail-next;
            }
            tail-next = head;
        }
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
            
            Node<T>* tail = head;
            if(num_nodes > 1){
                for(int i = 0; i < num_nodes; i++){
                    tail = tail->next;
                }
            }
            tail->next = head;
            return cargo;
        }

};

*/