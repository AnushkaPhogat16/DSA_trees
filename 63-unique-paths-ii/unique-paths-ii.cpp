class Solution {
public:
    int t[101][101];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        if(obstacleGrid[rows - 1][cols - 1] == 1) return 0;

        memset(t, -1, sizeof(t));

        return solve(rows - 1, cols - 1, obstacleGrid);
    }

    int solve(int ind1, int ind2, vector<vector<int>>& obstacleGrid){
        if(t[ind1][ind2] != -1) return t[ind1][ind2];

        if(ind1 == 0 && ind2 == 0) return 1;
        if(ind1 < 0 || ind2 < 0) return 0;

        int up = 0;
        if(ind1 > 0 && obstacleGrid[ind1 - 1][ind2] != 1 ){
            up = solve(ind1 - 1, ind2, obstacleGrid);
        }

        int left = 0;
        if(ind2 > 0 && obstacleGrid[ind1][ind2 - 1] != 1 ){
            left = solve(ind1, ind2- 1, obstacleGrid);
        }

        return t[ind1][ind2] = up + left;
    }
};