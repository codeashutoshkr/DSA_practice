#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

pair<int, int>diameterFast(Node* root){
    //base case
    if(root == NULL){
        pair<int,int> p = make_pair(0, 0);
        return p;
    }
      pair<int,int>left = diameterFast(root->left);
      pair<int,int>right = diameterFast(root->right);
      int op1 = left.first;
      int op2 = right.first;
      int op3 = left.second + right.second + 1;

      pair<int,int>ans;
      ans.first = max(op1, max(op2, op3));
      ans.second = max(left.second, right.second) + 1;
      return ans;
}

int diameter(Node* root){
    return diameterFast(root).first;
}

int main(){
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout<<"The diameter of given binary tree is: "<<diameter(root)<<endl;

     delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
}

/*
The diameter of a tree(sometime called the width) is the number of nodes on the longest path between two end nodes.
*/