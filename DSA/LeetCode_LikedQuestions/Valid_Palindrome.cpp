//                 - - - VALID  PALINDROME - - -  
/*
 A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
 it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.
Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
(Asked by Google, Meta)
*/
#include<iostream>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool isPalindrome(std::string s) {
       
        std::string cleaned_s = "";
        for (char c : s) {
            if (std::isalnum(c)) {
                cleaned_s += std::tolower(c);
            }
        }

        int left = 0;
        int right = cleaned_s.length() - 1;

        while (left < right) {
            // If characters at current pointers do not match, it's not a palindrome
            if (cleaned_s[left] != cleaned_s[right]) {
                return false;
            }
            // Move pointers inward
            left++;
            right--;
        }


        return true;
    }
};

int main(){
    string s;
    cin>>s;
    Solution sol;
    cout<<boolalpha;
    
    cout<<"Is this string a valid palindrome ? "<<sol.isPalindrome(s);
}

/*
 "cout<<boolalpha" manipulator changes this default behavior. When you insert std::boolalpha into std::cout,
  it tells the stream: "From now on, when you encounter a bool value, print the words true or false instead of 1 or 0."
   If you want to revert to the default 1/0 output for booleans, you'd use "std::noboolalpha"
*/