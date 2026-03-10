#include <iostream>
#include <algorithm> 
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  
    TreeNode* invertTree(TreeNode* root) {
        // Base case: If the current node is NULL
        if (root == nullptr) {
            return root;
        }

        invertTree(root->left);
        invertTree(root->right);

        // 2. Perform the inversion/swap operation at the current node.
        swap(root->left, root->right);
        
        return root;
    }
};

// --- Helper Functions for Testing ---

// Function to print the tree's values level by level (Breadth-First Search)
void printTreeBFS(TreeNode* root) {
    if (root == nullptr) {
        std::cout << "Tree is empty." << std::endl;
        return;
    }
    
    std::queue<TreeNode*> q;
    q.push(root);
    
    std::cout << "Tree (BFS Traversal):" << std::endl;
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        
        if (current != nullptr) {
            std::cout << current->val << " ";
            q.push(current->left);
            q.push(current->right);
        } else {
            // Placeholder for null children to show structure clearly
            std::cout << "null "; 
        }
    }
    std::cout << std::endl;
}

// Function to clean up allocated memory
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// --- Main function to demonstrate the solution ---
int main() {
    // 1. Build a sample tree:
    //      4
    //     / \
    //    2   7
    //   / \ / \
    //  1  3 6  9
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    root->right = new TreeNode(7, new TreeNode(6), new TreeNode(9));

    std::cout << "--- Original Tree ---" << std::endl;
    printTreeBFS(root); // Output: 4 2 7 1 3 6 9

    // 2. Instantiate the solution and invert the tree
    Solution sol;
    TreeNode* invertedRoot = sol.invertTree(root);

    std::cout << "\n--- Inverted Tree ---" << std::endl;
    printTreeBFS(invertedRoot); // Expected Output: 4 7 2 9 6 3 1
    
    // 3. Clean up memory
    deleteTree(invertedRoot);

    return 0;
}