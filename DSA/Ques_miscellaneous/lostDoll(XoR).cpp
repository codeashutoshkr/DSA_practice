/*Chef is fan of pairs and he likes all things that come in pairs.
 He even has a doll collection in which the dolls come in pairs.
  One day while going through his collection he found that there are odd number of dolls.
   Someone had stolen a doll!!!

Help chef find which type of doll is missing..
Input:- The first line contains an integer T, the number of test cases.
The first line of each test case contains an integer N, the number of dolls.The next N lines are the types of dolls that are left.
Output:- For each test case, display the type of doll that doesn't have a pair, in a new line.
 Link -  https://www.codechef.com/practice/course/arrays-strings-sorting/INTARR01/problems/MISSP?tab=statement 
 .
 .
 */
#include <bits/stdc++.h>
using namespace std;

    int missingDoll(int arr[] , int n){
        int lost = 0;
        for(int i = 0; i<n; i++){
            lost^=arr[i];
        }
        
        return lost;
    }

int main() {
	// your code goes here
    int t ; cin>>t;
  while(t--){
      int n; cin>>n;
      int arr[n];
      for(int i = 0; i< n; i++){
          cin>>arr[i];
      }

       int lostDoll = missingDoll(arr, n);
       cout<<lostDoll<<endl;
  }
  
}