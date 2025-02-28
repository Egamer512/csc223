#include <iostream>
using namespace std;
#include "LinkedList.h"

template <class T>
class Stack{
    LinkedList<T> items;
    public:
    void push(T item){
        items.insert_at_front(item);
    }
    T pop() {
        if (is_empty()){
            throw runtime_error("Can't remove an empty list(Stack)!")
        }
        return items.remove_from_front();
    }
    bool is_empty() const{
        return items.length() == 0;
    }
    T top(){
        ig
    }
};