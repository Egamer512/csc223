#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest/doctest.h"
#include <string>
#include "LinkedList.h"
using namespace std;

TEST_CASE("Test creates and renders the list Nodes"){
    Node* node1 = new Node;
    CHECK(node1->cargo == 0);
}