/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

#include<iostream>
#include<vector>
#include <unordered_map>


using namespace std;

vector<string> letterCombination(string digits){

    vector<string> ans;

    unordered_map<char, string> telephoneComb = {
         {'2', "abc"},
         {'3', "def"},
         {'4', "ghi"},
         {'5', "jkl"},
         {'6', "mno"},
         {'7', "pqrs"},
         {'8', "tuv"},
         {'9', "wxyz"}
         
    };
    backtrack(digits, telephoneComb, ans, "", 0);
    return ans;

}

void backtrack(const string& digits, unordered_map<char,string>& telephoneComb, vector<string>& ans, string comb, int index){

    if(index == digits.length()){
        ans.push_back(comb);
        return;
    }

    string letters = telephoneComb.at(digits[index]);
    for(auto letter : letters){
        backtrack(digits, telephoneComb, ans, comb+letter, index+1);
    }
}

