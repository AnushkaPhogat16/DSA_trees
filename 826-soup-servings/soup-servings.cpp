class Solution {
public:
    vector<pair<int, int>> serve = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    unordered_map<int, unordered_map<int, double>> memo;

    double soupServings(int n) {
        if (n > 5000) return 1.0; // optimization
        return solve(n, n);
    }

    double solve(int A, int B) {
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0) return 1.0;
        if (B <= 0) return 0.0;

        if (memo[A][B] != 0) return memo[A][B];

        double prob = 0.0;
        for (auto &p : serve) {
            prob += 0.25 * solve(A - p.first, B - p.second);
        }

        return memo[A][B] = prob;
    }
};
