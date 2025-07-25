#include <iostream>
using namespace std;

// Definition of linked list node
class Node {
public:
    int data;
    Node *next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

// Recursive helper function to propagate carry from right to left
bool add1(Node* head) {
    if (head == NULL)
        return true;  // initial carry = 1

    bool carry = add1(head->next);  // recursive call to end of list

    if (carry) {
        head->data += 1;
        if (head->data < 10)
            return false;  // no more carry needed
        else {
            head->data = 0;
            return true;   // carry forward
        }
    }
    return false;
}

// Function to add one to the number
Node* addOne(Node *head) {
    bool carry = add1(head);

    if (carry) {
        Node* temp = new Node(1);
        temp->next = head;
        head = temp;
    }

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
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
        Node* newNode = new Node(num % 10);
        newNode->next = head;
        head = newNode;
        num /= 10;
    }
    return head;
}

int main() {
    // Create linked list for number 999 (9->9->9)
    Node* head = createListFromNumber(999);

    cout << "Original Number: ";
    printList(head);

    head = addOne(head);

    cout << "After Adding One: ";
    printList(head);

    return 0;
}
