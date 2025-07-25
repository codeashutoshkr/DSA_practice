#include<iostream>
using namespace std;
// singly circular LL
class Node{
    public:
    int data;
    Node* next;
    // constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }    
    //destructor
    ~Node(){
      int value = this -> data;
      //memory free
      if(this->next != NULL){
        delete next;
        this -> next = NULL;
      }
      cout<<" Memory free for node with data "<<value<<endl;
    }  
};
void insertNode(Node* &tail, int element, int d){
    // empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
// non-empty list
// Assuming that the element is present in the list
         Node* curr = tail;
         while(curr-> data != element){
            curr = curr -> next;
         }
         // element found
         Node* temp = new Node(d);
         temp -> next = curr -> next;
         curr -> next = temp;
    }
}
void print(Node* tail){
    Node* temp = tail;

    if(tail == NULL){
        cout<<"List is empty "<<endl;
        return;
    }
   
    do{
        cout<<tail->data<<" ";
        tail = tail-> next;
    }
    while(tail != temp);
    cout<<endl;
}
    void deleteNode(Node* &tail, int value){
        // empty list
        if(tail == NULL){
            cout<<"List is empty, please check again "<<endl;
            return;
        }
        else{
            // non-empty
            // assuming that value is present in the list
            Node* prev = tail;
            Node* curr = prev -> next;
            while(curr-> data != value){
                prev = curr;
                curr = curr-> next;
            }
            prev-> next = curr -> next;
            // 1 node LL
            if(curr == prev){
                tail = NULL;
            }
            // >= 2 Node LL
            if(tail == curr){
                tail = prev;
            }
            curr -> next = NULL;
            delete curr;
        }
    }

int main(){
    Node* tail = NULL;
    insertNode(tail, 5 ,3);
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 7);
    print(tail);
    insertNode(tail, 7, 9);
    print(tail);
    insertNode(tail, 9, 18);
    print(tail);
    deleteNode(tail, 3);
    print(tail);

}