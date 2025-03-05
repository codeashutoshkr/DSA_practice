/*Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.
>> There are two ways to solve this problem- one is by using *(unordered map) and another one is by using *(XOR operation).
>>Key Idea:
We use the XOR ( ^ ) operator, which has two important properties:
~ x ^ x = 0 (Any number XORed with itself is 0)
~ x ^ 0 = x (Any number XORed with 0 remains unchanged)
XOR is commutative and associative, meaning order doesn’t matter.
🔹 Why does this work?
Since every number appears twice except for one, XORing all elements will cancel out the duplicate numbers (x ^ x = 0),
 leaving only the unique number.
*/
#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;  // XOR all elements
    }
    return result;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Single Number: " << singleNumber(nums) << endl; // Output: 4
    return 0;
}

