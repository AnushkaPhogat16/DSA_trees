class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> powers;
    vector<vector<int>> memo;

    int solve(int idx, int remaining) {
        if (remaining == 0) return 1;  // found one way
        if (idx >= powers.size() || remaining < 0) return 0;
        if (memo[idx][remaining] != -1) return memo[idx][remaining];

        long long take = 0, skip = 0;
        if (powers[idx] <= remaining)
            take = solve(idx + 1, remaining - powers[idx]);
        skip = solve(idx + 1, remaining);

        return memo[idx][remaining] = (take + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        // Precompute powers
        for (int i = 1; pow(i, x) <= n; i++) {
            powers.push_back((int)pow(i, x));
        }
        memo.assign(powers.size(), vector<int>(n + 1, -1));
        return solve(0, n);
    }
};
