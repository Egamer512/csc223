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
        LinkedList<T>::insert_at_front(item);
       }
    }

    T remove() {
        return LinkedList<T>::remove_from_front();
    }

    bool empty() {
        return (LinkedList<T>::length() == 0);
    }

    void insert_in_order(T item){
        for(int i = 0; i < LinkedList<T>::length(); i++){
            T element = LinkedList<T>::get_item_at(i);
            if(item < element){
                LinkedList<T>::insert_item_at(i);
            }
        }
    }


};