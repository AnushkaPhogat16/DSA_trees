class Solution {
public:
    int t[201][201];  // memoization table

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        memset(t, -1, sizeof(t));

        return solve(grid, m - 1, n - 1);
    }

    int solve(vector<vector<int>>& grid, int row, int col) {
        // base case: start cell
        if (row == 0 && col == 0) return grid[0][0];

        // out-of-bounds check
        if (row < 0 || col < 0) return INT_MAX;

        // memoized result
        if (t[row][col] != -1) return t[row][col];

        int fromTop = solve(grid, row - 1, col);
        int fromLeft = solve(grid, row, col - 1);

        // store and return minimum path sum to (row, col)
        return t[row][col] = grid[row][col] + min(fromTop, fromLeft);
    }
};
