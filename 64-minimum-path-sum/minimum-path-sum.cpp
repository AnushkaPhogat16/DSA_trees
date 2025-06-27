class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int> prev(n, 0);

        // dp[0][0] = grid[0][0];

        // for(int i = 1; i < m; i++){
        //     dp[i][0] = dp[i-1][0] + grid[i][0];
        // }
        // for(int j = 1; j < n; j++){
        //     dp[0][j] = dp[0][j-1] + grid[0][j];
        // }

        for(int i = 0; i < m; i++){
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    curr[j] = grid[0][0];
                }else{
                    int up = INT_MAX, left = INT_MAX;
                    if(i > 0) up = prev[j];
                    if(j > 0) left = curr[j-1];

                    curr[j] = grid[i][j] + min(up, left);
                }  
            }
            prev = curr;
        }

        return prev[n-1];
    }
};
