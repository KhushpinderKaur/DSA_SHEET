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


//INSERTING AT THE HEAD 
Node* insertAtHead(Node* head, int X){
     Node* newNode = new Node(X, head, nullptr);
     if(head == NULL){
        return newNode;
     }
     head->prev = newNode;
     head = newNode;
     return newNode;
}


//INSERTING AT TAIL
Node* insertAtTail(Node* head, int X){
    Node* newNode = new Node(X);
    Node* tail = head;
    if(head == NULL){
        return newNode;
    }
    while(tail->next != NULL){
        tail = tail->next;
    }
    newNode->prev = tail;
    tail->next = newNode;
    return head;
}



//INSERTING AT Kth POSITION
Node* insertAtK(Node*head, int X, int k){
     Node* newNode = new Node(X);
     if(head == nullptr){
        return newNode;
     }

     if(k == 1){
         newNode->next = head;
         head->prev = newNode;
         head = newNode;
         return head;
     }

     Node* temp = head;
     int count = 0;
     while(temp != NULL){
        count++;
        if(count == k-1)   break;
        temp = temp->next;
     }
     
     //k is greater than length of list.
     if(temp == nullptr){
        return head; 
     }

    Node* front = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = front;
    front->prev = newNode;
    return head; 
}


//INSERT BEFORE A GIVEN NODE
void insertBeforeNode(Node* node, int val){     //never at starting
    Node* back = node->prev;
    Node* newNode = new Node(val, node, back); 
    back->next = newNode;
    node->prev = newNode;
}


//PRINTING
void print(Node* head){
   while(head != NULL){
      cout << head->data << " ";
      head = head->next;
   }
}

int main(){
   vector<int> arr = {12,3,4,5,6,7,8,9};
   Node *head = convertArray2DLL(arr);
   cout << "Doubly Linked List: ";
   print(head);

   head = insertAtHead(head,10);
   cout << "\nDLL after inserting at head: ";
   print(head);

   head = insertAtTail(head,10);
   cout << "\nDLL after inserting at tail: ";
   print(head);

   head = insertAtK(head, 15, 3);
   cout << "\nDLL after inserting at Kth position: ";
   print(head);

   insertBeforeNode(head->next, 20);
   cout << "\nDLL after inserting before given node: ";
   print(head);

}