class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int sum = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = matrix[i][j];
                    sum += dp[i][j];
                }
            }
        }

        

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] == 0) dp[i][j] = 0;
                else{
                    dp[i][j] = 1+ min (dp[i-1][j], 
                    min(dp[i-1][j-1] , dp[i][j-1]));

                    sum += dp[i][j];
                }
            }
        }

        return sum;

        


    }
};