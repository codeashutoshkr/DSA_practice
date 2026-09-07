// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Example:-
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true

#include<iostream>
#include<vector>
#include<string>

using namespace std;


bool wordSearch(int i, int j, int index, vector<vector<char>>& board, string& word){
        
        if(index == word.length()){
            return true;
        }

        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || word[index] != board[i][j]){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';
        bool found = wordSearch(i+1, j, index+1, board, word) // down
                ||   wordSearch(i-1, j, index+1, board, word) // up
                ||   wordSearch(i, j+1, index+1, board, word) // right
                ||   wordSearch(i, j-1, index+1, board, word); // left

                board[i][j] = temp;

                return found;
    }


    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(word[0] == board[i][j] && wordSearch(i, j, 0, board, word))
                return true;
            }
        }

        return false;
    }