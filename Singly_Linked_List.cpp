#include<iostream>
using namespace std;

// Node class definition for singly linked list
class Node {
public:
    int data;  // stores the data in the node
    Node* next; //pointer to next node

    //constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    //destructor for deleting node and free memory
    ~Node()
    {
        int value = this->data;
        //memory free
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with data" << value << endl;
    }
};
// Function to insert a node at the beginning (head)
void insertAtHead(Node*& head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}
// Function to insert a node at the end (tail)
void insertAtTail(Node*& tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
// Function to print the linked list from head to end
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " "; // print node data
        temp = temp->next; //update temp
    }
    cout << endl;
}
// Function to insert a node at a specific position
void insertAtPosition(Node* &tail,Node* &head, int position,int d)
{
    //inserting at head
    if(position == 1){
    insertAtHead(head,d);
    return;
    }
    Node* temp = head;
    int cnt = 1;

    // Traverse to the node before the desired position
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

    // Inserting in the middle
    Node* nodeToInsert = new Node(d); // create new node
    nodeToInsert->next = temp->next;  // link new node to next node
    temp->next = nodeToInsert; // link previous node to new node
}
// Function to delete a node at a given position
void deleteNode(int position, Node* &head)
{
    if(position == 1)
    {
        Node* temp = head; // store head
        head = head->next; // move to next node
        temp->next = NULL; 
        delete temp; // delete node
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        // Traverse to the position
        while(cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        // Remove node from the list
        prev->next = curr->next;
        curr->next = NULL;
        delete curr; //free memory

    }
}
//Floyd Cycle Detection Algo:- returns meeting point if cycle exists
Node* floydDetectLoop(Node* head)
{
    if(head == NULL)
    return NULL;

    Node* slow = head; // moves one step
    Node* fast = head; // moves two steps

    // Traverse until end or cycle is detected
    while(slow!=NULL && fast!=NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast)
        {
            cout<< "Present at" << slow->data << endl;
            return slow; //cycle detected
        }
    }
    return NULL; // no cycle
}

Node* getStartingNode(Node* head)
{
    if(head == NULL)
    return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

void removeLoop(Node* head)
{
    if(head == NULL)
    {
        return;
    }

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp->next != startOfLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

int main() {
    // Create initial node
    Node* node1 = new Node(10);
    
    // Head and Tail both point to the first node
    Node* head = node1;
    Node* tail = node1;

    print(head);  

    insertAtTail(tail, 12);
    print(head);  

    insertAtTail(tail, 16);
    print(head);  

    insertAtHead(head, 5);
    print(head);  

    insertAtPosition(tail,head, 3, 22);
    cout<<"before deleting:- ";
    print(head);

    //insertAtPosition(tail,head, 2, 16);
    //print(head);

    //deleteNode(2,head);
    //cout<<"after deleting:- ";
    //print(head);

    //create a cycle
    tail->next = head->next->next;

    // Detect if loop exists
    if(floydDetectLoop(head) != NULL)
    {
        cout<<"Cycle is present" << endl;

    }
    else
    {
        cout<< "Cycle is not present"<< endl;
    }
    Node* loop = getStartingNode(head);
    cout<<"Starting node of cycle is:- " <<  loop->data << endl;

    removeLoop(head);
    print(head);

    return 0; 
}
