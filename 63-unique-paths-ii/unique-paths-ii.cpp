class Solution {
public:
    int t[101][101];
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rs = grid.size();
        int rc = grid[0].size();

        if(grid[rs-1][rc-1] == 1) return 0; // destination blocked
        memset(t, -1, sizeof(t));

        return solve(0, 0, grid);
    }

    int solve(int i, int j, vector<vector<int>>& grid){
        if(i == grid.size()-1 && j == grid[0].size()-1) return 1;
        if(i >= grid.size() || j >= grid[0].size()) return 0;
        if(grid[i][j] == 1) return 0; // current cell blocked

        if(t[i][j] != -1) return t[i][j];

        int down = 0, right = 0;

        if(i + 1 < grid.size() && grid[i+1][j] != 1) 
            down = solve(i+1, j, grid);

        if(j + 1 < grid[0].size() && grid[i][j+1] != 1) 
            right = solve(i, j+1, grid);

        return t[i][j] = down + right;
    }
};
