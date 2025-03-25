#include "NormalQueue.h"
#include <string>
#include <stdexcept>

using namespace std;

enum Color {RED, GREEN}; // Our two colors

struct RGThing { // this is the like the datatype we're going to be using 
    Color color; 
};

struct RGTpair {
    RGThing item1;
    RGThing item2;
};

class RGTPQ{
    private:
    NormalQueue<RGThing> red_queue;
    NormalQueue<RGThing> green_queue;

    public:
    bool empty(){
        return red_queue.empty() && green_queue.empty();
    }

    // simple insert function which checks the color of the item and inserts it to the proper queue
    void insert(RGThing item){
        if(item.color == RED){
            red_queue.insert(item);
        }else{
            green_queue.insert(item); // only red and green, so we use else
        }
    }

    RGTpair remove(){
        if (red_queue.empty() || green_queue.empty()){ // this case checks if one of the queues are empty, if that is true, then we can't remove 
            throw std::underflow_error("Can't remove from a pair because at least one color is empty");
        }

        // creating a new pair, and then we set the items to the removal of each queue because the remove function returns the item being removed!
        RGTpair pair;
        pair.item1 = red_queue.remove();
        pair.item2 = green_queue.remove();
        return pair;
    }


};