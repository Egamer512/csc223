#include "LinkedList.h"
#include <vector>
using namespace std;

template <class T>
class Stack
{
    LinkedList<T> items;

  public:
    void push(T item) {
        items.insert_at_front(item);
    }

    T pop() {
        if (is_empty())
           throw runtime_error("Can't pop from empty stack!");
        return items.remove_from_front();
    }

    bool is_empty() const {
        return items.length() == 0;
    }

    T top() {
       if (is_empty())
           throw runtime_error("Can't return top item of empty stack!");
       T top_item = items.remove_from_front();
       items.insert_at_front(top_item);
       return top_item; 
    }
};

vector<string> split_on_spaces(string expression){
    stringstream ss(expression);
    vector<string> exp_vector;
    string token;
    while(ss >> token){
        exp_vector.push_back(token);
    }
    return exp_vector;
}

int eval_postfix_expr(const string& exp){
    
}