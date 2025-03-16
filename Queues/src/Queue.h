#include "LinkedList.h"

template <class T>
class Queue : public LinkedList<T>
{
  public:
    // constructors
    Queue() = default;

    // modifiers
    void insert(T item) {
       if(empty()){
        LinkedList<T>::insert_at_front(item); // adding for an empty queue
        return; //without this return statement, the item would be added twice in an empty list!
       }
       int i = 1; // looping to check whether or not item is less than an element (basically, we want to loop until the next max)
       while(i <= LinkedList<T>::length() && item < LinkedList<T>::get_item_at(i)){
        i++;
       }
       LinkedList<T>::insert_item_at(item, i -1);
    }

    T remove() {
        if (empty()) {
            throw std::underflow_error("Can't remove from empty queue");
        }       
        return LinkedList<T>::remove_from_front();
    }

    bool empty() {
        return (LinkedList<T>::length() == 0);
    }

};