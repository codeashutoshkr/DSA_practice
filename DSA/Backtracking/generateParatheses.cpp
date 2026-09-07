// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses. 
/*
 Example:-
 Input: n = 3
 Output: ["((()))","(()())","(())()","()(())","()()()"] 
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

void dfs(int openPara, int closePara, int n, string s, vector<string> &res){
    
    if(openPara + closePara == 2*n){
        res.push_back(s);
        return;
    }

    if(openPara < n){
        dfs(openPara+1, closePara, n, s+"(", res);
    }
    if(closePara < openPara){
        dfs(openPara, closePara+1, n, s+")", res);
    }

}

vector<string> generateParanthesis(int n){
    vector<string> res;
    dfs(0, 0, n, "", res);
    return res;
    
} 



int main(){
    int n; 
    cout<<"Enter a number 'n' "; cin>>n;
    vector<string> ans;
    ans = generateParanthesis(n);
    cout<<"[ ";
    for(int i=0; i<ans.size(); i++){
        cout<<'"';
        cout<<ans[i]<<'"';
        cout<<" ";
        
    }
    cout<<"]";
}