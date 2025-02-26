/*You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?*/

#include <iostream>
using namespace std;

        int climbStairs(int n) {
            if(n <= 3){
                return n;
            }
            int prev1 = 3;
            int prev2 = 2;
            int curr = 0, i = 3;
            while(i < n){
                curr = prev2 + prev1 ;
                prev2 = prev1;
                prev1 = curr;
                i++;
            }
            return curr;
        
    };

    int main(){
        int n;
        cout<<"The number of stairs n: "; cin>>n;
        cout<<climbStairs(n)<<endl;
    }