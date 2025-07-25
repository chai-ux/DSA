#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
//print the head
void printH(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout<< endl;
}
//print the tail
void printT(Node* tail) {
    Node* temp = tail;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
//insert node at head
void insertAtHead(Node* &head, int data)
{
    Node* temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
//insert node at tail
void insertAtTail(Node* &tail,int data)
{
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
//delete a node



int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    printH(head);
    insertAtHead(head,13);
    printH(head);
    insertAtTail(tail,15);
    printT(tail);
}