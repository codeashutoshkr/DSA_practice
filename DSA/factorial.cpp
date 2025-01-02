/*You are asked to calculate factorials of some small positive integers.
Input- An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines,
 each containing a single integer n, 1 <= n <= 100
Output- For each integer n given at input, display a line with the value of n!
Note: For larger numbers, their factorial can overflows any available numeric data type in C. */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void multiply(vector<int>& number, int x) {
    int carry = 0;
    for (int i = 0; i < number.size(); ++i) {
        int product = number[i] * x + carry;
        number[i] = product % 10; // Store the last digit of product
        carry = product / 10;     // Carry over the remaining digits
    }
    while (carry) {
        number.push_back(carry % 10);
        carry /= 10;
    }
}

void calculate_factorial(int n) {
    vector<int> result(1, 1); // Initialize with 1

    for (int i = 2; i <= n; ++i) {
        multiply(result, i);
    }

    // Print the result in reverse order
    for (auto it = result.rbegin(); it != result.rend(); ++it) {
        cout << *it;
    }
    cout << endl;
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
        calculate_factorial(n);
    }
    return 0;
}

