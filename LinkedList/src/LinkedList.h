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

string render_list(Node* list);

string render_list_backward(Node* list);

string render_pretty(Node* list, string (*list_renderer)(Node*));