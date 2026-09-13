/*Given a string s, partition s such that every substring of the partition is a palindrome. 
Return all possible palindrome partitioning of s.

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

    bool isPalindrome(const string& s, int low, int high){
        while(low < high){
            if(s[low] != s[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }

    void backtrack(vector<vector<string>>& ans, vector<string>&palin, const string& s, int start){

        if(start == s.length()){
            ans.push_back(palin);
            return;
        }

        for(int end=start; end<s.length(); end++){
            if(isPalindrome(s, start, end)){
                palin.push_back(s.substr(start, end-start+1));
                backtrack(ans, palin, s, end+1);
                palin.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> palin;
        backtrack(ans, palin, s, 0);
        
        return ans;
    }