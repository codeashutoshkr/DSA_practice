/*You are asked to calculate factorials of some small positive integers.
Input- An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines,
 each containing a single integer n, 1 <= n <= 100
Output- For each integer n given at input, display a line with the value of n!
Note: For larger numbers, their factorial can overflows any available numeric data type in C++. */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> factorial(int n) {
        // code here
        
        vector<int>res;
        res.push_back(1);
        
        for(int i=2; i<=n; i++){
            
            int carry = 0;
            
            for(int j=0; j<res.size(); j++){
                int prod = res[j]*i + carry; //product
                
                res[j] = prod%10;
                carry = prod/10;
            }
        
        
        while(carry != 0){
            res.push_back(carry%10);
            carry/=10;
        }
      }  
        reverse(res.begin(), res.end());
        return res;
    }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n < 1 || n > 100) {
            cout << "n should be in the range 1 to 100" << endl;
            continue;
        }
        vector<int>ans;
        ans = factorial(n);
        cout<<"[";
        for(int i=0; i<ans.size(); i++){
            
            cout<<ans[i]<<", ";
            
        }
        cout<<"]";
    }
    return 0;
}

