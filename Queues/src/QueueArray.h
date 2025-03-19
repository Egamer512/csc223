#ifndef QUEUE_H
#define QUEUE_H
#define MAX_SIZE 1024
#include <stdexcept>

template <class T>
class Queue {
    int first;
    int last;
    T items[MAX_SIZE];

public:
    Queue() {
        first = 0;
        last = 0;
    }

    void insert(const T& value) {
        if ((last) == MAX_SIZE) {
            throw std::overflow_error("No more space in queue");
        }
        int pos = last;
        while(pos > first && items[pos - 1] < value){ // Check to see if we are able to go further down the list, and check if the element before the element of the index is less than our value
            items[pos] = items[pos - 1]; // Set the element that we were on to the element after it, so we're shifting hte numbers down
            pos--; // shifting the elements to the right until the correct spot is found
        }
        items[pos] = value;
        last++;
    }

    T remove() {
        if (empty()) {
            throw std::underflow_error("Can't remove from empty queue");
        }
        int oldfirst = first;
        first = (first + 1) % MAX_SIZE;
        return items[oldfirst];
    }

    bool empty() const {
        return first == last;
    }
};
#endif // QUEUE_H