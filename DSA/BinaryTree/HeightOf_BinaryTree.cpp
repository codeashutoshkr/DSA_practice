#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int height(struct Node* node){
    //base case
    if(node == NULL){
        return 0;
    }
    int left = height(node -> left);
    int right = height(node ->right);
    int ans = max(left, right) + 1;
    return ans;
}

int main(){
      Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Calculate and print the height of the tree.
    cout << "The height of the binary tree is: " << height(root) << endl;

    // It's good practice to free the allocated memory to prevent memory leaks.
    // For a simple example like this, it's not strictly necessary, but good to remember.
    // For more complex applications, you would need a function to properly delete the entire tree.
     delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;

}