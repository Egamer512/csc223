using namespace std;

struct Node {
    int cargo;
    Node* next;

    Node();
    Node(int);
    Node(int, Node*);
}