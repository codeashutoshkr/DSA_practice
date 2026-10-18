/*
Given an array of integers nums sorted in non-decreasing order, 
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
 
Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9
*/

#include<bits/stdc++.h>

using namespace std;

    
    int findBound(vector<int>& nums, int target, bool isFirst){
        int low = 0; 
        int high = nums.size()-1;
        int bound = -1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target){
                bound = mid; // candidate index found
                if(isFirst){
                    high = mid-1; //Keep searching for the first position of the target
                }else{
                    low = mid+1; //Keep searching for the last position of the target
                }
            }
            else if(nums[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return bound;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        //If target doesn't exist, last occurance will not exist either
        if(first == -1){
            return {-1, -1};
        }

        int last = findBound(nums, target, false);

        return {first, last};
    }
