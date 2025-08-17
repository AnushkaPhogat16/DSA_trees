class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) return 1.0; // trivial cases

        vector<double> dp(n + 1, 0.0); 
        dp[0] = 1.0;  // Start with score 0
        double windowSum = 1.0; // Sum of last maxPts dp values
        double result = 0.0;

        for (int i = 1; i <= n; i++) {
            dp[i] = windowSum / maxPts;  // average of last maxPts
            if (i < k) {
                windowSum += dp[i];      // still allowed to draw
            } else {
                result += dp[i];         // stopped drawing, check result
            }
            if (i - maxPts >= 0) {
                windowSum -= dp[i - maxPts]; // maintain window size
            }
        }

        return result;
    }
};
