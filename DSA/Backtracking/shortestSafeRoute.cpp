/*
Given a 2D matrix mat[][] of size n × m, where each cell is either 0 (landmine) or 1 (safe), 
find the minimum number of steps required to travel from any cell in the leftmost column to any cell in the rightmost column.

You can move only in four directions: up, down, left, and right.
A cell is unsafe if it contains a landmine or is directly adjacent (up, down, left, or right) to a landmine, and such cells must be avoided.
Return -1 if no safe path exists.

Examples:
Input: mat[][] = [[1, 0, 1, 1, 1], 
                  [1, 1, 1, 1, 1], 
                  [1, 1, 1, 1, 1], 
                  [1, 1, 1, 0, 1], 
                  [1, 1, 1, 1, 0]]
https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/710037/Web/Other/blobid0_1789323379.png
*/

#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int findShortestPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Step 1: Pre-compute all unsafe cells
        vector<vector<bool>> unsafe(n, vector<bool>(m, false));

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (mat[r][c] == 0) {
                    unsafe[r][c] = true;
                    // Mark 4-directional adjacent neighbors as unsafe
                    for (int i = 0; i < 4; i++) {
                        int nr = r + dr[i];
                        int nc = c + dc[i];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                            unsafe[nr][nc] = true;
                        }
                    }
                }
            }
        }

        // Step 2: Multi-Source BFS Queue (stores {row, col})
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Push all safe starting cells in column 0
        for (int r = 0; r < n; r++) {
            if (!unsafe[r][0]) {
                q.push({r, 0});
                visited[r][0] = true;
            }
        }

        // Path length starts at 1 (counting the starting cell in column 0)
        int dist = 1;

        // Step 3: Level-Order BFS Traversal
        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto curr = q.front();
                q.pop();

                int r = curr.first;
                int c = curr.second;

                // Destination reached: Any cell in the rightmost column
                if (c == m - 1) {
                    return dist;
                }

                // Explore 4 directions
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && 
                        !unsafe[nr][nc] && !visited[nr][nc]) {
                        
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            // Increment path length after expanding the current level
            dist++;
        }

        return -1;
    }