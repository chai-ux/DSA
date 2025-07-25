#include <iostream>
using namespace std;

// Node class for singly linked list
class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

// Function to insert a new node at the end
void insertAtTail(Node* &tail, int val) {
    Node* newNode = new Node(val);
    if (tail == NULL) {
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to sort the linked list of 0s, 1s and 2s
Node* sortList(Node *head) {
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;

    // Count the number of 0s, 1s, and 2s
    while(temp != NULL) {
        if(temp->data == 0)
            zeroCount++;
        else if(temp->data == 1)
            oneCount++;
        else if(temp->data == 2)
            twoCount++;
        temp = temp->next;
    }

    // Overwrite the node values
    temp = head;
    while(temp != NULL) {
        if(zeroCount > 0) {
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount > 0) {
            temp->data = 1;
            oneCount--;
        }
        else {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }

    return head;
}

// Main function to test the logic
int main() {
    // Create the linked list: 1 -> 2 -> 0 -> 1 -> 2 -> 0 -> 1
    Node* head = new Node(1);
    Node* tail = head;
    
    insertAtTail(tail, 2);
    insertAtTail(tail, 0);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 0);
    insertAtTail(tail, 1);

    cout << "Original List: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted List:   ";
    printList(head);

    return 0;
}
