#include <iostream>
using namespace std;

struct Node {
    int cargo;
    Node* next;

    Node();
    Node(int);
    Node(int, Node*);

    string to_str() const;

};