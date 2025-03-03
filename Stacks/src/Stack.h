#include <iostream>
using namespace std;
#include "LinkedList.h"
#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 128
#include <stdexcept>

template <class T>
class Stack{
    int top_item;
    T items[MAX_SIZE];

    
    public:

    Stack(){
        top_item = -1;
    }

    

    void push(const T& item){
        if (top_item >= MAX_SIZE -1){
            throw std::overflow_error("Stack Overflow");
        }
        items[++top_item] = value;
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


#endif // STACK_H
