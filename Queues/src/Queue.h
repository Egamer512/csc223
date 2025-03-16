#include "LinkedList.h"

template <class T>
class Queue : public LinkedList<T>
{
  public:
    // constructors
    Queue() = default;

    // modifiers
    void insert(T item) {
       if(LinkedList<T>::length() == 0){
        LinkedList<T>::insert_at_front(item); // adding for an empty queue
       }
       int i = 1; // looping to check whether or not item is less than an element (basically, we want to loop until the next max)
       while(i <= LinkedList<T>::length() && item < LinkedList<T>::get_item_at(i)){
        i++;
       }
       LinkedList<T>::insert_item_at(item, i -1);
    }

    T remove() {
        return LinkedList<T>::remove_from_front();
    }

    bool empty() {
        return (LinkedList<T>::length() == 0);
    }

};