#include <iostream>
using namespace std;
#include "#LinkedList.h"

template <class T>
struct Stack:public LinkedList<T>{
    void push(T item){
        LinkedList<T>::insert_at_front(item);
    }
    T pop(){
        return LinkedList<T>::remove_from_front();
    }
};