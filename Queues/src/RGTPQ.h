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


};