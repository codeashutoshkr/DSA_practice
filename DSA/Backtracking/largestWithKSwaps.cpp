/*
Given a number k and string s of digits denoting a positive integer, 
build the largest number possible by performing swap operations on the digits of s at most k times.

Examples :

Input: s = "1234567", k = 4
Output: 7654321
Explanation: Three swaps can make the input 1234567 to 7654321, swapping 1 with 7, 2 with 6 and finally 3 with 5.
*/

#include<bits/stdc++.h>

using namespace std;

void solve(int index, string& s, int k, string& maxStr) {
          // Base Case: No swaps left or reached end of string
          if (k == 0 || index >= s.length() - 1) {
              return;
          }

          int n = s.length();
          char maxChar = s[index];

          // Find the maximum digit present in s[index ... n-1]
          for (int j = index + 1; j < n; j++) {
              if (s[j] > maxChar) {
                  maxChar = s[j];
              }
          }

          // If s[index] is already the maximum digit, move to next index without using a swap
          if (maxChar != s[index]) {
              k--; // Spend 1 swap budget
          }

          // Try swapping s[index] with EVERY occurrence of maxChar to find the global optimum
          for (int j = index; j < n; j++) {
              if (s[j] == maxChar) {
                  // 1. CHOOSE
                  swap(s[index], s[j]);

                  // Update global maximum string
                  if (s > maxStr) {
                      maxStr = s;
                  }

                  // 2. RECURSE
                  solve(index + 1, s, k, maxStr);

                  // 3. UN-CHOOSE (Backtrack)
                  swap(s[index], s[j]);
              }
          }
      }
      
      
      
    string findMaximumNum(string& s, int k) {
        // code here.
        string maxStr = s;
                solve(0, s, k, maxStr);
                return maxStr;
    }

int main(){
    string s = "1234567";
    int k = 4;

    string ans = findMaximumNum(s, k);
    cout<<ans<<endl;
}