#include <bits/stdc++.h>
using namespace std;

// Definition of linked list node
class Node {
public:
    int data;
    Node *next;
    Node *random;

    Node() : data(0), next(nullptr), random(nullptr) {}
    Node(int x) : data(x), next(nullptr), random(nullptr) {}
    Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
};

// Function to insert node at the tail of a linked list
void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to clone a linked list with random pointers
Node *cloneLL(Node *head) {
    // Step 1: Create a cloned list with same data
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    Node* temp = head;

    while (temp != NULL) {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // Step 2: Create a map from original nodes to clone nodes
    unordered_map<Node*, Node*> oldToNewNode;
    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while (originalNode != NULL) {
        oldToNewNode[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    // Step 3: Assign random pointers
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL) {
        if (originalNode->random != NULL)
            cloneNode->random = oldToNewNode[originalNode->random];
        else
            cloneNode->random = NULL;

        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
}

// Helper function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Data: " << temp->data << ", Random: ";
        if (temp->random)
            cout << temp->random->data;
        else
            cout << "NULL";
        cout << endl;
        temp = temp->next;
    }
}

// Sample main function for testing
int main() {
    // Creating a linked list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Setting random pointers
    head->random = head->next->next;         // 1's random -> 3
    head->next->random = head;               // 2's random -> 1
    head->next->next->random = head->next;   // 3's random -> 2

    cout << "Original List:\n";
    printList(head);

    // Clone the list
    Node* clonedList = cloneLL(head);

    cout << "\nCloned List:\n";
    printList(clonedList);

    return 0;
}
