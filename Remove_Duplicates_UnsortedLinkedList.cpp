#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;

// Node class definition for singly linked list
class Node
{
public:
    int data;   // stores the data in the node
    Node *next; // pointer to next node

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
// Function to insert a node at the beginning (head)
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
// Function to insert a node at the end (tail)
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
// Function to print the linked list from head to end
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " "; // print node data
        temp = temp->next;         // update temp
    }
    cout << endl;
}
// Function to insert a node at a specific position
void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    // inserting at head
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;

    // Traverse to the node before the desired position
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // inserting at last position
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // Inserting in the middle
    Node *nodeToInsert = new Node(d); // create new node
    nodeToInsert->next = temp->next;  // link new node to next node
    temp->next = nodeToInsert;        // link previous node to new node
}

// Method 1:- Using Hashing (Unordered Map)

Node *removeDuplicates(Node *head)
{
    if (head == NULL)
        return head;

    unordered_map<int, bool> visited;

    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        if (visited[curr->data] == true)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
     return head;
}

//Method 2:- Bubble Sort the List, then Remove Adjacent Duplicates

void swapData(Node* a, Node* b)
{

    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort(Node* &head)
{
    if(head == NULL)
    return;

    bool swapped = true;
    Node* end = NULL;

    while(swapped)
    {
        swapped = false;
        Node* curr = head;
        while(curr->next != end)
        {
            if(curr->data > curr->next->data)
            {
            swapData(curr,curr->next);
            swapped = true;
            }
            curr = curr->next;
        }
        end = curr;
    }
}

Node* removeduplicates(Node* head)
{
    if(head == NULL)
    return head;

    bubbleSort(head);

    Node* curr = head;
    while(curr != NULL)
    {
    if((curr->next != NULL) && (curr->data == curr->next->data))
    {
        Node* nextnode = curr->next->next;
        Node* nodeToDelete = curr->next;
        delete(nodeToDelete);
        curr->next = nextnode;
    }
    else{
        curr = curr->next;
    }
   }
   return head;
}


int main()
    {
        // Create initial node
        Node *node1 = new Node(10);

        // Head and Tail both point to the first node
        Node *head = node1;
        Node *tail = node1;

        print(head);

        insertAtTail(tail, 10);
        print(head);

        insertAtTail(tail, 16);
        print(head);

        insertAtHead(head, 5);
        print(head);

        insertAtPosition(tail, head, 3, 22);
        cout << "Before Removing Duplicates:- ";
        print(head);

        removeDuplicates(head);
        cout<<"After Removing Duplicates:- ";
        print(head);

        return 0;
    }