class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // base case:- last row = grid values
        for(int j = 0; j < n; j++){
            dp[n-1][j] = grid[n-1][j];
        }

        // fill upwards from 2nd last row
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(k!=j){
                        dp[i][j] = min(dp[i][j], grid[i][j] + dp[i+1][k]);
                    }
                }
            }
        }

        int ans = INT_MAX;
        for(int j = 0; j < n; j++){
            ans = min(ans, dp[0][j]);
        }

        return ans;


    }
};