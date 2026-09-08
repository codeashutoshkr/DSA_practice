/* Given an integer array nums of unique elements, return all possible subsets (the power set).
   The solution set must not contain duplicate subsets. Return the solution in any order.

>> Example 1:
 Input: nums = [1,2,3]
 Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

#include<iostream>
#include<vector>

using namespace std;

void createSubset(vector<int>& nums, vector<vector<int>>& ans,
    vector<int> subset, int index){

        if(index == nums.size()){
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        createSubset(nums, ans, subset, index+1);

        subset.pop_back();
        createSubset(nums, ans, subset, index+1);
    }

vector<vector<int>> subSets(vector<int>& nums){

    vector<vector<int>> ans;
    vector<int> subset;

    createSubset(nums, ans, subset, 0);
    return ans;

}

int main(){
    int n;
    cout<<"Enter the number of elements of the set: "; cin>>n;
    vector<int>set(n);
    cout<<"Enter the elements of the set: "; 
    for(int i=0; i<n; i++){
        cin>>set[i];
    }

    vector<vector<int>> ans = subSets(set);

    for(int i=0; i<ans.size(); i++){
        cout<<"[";
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j];
        }
        cout<<"]";
        
    }
}