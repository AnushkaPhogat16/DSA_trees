class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[rows - 1][cols - 1] == 1)
            return 0;

        vector<int> prev(cols, 0);

        for (int i = 0; i < rows; i++) {
            vector<int> curr(cols, 0);
            for (int j = 0; j < cols; j++) {
                if(i == 0 && j == 0) curr[j] = 1;
                else{
                    int up = 0, left = 0;
                    if(i > 0 && obstacleGrid[i-1][j] != 1){
                        up = prev[j];
                    }

                    if(j > 0 && obstacleGrid[i][j-1] != 1){
                        left = curr[j-1];
                    }

                    curr[j] = (obstacleGrid[i][j] == 1) ? 0 : (up + left);
                }
                
            }

            prev = curr;
        }

        return prev[cols - 1];
    }
};
