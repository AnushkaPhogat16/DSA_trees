class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        long long twoColor = 6;  // 2-color patterns (e.g., RGB, RBG)
        long long threeColor = 6; // 3-color patterns (e.g., RGR, GRB)

        for (int i = 1; i < n; i++) {
            long long newTwoColor = (2 * twoColor + 2 * threeColor) % MOD;
            long long newThreeColor = (2 * twoColor + 3 * threeColor) % MOD;

            twoColor = newTwoColor;
            threeColor = newThreeColor;
        }

        return (twoColor + threeColor) % MOD;
    }
};
