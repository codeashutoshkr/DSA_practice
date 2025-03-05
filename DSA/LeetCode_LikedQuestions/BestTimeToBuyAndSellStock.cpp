/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/
#include<iostream>
using namespace std;
#include<vector>
#include <climits>

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int minn = INT_MAX, maxProfit = 0;
            
            for (int i = 0; i < prices.size(); i++) {
                minn = min(minn, prices[i]);  // Update minimum price
                maxProfit = max(maxProfit, prices[i] - minn);  // Update max profit
            }
            
            return maxProfit;
        }
    };
    int main(){
        int n; cout<<"Enter the size of array: ";
        cin>>n;
        vector<int>prices(n);
        cout<<"Enter the prices of stocks: ";
        for(int i=0; i<n; i++){
            cin>>prices[i];
        }
        Solution sol;
        int profit = sol.maxProfit(prices);
        cout<<"Maximum Profit: "<<profit<<endl;
        return 0;
    }