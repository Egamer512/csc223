#include "LinkedList.h"
#include <vector>
using namespace std;

template <class T>
class Stack
{
    LinkedList<T> items;

  public:
    void push(T item) {
        items.insert_at_front(item);
    }

    T pop() {
        if (empty())
           throw runtime_error("Can't pop from empty stack!");
        return items.remove_from_front();
    }

    bool empty() const {
        return items.length() == 0;
    }

    T top() {
       if (empty())
           throw runtime_error("Can't return top item of empty stack!");
       T top_item = items.remove_from_front();
       items.insert_at_front(top_item);
       return top_item; 
    }
};