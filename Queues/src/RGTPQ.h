#include "NormalQueue.h"
#include <string>
#include <stdexcept>

using namespace std;

enum Color {RED, GREEN}; // Our two colors

struct RGThing {
    Color color;
    string label;
};

struct RGTpair {
    RGThing item1;
    RGThing item2;
};