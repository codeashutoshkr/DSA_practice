/*
The Knight's tour problem🐴

You are given an integer n, there is a n × n chessboard with a Knight starting at the top-left corner (0, 0).
 Your task is to determine a valid Knight's Tour, where the Knight visits every square exactly once, 
 following the standard movement rules of a chess Knight (two steps in one direction and one step perpendicular), 
 for example if a Knight is placed at cell (2, 2), in one move it can move to any of the following cells: 
 (4, 3), (4, 1), (0, 3), (0, 1), (3, 4), (3, 0), (1, 4) and (1, 0).

🟢 You have to return the order in which each cell is visited. If a solution exists,
return the sequence of numbers (starting from 0) representing the order of visited squares. 
If no solution is possible, return an empty list.

Note: You can return any valid ordering, if it is correct the driver code will print true else it will print false.

👉Example:
Input: n = 5
Output: true
Explanation: A possible Knight's Tour in a 5x5 chessboard is given below where Each number represents 
the step at which the Knight visits that cell, starting from (0, 0) as step 0.

[[0, 11, 2, 17, 20],
 [3, 16, 19, 12, 7],
 [10, 1, 6, 21, 18],
 [15, 4, 23, 8, 13], 
 [24, 9, 14, 5, 22]]

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Solution:

Logic Breakdown & Solvability Rules-
🚀 N = 1 (Trivial Case):
The grid consists of a single square (0, 0). The knight starts and finishes at step 0.Return [[0]]. 
🚀 N = 2, 3, 4$ (Impossible): It is mathematically proven that no valid Knight's Tour exists
for board sizes 2X2, 3X3, or 4X4. Return {} (empty list). 
🚀 N >= 5 (Always Possible): 
A valid tour always exists starting from (0, 0).

✨ Why Naive Backtracking Fails vs. Warnsdorff's RuleNaive Backtracking: 
👽Trying the 8 knight moves in a fixed order produces a search tree of up to O(8^{N^2}) states. 
On 5X5 or 6X6 grids, naive backtracking frequently hits dead ends deep in the recursion tree, 
leading to Time Limit Exceeded (TLE).
💡Warnsdorff's Heuristic: 
From the current cell, 
always move to an unvisited neighbor that has the fewest unvisited onward moves (minimum degree). 
By prioritizing constrained cells early, the algorithm avoids getting trapped in dead ends 
and finds a valid tour in almost linear time.

✅Step-by-Step Algorithm ~

1️⃣ Initialize an N X N matrix board filled with -1 (unvisited).
2️⃣ Start at (0, 0) with step = 0.
3️⃣ At cell (r, c):
4️⃣ Mark board[r][c] = step.
🔥 Base Case: If step == N * N - 1, all cells are visited; return true.
🔥 Find all valid unvisited knight moves from (r, c).
🔥 Compute the number of unvisited onward neighbors for each candidate move.
🔥 Sort candidate moves in ascending order of their onward degree.Recurse on each move in sorted order. 
🔥 If a path succeeds, return true.If all moves fail, backtrack by resetting board[r][c] = -1 and return false.
*/


#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // 8 possible moves for a Chess Knight
    const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    // Check if (r, c) is inside the grid and unvisited
    bool isValid(int r, int c, int n, const vector<vector<int>>& board) {
        return (r >= 0 && r < n && c >= 0 && c < n && board[r][c] == -1);
    }

    // Warnsdorff's Heuristic: Count unvisited neighbors from (r, c)
    int getDegree(int r, int c, int n, const vector<vector<int>>& board) {
        int count = 0;
        for (int i = 0; i < 8; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (isValid(nr, nc, n, board)) {
                count++;
            }
        }
        return count;
    }

    bool solve(int r, int c, int step, int n, vector<vector<int>>& board) {
        board[r][c] = step;

        // Base Case: Visited all N * N squares
        if (step == n * n - 1) {
            return true;
        }

        // Collect all valid next moves with their degree
        vector<pair<int, pair<int, int>>> nextMoves;
        for (int i = 0; i < 8; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (isValid(nr, nc, n, board)) {
                int degree = getDegree(nr, nc, n, board);
                nextMoves.push_back({degree, {nr, nc}});
            }
        }

        // Sort moves by degree in ascending order (Warnsdorff's Rule)
        sort(nextMoves.begin(), nextMoves.end());

        // Explore neighbors with the fewest onward choices first
        for (const auto& move : nextMoves) {
            int nr = move.second.first;
            int nc = move.second.second;

            if (solve(nr, nc, step + 1, n, board)) {
                return true;
            }
        }

        // Backtrack
        board[r][c] = -1;
        return false;
    }

public:
    vector<vector<int>> knightTour(int n) {
        // Edge Cases: No valid tour exists for 2x2, 3x3, 4x4 grids
        if (n >= 2 && n <= 4) {
            return {};
        }

        vector<vector<int>> board(n, vector<int>(n, -1));

        if (solve(0, 0, 0, n, board)) {
            return board;
        }

        return {};
    }
};

