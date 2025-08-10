class Solution {
public:
    int t[71][71][71];
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        memset(t, -1, sizeof(t));

        return solve(0, 0, 0, cols-1, grid);
    }

    int solve(int i1, int j1, int i2, int j2, vector<vector<int>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();

        if(i1 < 0 || i2 < 0 || j1 < 0 || j2 < 0|| i1 >= rows || i2 >= rows || j1 >= cols || j2 >= cols){
            return INT_MIN;
        }

        if(i1 == rows-1 && i2 == rows-1){
            return (j1 == j2) ? grid[i1][j1] : grid[i1][j1] + grid[i2][j2];
        }

        if(t[i1][j1][j2] != -1) return t[i1][j1][j2];

        int maxVal = INT_MIN;

        for(int j = -1; j <= 1; j++){
            for(int k = -1; k <= 1; k++){
                int curr = solve(i1 + 1, j1 + j, i2 + 1, j2 + k, grid);
                maxVal = max(maxVal, curr);
            }
        }

        int sum = (j1 == j2) ? grid[i1][j1] : grid[i1][j1] + grid[i2][j2];

        return t[i1][j1][j2] = maxVal + sum;
    }
};