#include "LinkedList.h"
#include <vector>
#include <cctype>
#include <string>
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
    string item;
    while(ss >> item){
        exp_vector.push_back(item);
    }
    return exp_vector;
}

int eval_postfix_expr(const string& exp){
    vector<string> exp_vector = split_on_spaces(exp); // Full Expression in a Vector
    Stack<int> operands; // Stack of the operands
    for(const auto& item : exp_vector){
        if(isdigit(item[0])){
            operands.push(stoi(item));
        }else{
            int right = operands.pop();
            int left = operands.pop();

            if(item[0] == '+'){
                operands.push(left + right);
            }else if(item[0] == '-'){
                operands.push(left - right);
            }else if(item[0] == '*'){
                operands.push(left * right);
            }else{
                operands.push(left / right);
            }
        }
    }
    return operands.pop();
}