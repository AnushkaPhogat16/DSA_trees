class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base cases
        for (int i = 0; i <= n; i++) dp[i][0] = i; // converting word1[0..i-1] to empty = i deletions
        for (int j = 0; j <= m; j++) dp[0][j] = j; // converting empty to word2[0..j-1] = j insertions

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // no operation needed
                } else {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],     // delete
                        dp[i][j - 1],     // insert
                        dp[i - 1][j - 1]  // replace
                    });
                }
            }
        }

        return dp[n][m];
    }
};
