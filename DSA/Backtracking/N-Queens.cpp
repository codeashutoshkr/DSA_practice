/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.
You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' 
and '.' both indicate a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;


 void helper(int colIdx, vector<string>& board, int n, vector<vector<string>>& ans){

        if(colIdx == n){
            ans.push_back(board);
            return;
        }
        // column-wise traversal for colIdx, trying all rowIdx
        for(int rowIdx=0; rowIdx<n; rowIdx++){

            if(check(rowIdx, colIdx, n, board)){
                
                board[rowIdx][colIdx] = 'Q';

                helper(colIdx+1, board, n, ans);
                // undo these changes
                
                board[rowIdx][colIdx] = '.';
            }
        }
    }

    bool check(int rowIdx, int colIdx, int n, vector<string>& board){

        //check row
        for(int col=0; col<colIdx; col++){
            if(board[rowIdx][col] == 'Q'){
                return false;
            }
        }

        //check diagonal 1(upward)
        int i= rowIdx, j = colIdx;
        while(i>=0 && j>= 0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i-=1, j-=1;
        }

        // check diagonal 2(downward)
        i = rowIdx, j = colIdx;
        while(i<n && j>=0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i+=1, j-=1;
        }
        return true;     
    }


    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        helper(0, board, n, ans);
        return ans;
    }

 