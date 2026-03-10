//  Longest Common Prefix
// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie(char ch) {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode* root, string word) {
        // Base case: word is empty
        if (word.length() == 0) {
            root->isTerminal = true;
            return; // Added return to prevent accessing word[0]
        }

        int index = word[0] - 'a';
        TrieNode* child;

        // If present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } 
        else {
            // If absent
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }
        
        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans) {
        TrieNode* temp = root; // Use a temp pointer to traverse
        
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            
            // If the current node has only one child, it's a common prefix
            if (temp->childCount == 1) {
                ans.push_back(ch);
                int index = ch - 'a';
                temp = temp->children[index];
            } 
            else {
                break;
            }

            // If we reach the end of one of the words, we must stop
            if (temp->isTerminal) {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string>& arr, int n) {
    if (n == 0) return "";
    
    Trie *t = new Trie('\0');
    
    // 1. Insert all words into the Trie
    for (int i = 0; i < n; i++) {
        t->insertWord(arr[i]);
    }
    
    // 2. Find LCP using the first word as a reference
    string first = arr[0];
    string ans = "";
    t->lcp(first, ans);
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    vector<string> arr(n);
    cout << "Enter the strings (lowercase):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    string result = longestCommonPrefix(arr, n);

    if (result.empty()) {
        cout << "There is no common prefix." << endl;
    } else {
        cout << "The Longest Common Prefix is: " << result << endl;
    }

    return 0;
}