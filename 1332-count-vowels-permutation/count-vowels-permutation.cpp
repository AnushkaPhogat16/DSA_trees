class Solution {
public:
    const int MOD = 1e9+7;

    int countVowelPermutation(int n) {
        const int MOD = 1e9+7;
        vector<long long> prev(5, 1), curr(5, 0);

        for(int i=2; i<=n; i++) {
            curr[0] = (prev[1] + prev[2] + prev[4]) % MOD;
            curr[1] = (prev[0] + prev[2]) % MOD;
            curr[2] = (prev[1] + prev[3]) % MOD;
            curr[3] = prev[2] % MOD;
            curr[4] = (prev[2] + prev[3]) % MOD;
            prev = curr;
        }

        long long ans = 0;
        for(int j=0; j<5; j++) ans = (ans + prev[j]) % MOD;
        return ans;
    }

};
