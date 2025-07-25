#include <iostream>
using namespace std;

// Linked list node definition
struct Node {
    int data;
    Node* next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to reverse a linked list
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to insert a node at the head of a linked list
void insertAtHead(Node*& head, int digit) {
    Node* newNode = new Node(digit);
    newNode->next = head;
    head = newNode;
}

// Function to add two reversed linked lists and return the result (no reverse needed)
Node* add(Node* num1, Node* num2) {
    int carry = 0;
    Node* ansHead = NULL;

    while (num1 != NULL || num2 != NULL || carry != 0) {
        int val1 = (num1 != NULL) ? num1->data : 0;
        int val2 = (num2 != NULL) ? num2->data : 0;

        int sum = carry + val1 + val2;
        int digit = sum % 10;
        carry = sum / 10;

        insertAtHead(ansHead, digit);

        if (num1 != NULL) num1 = num1->next;
        if (num2 != NULL) num2 = num2->next;
    }

    return ansHead;
}

// Final function to add two numbers represented by linked lists
Node* addTwoLists(Node* num1, Node* num2) {
    // Step 1: Reverse both input lists
    num1 = reverse(num1);
    num2 = reverse(num2);

    // Step 2: Add both lists and return result (already in correct order)
    Node* result = add(num1, num2);
    return result;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from a number
Node* createListFromNumber(int num) {
    if (num == 0)
        return new Node(0);

    Node* head = NULL;
    while (num > 0) {
        insertAtHead(head, num % 10);
        num /= 10;
    }
    return head;
}

// Main function to test the implementation
int main() {
    // Example: num1 = 243, num2 = 564 → Output: 807
    Node* num1 = createListFromNumber(243);
    Node* num2 = createListFromNumber(564);

    cout << "Number 1: ";
    printList(num1);
    cout << "Number 2: ";
    printList(num2);

    Node* result = addTwoLists(num1, num2);

    cout << "Sum: ";
    printList(result);

    return 0;
}
