/*
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 
if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

#include<iostream>
#include<vector>

using namespace std;

 int findPivot(vector<int>&nums){
    //Step1: find the index of the minimum element(Pivot) in O(logN)
        int low=0, high = nums.size()-1;
        while(low < high){
            int mid = low + (high-low)/2;
            if(nums[mid] > nums[high]){
                low = mid+1; // Pivot is in the right half
            }else{
                high = mid; // pivot is at the mid or in the left half
            }
        }
        return low; // "low" points to the minimum element
    }

    //Step3: Standard binary search on a sorted range [low, high]
    int binarySearch(const vector<int>& nums, int low, int high, int target){
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) low = mid+1;
            else high = mid-1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums);

    // Step2: Decide which sorted half contains the target
        if(target >= nums[pivot] && target <= nums[n-1]){
            return binarySearch(nums, pivot, n-1, target);
        }

        return binarySearch(nums, 0, pivot-1, target);
    }