#include<iostream>
using namespace std;
class Node
{
public:
int data;
Node* next;
//constuctor
Node(int data)
{
    this->data = data;
    this->next = NULL;
}
};
//inserting node at head
void insertAtHead(Node*& head,int d)
{
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}
//inserting node at tail
void insertAtTail(Node*& tail,int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
//function to print the head 
void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
//deleting the node
void deleteNode(int position, Node*& head)
{
   if(position == 1)
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtHead(head,20);
    print(head);
     
    insertAtTail(tail,30);
    print(head);

    deleteNode(2,head);
    print(head);
    return 0;
}






