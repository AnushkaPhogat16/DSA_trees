class Solution {
public:
    int n, m;
    int minDistance(string w1, string w2) {
        n = w1.size();
        m = w2.size();

        int lcsLen = lcs(w1, w2);

        return m + n - 2*lcsLen;
    }

    int lcs(string w1, string w2){
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(w1[i-1] == w2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};