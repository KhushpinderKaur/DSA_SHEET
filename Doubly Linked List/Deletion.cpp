#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

// ARRAY TO DOUBLY LINKED LIST
Node *convertArray2DLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = prev->next; // prev = prev->next;
    }
    return head;
}

// DELETE HEAD
Node *deleteHead(Node *head)
{
    Node *prev = head;
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;

    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

// DELETE TAIL
Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node* tail = head;             //2 while loop method is also correct
    while(tail->next != nullptr){
        tail = tail->next;
    }
    
    Node* temp = tail->prev;      //previous of tail
    temp->next = nullptr;
    tail->prev = nullptr;
    return head;
}



//DELETE Kth ELEMENT
Node* deleteKth(Node* head, int k){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        if(count == k)  break;
        temp = temp->next;
    }
    Node* front = temp->next;
    Node* back = temp->prev;

    if(front == nullptr && back == nullptr){   //only one element
        delete temp;
        return NULL;
    }

    if(front == nullptr){    //at tail
        deleteTail(head);
        return head;
    }

    if(back == nullptr){     //at head 
        deleteHead(head);
        return head;
    }

    back->next = front;
    front->prev = back;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head; 
}


//DELETE GIVEN NODE
Node* deleteNode(Node* head, Node* temp){      //Constraint: temp != head
    Node* front = temp->next;
    Node* back = temp->prev;

    if(front == NULL){
        back->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return head;
    }

    back->next = front;
    front->prev = back;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

// PRINTING
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "  ";
        head = head->next;
    }
}

int main()
{
    vector<int> arr = {12, 3, 4, 5, 6, 7, 8, 2, 1, 9};

    Node *head = convertArray2DLL(arr);
   cout << "Doubly Linked List: ";
    print(head);

    head = deleteHead(head);
    cout << "\nDLL after deleting the head: ";
    print(head);

    head = deleteTail(head);
    cout << "\nDLL after deleting the tail: ";
    print(head);

    head = deleteKth(head, 3);
    cout << "\nDLL after deleting 3rd element: ";
    print(head);

    head = deleteNode(head, head->next->next);
    cout << "\nDLL after deleting node: ";
    print(head);

   return 0;
}