/*You are given a string s and an integer k. Encrypt the string using the following algorithm:
For each character c in s, replace c with the kth character after c in the string (in a cyclic manner).
Return the encrypted string.
Example 1:
Input: s = "dart", k = 3
Output: "tdar"
*/
#include<iostream>
using namespace std;
#include <string.h>

    string getEncryptedString(string s, int k) {
        int n = s.size();
        string ans = "";
        if (k <= n) {
            for(int i=k;i<n;i++){
                ans += s[i];
            }
            for(int i=0;i<k;i++){
                ans += s[i];
            }
        }
        if (k > n) {
            int st = k % n;
            for(int i=st;i<n;i++){
                ans += s[i];
            }
            for(int i=0;i<st;i++){
                ans += s[i];
            }
        }
        return ans;
    }


   int main(){
    string s;
    cin>>s;
    int k; cin>>k;
     string getEncryptString = getEncryptedString(s, k);
     cout<<getEncryptString<<endl;
     return 0;

}
