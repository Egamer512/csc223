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
        items[++top_item] = item;
    }

    T pop() {
        if (is_empty()){
            throw runtime_error("Can't remove an empty list(Stack)!");
        }
        return items[top_item--];
    }
    bool is_empty() const{
        return top_item == -1;
    }

    const T& top() const {
        if (is_empty()) {
            throw std::underflow_error("Stack is empty");
        }
        return items[top_item];
    }

    size_t size() const {
        return top_item + 1;
    }
};

#endif // STACK_H
