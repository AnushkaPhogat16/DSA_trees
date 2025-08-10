class Solution {
public:
    int N;
    double dp[101][25][25]; // k ≤ 100, n ≤ 25
    vector<pair<int, int>> directions = {
        {1,2}, {1,-2}, {-1,2}, {-1,-2},
        {2,1}, {2,-1}, {-2,1}, {-2,-1}
    };

    double knightProbability(int n, int k, int row, int col) {
        N = n;
        // Initialize all dp values to -1 (meaning "not computed yet")
        for (int step = 0; step <= k; step++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dp[step][i][j] = -1.0;
                }
            }
        }
        return solve(row, col, k);
    }

    double solve(int r, int c, int k) {
        // Off-board → probability 0
        if (r < 0 || r >= N || c < 0 || c >= N) return 0.0;
        // No moves left → still on board → probability 1
        if (k == 0) return 1.0;

        // Return memoized value if computed
        if (dp[k][r][c] != -1.0) return dp[k][r][c];

        double ans = 0.0;
        for (auto &dir : directions) {
            ans += solve(r + dir.first, c + dir.second, k - 1) / 8.0;
        }

        return dp[k][r][c] = ans;
    }
};
