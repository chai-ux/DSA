#include <iostream>
using namespace std;

// Node class for singly linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor (optional)
    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

// Function to merge two sorted linked lists
Node* solve(Node* first, Node* second) {
    if (first->next == NULL) {
        first->next = second;
        return first;
    }

    Node* curr1 = first;
    Node* next1 = curr1->next;
    Node* curr2 = second;
    Node* next2;

    while (next1 != NULL && curr2 != NULL) {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data)) {
            // Insert curr2 between curr1 and next1
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            // Move curr1 and curr2 forward
            curr1 = curr2;
            curr2 = next2;
        } else {
            curr1 = next1;
            next1 = next1->next;

            // If we've reached the end of first list
            if (next1 == NULL) {
                curr1->next = curr2;
                return first;
            }
        }
    }

    return first;
}

// Wrapper function to handle order and edge cases
Node* sortTwoLists(Node* first, Node* second) {
    if (first == NULL) return second;
    if (second == NULL) return first;

    if (first->data <= second->data) {
        return solve(first, second);
    } else {
        return solve(second, first);
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function
int main() {
    // First sorted list: 1 -> 3 -> 5
    Node* first = new Node(1);
    first->next = new Node(3);
    first->next->next = new Node(5);

    // Second sorted list: 2 -> 4 -> 6
    Node* second = new Node(2);
    second->next = new Node(4);
    second->next->next = new Node(6);

    cout << "First List: ";
    printList(first);

    cout << "Second List: ";
    printList(second);

    Node* merged = sortTwoLists(first, second);

    cout << "Merged List: ";
    printList(merged);

    // Clean up memory
    delete merged;

    return 0;
}
