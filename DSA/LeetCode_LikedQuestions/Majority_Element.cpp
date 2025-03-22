/*Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.
Example 1:
Input: nums = [3,2,3]
Output: 3
Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2 
There are two ways to solve this problem
1.) Used an unordered map to find maximum frequeny of the elements of the array. Time and space complexity = O(N).
2.) The Boyer-Moore Voting Algorithm is an efficient method to find the majority element in an array in O(N) time and O(1) space.
*/
#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>  // using unordered map (Hash Map)
/*class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int n = nums.size();
            int maxx = 0, majorEle = 0;
            unordered_map<int, int>freqMap;
            for(int i=0; i<n; i++){
                freqMap[nums[i]]++;
            if(freqMap[nums[i]] >= maxx){
                maxx = freqMap[nums[i]];
                majorEle = nums[i];
            }
            }
            return majorEle;
        }
    };*/
    // The Boyer-Moore Voting Algorithm::
    class Solution {
        public:
            int majorityElement(vector<int>& nums) {
                int frq = 0, ans = 0;  // frq = frequency count, ans = candidate for majority
                
                for (int i = 0; i < nums.size(); i++) {
                    if (frq == 0) {    // If frequency becomes 0, pick a new candidate
                        ans = nums[i];
                    }
        
                    if (ans == nums[i]) { // If current element matches candidate, increase frequency
                        frq++;
                    } else {              // Otherwise, decrease frequency
                        frq--;
                    }
                }  
        
                return ans;  // Return the majority element
            }  
        }; 

        int main(){
            int n; cout<<"The size of the array: "; cin>>n;
            vector<int> nums(n);
            for(int i=0; i<n; i++){
                cin>>nums[i];
            }
            Solution result;
            int ans = result.majorityElement(nums);
            cout<<"Majority Element: "<<ans<<endl;
        }