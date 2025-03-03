#include <iostream>
using namespace std;
#include "LinkedList.h"

template <class T>
class Stack{
    int top_item;
    T items[MAX_SIZE];

    
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
        if(is_empty())
            throw runtime_error("Can't return the top item of an empty list")
        T top_item = items.remove_from_front();
        items.insert_at_front();
        return top_item;
    }
};