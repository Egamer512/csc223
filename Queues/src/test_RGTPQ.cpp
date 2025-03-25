#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include <string>
#include "RGTPQ.h"
using namespace std;

TEST_CASE("Insertion and Removal"){
    RGTPQ Queue;

    RGThing red1 {RED};
    RGThing red2 {RED};
    RGThing green1 {GREEN};
    RGThing red3 {RED};
    RGThing green2 {GREEN};

    CHECK(Queue.empty() == true);

    Queue.insert(red1);
    Queue.insert(red2);
    Queue.insert(green1);

    RGTpair pair1 = Queue.remove();
    CHECK(pair1.item1.color == RED);
    CHECK(pair1.item2.color == GREEN);


}