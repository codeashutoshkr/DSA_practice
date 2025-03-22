#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
};
// traversing a LL
   void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
   }
// to get the length of LL
   int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
   }
   // insert at head
   void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
   }
   // insert at tail
   void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
   }

   int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    print(head);
    cout<<getLength(head)<<endl;
    insertAtHead(head, 11);
    print(head);
    insertAtHead(head, 15);
    print(head);
    insertAtTail(head, 25);
    print(head);
    
   }
 