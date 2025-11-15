#include<iostream>
#include<vector>
using namespace std;

int largestSubarr(vector<int> &arr, int k){
     int n = arr.size();
     int maxSize = 0, sum = 0;
     int left = 0;
     for(int right = 0; right<n; ++right){
        sum += arr[right];

         while(sum > k){
            sum -= arr[left];
            left++;
        }
        
        if(sum == k){
            int currSize = right-left + 1;
            sum -= arr[left];
            left++;
            if(currSize >= maxSize){
                maxSize = currSize;
            }
        }
        
     }
     return maxSize;
}


int main(){
    int n, k;
    cout<<"Enter the value of sum: "; cin>>k;
    cout<<"Ente the size of the array: "; cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = largestSubarr(arr, k);
    cout<<ans<<endl;
}