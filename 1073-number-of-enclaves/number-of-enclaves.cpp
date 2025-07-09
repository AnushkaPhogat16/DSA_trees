class Solution {
public:

    void dfs(int r, int c, vector<vector<int>>& grid, vector<pair<int, int>>& dirs, int n, int m) {
        grid[r][c] = 0; // Mark the cell as visited by setting it to 0

        for (int i = 0; i < 4; i++) {
            int newx = r + dirs[i].first;
            int newy = c + dirs[i].second;

            if (newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] == 1) {
                dfs(newx, newy, grid, dirs, n, m);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int, int>> dirs {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Start DFS from the boundary (first and last row, first and last column)
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) {
                dfs(i, 0, grid, dirs, n, m);
            }
            if (grid[i][m - 1] == 1) {
                dfs(i, m - 1, grid, dirs, n, m);
            }
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) {
                dfs(0, j, grid, dirs, n, m);
            }
            if (grid[n - 1][j] == 1) {
                dfs(n - 1, j, grid, dirs, n, m);
            }
        }

        // Count the remaining 1's in the grid which are the "safe" enclaves
        int safe = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    safe++;
                }
            }
        }

        return safe;
    }
};
