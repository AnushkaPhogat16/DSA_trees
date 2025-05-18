#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int colorTheGrid(int m, int n) {
        static const int MOD = 1e9+7;
        // 1) Enumerate all valid column‐patterns in base‐3 of height m
        vector<int> valid;
        int maxMask = pow(3, m);
        valid.reserve(maxMask);
        for (int mask = 0; mask < maxMask; ++mask) {
            int tmp = mask, last = -1;
            bool ok = true;
            for (int i = 0; i < m; ++i) {
                int c = tmp % 3;
                tmp /= 3;
                if (c == last) { ok = false; break; }
                last = c;
            }
            if (ok) valid.push_back(mask);
        }
        
        int S = valid.size();
        // 2) Build compatibility lists
        vector<vector<int>> compat(S);
        for (int i = 0; i < S; ++i) {
            for (int j = 0; j < S; ++j) {
                int a = valid[i], b = valid[j];
                bool ok = true;
                for (int k = 0; k < m; ++k) {
                    if ((a % 3) == (b % 3)) { ok = false; break; }
                    a /= 3; b /= 3;
                }
                if (ok) compat[i].push_back(j);
            }
        }
        
        // 3) DP over columns with rolling arrays
        vector<int> dp(S, 1), nextDP(S);
        for (int col = 1; col < n; ++col) {
            fill(nextDP.begin(), nextDP.end(), 0);
            for (int i = 0; i < S; ++i) if (dp[i]) {
                long long ways = dp[i];
                for (int j : compat[i]) {
                    nextDP[j] = (nextDP[j] + ways) % MOD;
                }
            }
            dp.swap(nextDP);
        }
        
        // 4) Sum up the ways for the last column
        long long ans = 0;
        for (int x : dp) ans = (ans + x) % MOD;
        return ans;
    }
};
