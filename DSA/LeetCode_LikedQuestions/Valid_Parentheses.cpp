/* 
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
1> Open brackets must be closed by the same type of brackets.
2> Open brackets must be closed in the correct order.
3> Every close bracket has a corresponding open bracket of the same type.
Example 1:
Input: s = "()"
Output: true
*/
#include <iostream>
#include <stack>
using namespace std;

        bool isValid(string s) {
            stack<char> s1; // stack because it is based on LIFO, this will help to check the recent closing bracket
            for(int i=0; i<s.size(); i++){
                if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                    s1.push(s[i]);
                }
        // if s1 is empty
                else{
                    if(s1.empty()){
                        return false;
                    }
                    else{
                        char ch = s1.top();
                        s1.pop();
                        if((s[i] == '}' && ch == '{') || (s[i] == ']' && ch == '[') || (s[i] == ')' && ch == '(') ){
                            continue;
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
            return s1.empty();// if s1 is not empty it means there can be a open bracket then it return false else return true
        }
    

    int main(){
        string s;
        cin>>s;
        cout<<isValid(s);
    }
