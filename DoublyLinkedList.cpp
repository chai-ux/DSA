#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        //memory free
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with data:- " << value << endl;
    }
};
void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<< temp->data<< " ";
        temp = temp->next;
    }
    cout<< endl;
}
int getLength(Node* head)
{
    int len = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void insertAtHead(Node* &head, int d)
{
    Node* temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertAtTail(Node* &tail, int d)
{
    Node*temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void insertAtPosition(Node* &head,Node* &tail,int position,int d)
{
    //inserting at first position
     if(position == 1){
        insertAtHead(head,d);
        return;
        }
        Node* temp = head;
        int cnt = 1;
        while(cnt < position - 1){
            temp = temp->next;
            cnt++;
        }
    //inserting at last position
        if(temp->next == NULL)
        {
            insertAtTail(tail,d);
            return;
        }
        Node* nodeToInsert = new Node(d);
        nodeToInsert->next = temp->next;
        temp->next->prev = nodeToInsert;
        temp->next = nodeToInsert;
        nodeToInsert->prev = temp;
}
void deleteNode(int position, Node* &head)
{
    if(position == 1)
    {
        Node* temp = head;
        if (temp->next != NULL)
            temp->next->prev = NULL;
        head = temp->next;
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
        curr->prev = NULL;
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
    //cout<< getLength(head)<< endl;
    insertAtHead(head, 12);
    print(head);
    insertAtHead(head, 16);
    print(head);
    insertAtTail(tail, 15);
    print(head);
    insertAtPosition(head,tail,3,22);
    print(head);
    deleteNode(4,head);
    print(head);
    
    
    return 0;
}