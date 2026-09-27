/*
Given an array arr[], determine if it can be partitioned into two subsets such that 
the sum of elements in both parts is the same.
Note: Each element must be in exactly one subset.

Examples:
Input: arr = [1, 5, 11, 5]
Output: true
Explanation: The two parts are [1, 5, 5] and [11].
*/

#include<iostream>
#include<vector>

using namespace std;

    bool equalPartition(vector<int>& arr) {
            int totalSum = 0;
            for (int num : arr) {
                totalSum += num;
            }

            // Rule 1: Odd sum can never be partitioned into two equal integer halves
            if (totalSum % 2 != 0) {
                return false;
            }

            int target = totalSum / 2;

            // dp[j] will be true if a subset sum of 'j' is achievable
            vector<bool> dp(target + 1, false);

            // Base Case: A target sum of 0 is always achievable (empty subset)
            dp[0] = true;

            // Process each number in the array
            for (int num : arr) {
                // Traverse BACKWARDS from 'target' down to 'num'
                for (int j = target; j >= num; j--) {
                    dp[j] = dp[j] || dp[j - num];
                }
            }

            return dp[target];
        }