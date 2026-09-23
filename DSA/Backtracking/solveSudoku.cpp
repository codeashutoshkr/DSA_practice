/*
Given a 9*9 matrix mat[][] representing an incomplete Sudoku puzzle. Each cell contains a digit from 0 to 9,
where 0 represents an empty cell
and non-zero digits represent fixed values.
Fill the empty cells to complete the puzzle. It is guaranteed that the puzzle has exactly one valid solution.

A valid Sudoku solution must satisfy the following conditions:

Each digit from 1 to 9 appears exactly once in every row.
Each digit from 1 to 9 appears exactly once in every column.
Each digit from 1 to 9 appears exactly once in each of the nine 3*3 subgrids.
*/

#include<iostream>
#include<vector>

using namespace std;

bool isValid(vector<vector<int>>& mat, int row, int col, int num){

    for(int i=0; i<9; i++){
        // check row
        if(mat[row][i] == num) return false;

        // check column
        if(mat[i][col] == num) return false;

        int gridRow = 3*(row/3) + i/3;
        int gridCol = 3*(col/3) + i%3;

        if(mat[gridRow][gridCol] == num) return false;
    }
    return true;
}

bool solve(vector<vector<int>>& mat){

    for(int row=0; row<9; row++){
        for(int col=0; col<9; col++){
            // find empty cell
            if(mat[row][col] == 0){
                // Try placing digit 1 through 9
                for(int num=1; num<=9; num++){
                    if(isValid(mat, row, col, num)){
                        mat[row][col] = num;
                    }
            // Recurse: If this choice leads to a solution, stop searching
               if(solve(mat)) return true;

               mat[row][col] = 0; // backtrack
                }
        // If no number 1-9 works, this path is a dead end
                return false;
            }
        // Base case: No empthy cell left in the entire board
                return true;
        }
    }
}

void solveSudoku(vector<vector<int>>& mat){
    solve(mat);
}