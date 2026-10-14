/*
Given a string s, which may contain duplicate characters, generate all possible unique permutations of the string.
Note: You may return the permutations in any order.

Examples:

Input: s = "ABC"
Output: ["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]
Explanation: Given string ABC has 6 unique permutations.
*/

#include<bits/stdc++.h>

using namespace std;

void backtrack(string& s, string& currentPath, vector<string>& result, vector<bool>& visited){
        
    //base case: Constructed a permutation of full length
        if(currentPath.length() == s.length()){
            result.push_back(currentPath);
            return;
        }
        
        for(int i=0; i<s.length(); i++){
        // If already used in current recursive path, skip
          if(visited[i]){
              continue;
          }
    // Duplicate Pruning Rule:
    //If the current char == previous char AND previous char was not visited at this level
    // skip to avoid generating duplicate permutations
    
    if(i>0 && s[i] == s[i-1] && !visited[i-1]){
        continue;
    }
    
    //1. Choose
    visited[i] = true;
    currentPath.push_back(s[i]);
    
    //2. Recurse
    backtrack(s, currentPath, result, visited);
    
    //3. Un-Choose
    visited[i] = false;
    currentPath.pop_back();
  }
}
  
    vector<string> findPermutation(string &s) {
        // Code here
        vector<string> result;
        string currentPath = "";
        vector<bool> visited(s.length(), false);
        sort(s.begin(), s.end());
        
        backtrack(s, currentPath, result, visited);
        
        return result;
    }

int main(){
    string s = "ABC";
    vector<string> ans = findPermutation(s);
    cout<<"[";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<", ";
    }
    cout<<"]"<<endl;
}