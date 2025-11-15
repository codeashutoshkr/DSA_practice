#include<iostream>
#include<queue>
using namespace std;

class Node{

    public: 
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
         this->right = NULL;
    }
};

void levelOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            //purana level complete traverse has done
            cout<<endl;
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

Node* insertIntoBST(Node* root, int d){
    //base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d> root ->data){
        //right part me insert karna h
        root->right = insertIntoBST(root->right, d);
    }
    else{
        //left part
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

Node* deleteFromBST(Node* root, int val){
    //base case
    if(root==NULL){
        return root;
    }
    if(root->data == val){
        // 0 child
      if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
      }
        // 1 child
           // left child
           if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
           }
           // right child
            if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
           }
        // 2 child
        if(root->left!=NULL && root->right!= NULL){
            int mini = minVal(root->right ) -> data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if(root->data > val){
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right, val);
    }
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
       root = insertIntoBST(root, data);
        cin>>data;
    }
}

void inorder(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
Node* maxVal(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

int main(){

    Node* root = NULL;
    cout<<"Enter data to create BST "<<endl;
    takeInput(root);
    
    cout<<"Here's the BST \n";
    levelOrderTraversal(root);

    cout<<"Printing Inorder: \n"; inorder(root);
    cout<<"Printing Preorder: \n"; preorder(root);
    cout<<"Printing Postorder: \n"; postorder(root);

    return 0;
}