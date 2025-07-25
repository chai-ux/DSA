#include<iostream>
#include<stack>
using namespace std;

// Custom Stack class (not using std::stack)
class Stack {
public:
    int *arr;   // pointer to dynamically allocated array for stack elements
    int top;    // index of the top element
    int size;   // total capacity of the stack

    // Constructor to initialize stack
    Stack(int size) {
        this->size = size;   //create an array of given size
        arr = new int[size];
        top = -1;   // -1 means stack is empty
    }

    // Push operation → inserts an element on top
    void push(int element) {
        // Check if there is space in the stack
        if (size - top > 1) { 
            top++;           // move top pointer to next empty index
            arr[top] = element; // store the element
        } else {
            cout << "Stack Overflow" << endl; // No space left
        }
    }

    // Pop operation → removes the top element
    void pop() {
        if (top >= 0) { 
            top--;           // just decrease top pointer (no actual deletion needed)
        } else {
            cout << "Stack Underflow" << endl; // Stack already empty
        }
    }

    // Peek operation → returns the top element without removing it
    int peek() {
        if (top >= 0)
            return arr[top];  // return current top element
        else {
            cout << "Stack is Empty" << endl;
            return -1;  // return some default value
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        if (top == -1)
            return true;
        else
            return false;
    }
};

int main() {
    Stack st(5);  // create a stack of size 5

    // Push some elements
    st.push(3);
    st.push(4);
    st.push(67);

    // Peek → should print 67 (last pushed)
    cout << st.peek() << endl;

    // Pop → removes 67
    st.pop();

    // Peek again → should print 4
    cout << st.peek() << endl;

    // Check if empty → should print "Not Empty Stack"
    if (st.isEmpty())
        cout << "Empty Stack" << endl;
    else {
        cout << "Not Empty Stack" << endl;
    }

    // Pop → removes 4
    st.pop();
    cout << st.peek() << endl; // should print 3

    // Pop → removes 3
    st.pop();
    cout << st.peek() << endl; // now empty → prints "Stack is Empty"

    return 0;
}
