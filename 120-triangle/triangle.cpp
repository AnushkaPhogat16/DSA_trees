class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int ind = 0;
        int row = 0;
        
        vector<vector<int>> dp(rows, vector<int>(rows, 0));

        for(int i = 0; i < rows; i++){
            dp[rows - 1][i] = triangle[rows-1][i];
        }

        for (int row = rows - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[row][col] = triangle[row][col] + min(dp[row+1][col], dp[row+1][col+1]);
            }
        }

        return dp[0][0];

    }
};