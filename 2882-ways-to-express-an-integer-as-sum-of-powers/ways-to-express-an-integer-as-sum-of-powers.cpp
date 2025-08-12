class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> powers;
    int t[305][305];

    int solve(int idx, int remaining) {
        if (remaining == 0) return 1;
        if (idx >= powers.size() || remaining < 0) return 0;
        if (t[idx][remaining] != -1) return t[idx][remaining];

        long long take = 0, skip = 0;
        if (powers[idx] <= remaining)
            take = solve(idx + 1, remaining - powers[idx]);
        skip = solve(idx + 1, remaining);

        return t[idx][remaining] = (take + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        for (int i = 1; pow(i, x) <= n; i++) {
            powers.push_back((int)pow(i, x));
        }
        memset(t, -1, sizeof(t));
        return solve(0, n);
    }
};
