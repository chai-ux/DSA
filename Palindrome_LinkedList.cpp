#include <iostream>
using namespace std;

// Definition for singly-linked list.
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        this->data = val;
        this->next = NULL;
    }
};

class Solution {
private:
    // Function to get middle of the linked list
    Node* getMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    // Function to reverse a linked list
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    // Function to check if the linked list is a palindrome
    bool isPalindrome(Node* head) {
        if (head == NULL || head->next == NULL)
            return true;

        // Step 1: Find middle
        Node* middle = getMiddle(head);

        // Step 2: Reverse the second half
        Node* temp = middle->next;
        middle->next = reverse(temp);

        // Step 3: Compare both halves
        Node* head1 = head;
        Node* head2 = middle->next;
        while (head2 != NULL) {
            if (head1->data != head2->data) {
                // Restore list before returning
                temp = middle->next;
                middle->next = reverse(temp);
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // Step 4: Restore the original list
        temp = middle->next;
        middle->next = reverse(temp);

        return true;
    }
};

// Utility function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Utility function to insert at the end
void insertAtTail(Node*& tail, int val) {
    Node* newNode = new Node(val);
    tail->next = newNode;
    tail = newNode;
}

// Main function to test
int main() {
    // Create linked list: 1 -> 2 -> 3 -> 2 -> 1
    Node* head = new Node(1);
    Node* tail = head;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    bool result = obj.isPalindrome(head);

    if (result)
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is not a palindrome." << endl;

    // Clean up memory
    delete head;

    return 0;
}
