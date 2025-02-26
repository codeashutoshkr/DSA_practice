#include<iostream>
using namespace std;
                          //   implementation in singly linked list
class Node{
    public:
    int data;
    Node* next;
    // constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }      
};
    // insertion at head
      void insertAtHead(Node* &head, int d){
        // new node create
        Node* temp = new Node(d);
        temp -> next = head;
        head = temp;
      }
      //insert at tail
      void insertAtTail(Node* &tail, int d){
        // new node create
        Node* temp = new Node(d);
        tail -> next = temp;
        tail = temp;
      }
      // insert at a position
      void insertAtPosition(Node* &tail, Node* &head, int position, int d){
        // insert at head
        if(position == 1){
          insertAtHead(head, d);
          return;
        }

        Node* temp = head;
        int cnt = 1;
        while(cnt < position-1){
          temp = temp->next;
          cnt++;
        }
        // insert at last position
        if(temp -> next == NULL){
          insertAtTail(tail, d);
          return;
        }
        // creating  a node for d
        Node* nodeToInsert = new Node(d);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
      }


      void print(Node* &head){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp -> data<<" ";
            temp = temp->next;
        }
        cout<<endl;
      }


int main(){

    // create a new node
    Node* node1 = new Node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
    // head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);
    
    insertAtHead(head, 12); // insertion at head
    print(head);

    insertAtHead(head, 15); // insertion at head
    print(head);

    insertAtTail(tail, 12); // insertion at tail
    print(head);

    insertAtTail(tail, 15); // insertion at tail
    print(head);

    insertAtPosition(tail, head, 3, 99); // insertion at position
    print(head);
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    return 0;

}