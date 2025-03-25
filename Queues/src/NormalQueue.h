#include "LinkedList.h"

template <class T>
class NormalQueue : public LinkedList<T>
{
  public:
    // constructors
    NormalQueue() = default;

    // modifiers
    void insert(T item) {
        LinkedList<T>::insert_at_end(item);
    }

    T remove() {
        if(empty()){
            throw std::underflow_error("can't remove from an empty queue");
        }
        return LinkedList<T>::remove_from_front();
    }

    bool empty() {
        return (LinkedList<T>::length() == 0);
    }
};