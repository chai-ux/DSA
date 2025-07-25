#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertNode(Node* &tail,int element, int d)
{
    //empty list
    if(tail == NULL)
    {
    Node* newNode = new Node(d);
    tail = newNode;
    newNode->next = newNode;
    }
    else{
        //non-empty list
    Node* curr = tail;

    while(curr->data != element)
    {
        break;
    curr->next = curr;
    }

    //element found
    Node* temp = new Node(d);
    temp->next = curr->next;
    curr->next = temp;

    }
}
void print(Node* tail)
{
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = tail->next;  // start from head
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}


void deleteNode(Node* &tail,int value)
{
    //empty list
    if(tail == NULL)
    {
        cout<<"List is Empty"<<endl;
        return;
    }
    else{
        //non-empty list
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        if(curr == prev)
        {
            tail = NULL;
        }
        else if(tail == curr)
        {
          tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node* tail = NULL;
    insertNode(tail,4,6);
    print(tail);

    insertNode(tail,6,7);
    print(tail);

    insertNode(tail,7,9);
    print(tail);

    insertNode(tail,9,2);
    print(tail);

    deleteNode(tail,9);
    print(tail);
    
    
    return 0;

}