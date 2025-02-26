/*Chef likes problems which using some math. Now he asks you to solve next one. You have 4 integers, 
Chef wondering is there non-empty subset which has sum equals 0.

Input: The first line of input contains T - number of test cases.
Each of the next T lines containing four pairwise distinct integer numbers - a, b, c, d.

Output: For each test case output "Yes", if possible to get 0 by choosing non-empty subset of {a, b, c, d} with sum equal 0,
 or "No" in another case.*/

 #include <iostream>
using namespace std;

void solve() {
   long long  int arr[4];
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }

   
    for (long long int i = 1; i < 16; i++) { // Start from 1 to ensure the subset is non-empty
        long long int sum = 0;
        for (long long int j = 0; j < 4; j++) {
            if (i & (1 << j)) { 
                sum += arr[j];
            }
        }
        if (sum == 0 && i != 0) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
   long long  int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
/* Explanation:
1> Loop through all subsets using bit masking (1 << 4 = 16 subsets).
2> Calculate the sum of elements in the subset.
3> If the sum is 0, print "YES" and return immediately.
4> If no subset gives 0, print "NO"
*/