/*You're given a BST and a target value. You need to find out 
whether there exists a pair of node values in the BST,
such that their sum is equal to the target value.
>>Follow-Up: Can you solve this in O(N) time, and O(H) space complexity?*/

#include<iostream>
#include<vector>
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

void inorder(Node* root, vector<int> &in){
    if(root==NULL){
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

bool twoSumInBST(Node*root, int target){
    vector<int> inorderVal;
    // stores inorder-> sorted values
    inorder(root, inorderVal);

    //use 2 pointer approach to check if pair exists
    int i=0, j= inorderVal.size()-1;

    while(i<j){
        int sum = inorderVal[i] + inorderVal[j];
        if(sum == target){
            return true;
        }
        else if(sum > target){
            j--;
        }
        else{
            i++;
        }
       
    }
     return false;
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

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
       root = insertIntoBST(root, data);
        cin>>data;
    }
}

int main(){
    Node* root = NULL;
    cout<<"Enter data to create BST "<<endl;
    takeInput(root);
    int target;
    cout<<"ENter the target: \n";cin>>target;
    bool pairExists = twoSumInBST(root, target);

    if(pairExists) cout<<"Pair with sum "<<target<<" found!\n";
    else cout<<"Pair not found.\n";
        return 0;
}