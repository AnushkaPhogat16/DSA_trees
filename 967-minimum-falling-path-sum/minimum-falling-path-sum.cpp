class Solution {
public:
    int t[101][101];
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minSum = INT_MAX;
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, 1));

        for(int i = 0; i < cols; i++){
            dp[0][i] = matrix [0][i];                        
        }

        for(int i = 1; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int up = dp[i-1][j];
                int dl = (j > 0) ? dp[i-1][j-1] : INT_MAX;
                int dr = (j < cols - 1) ? dp[i-1][j+1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min(up, min(dl, dr));
                
            }
        }    

        for(int j = 0; j < cols; j++){
            minSum = min(minSum, dp[rows-1][j]);
        }            

        return minSum;

    }


};