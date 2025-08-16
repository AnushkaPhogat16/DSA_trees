class Solution {
public:
    const int MOD = 1e9+7;

    int countVowelPermutation(int n) {
        // dp[i][c] = number of strings of length i ending with vowel c
        vector<vector<long long>> dp(n+1, vector<long long>(5, 0));

        // Base case: length 1, each vowel counts as 1
        for(int j=0; j<5; j++) dp[1][j] = 1;

        for(int i=2; i<=n; i++) {
            dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4]) % MOD; // a <- e,i,u
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;              // e <- a,i
            dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % MOD;              // i <- e,o
            dp[i][3] = dp[i-1][2] % MOD;                             // o <- i
            dp[i][4] = (dp[i-1][2] + dp[i-1][3]) % MOD;              // u <- i,o
        }

        long long ans = 0;
        for(int j=0; j<5; j++) ans = (ans + dp[n][j]) % MOD;
        return ans;
    }
};
