class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int start, int k) {
        int n = fruits.size();
        // extract positions and build prefix‐sum of fruit counts
        vector<int> pos(n), pSum(n);
        for (int i = 0; i < n; i++) {
            pos[i]  = fruits[i][0];
            pSum[i] = fruits[i][1] + (i > 0 ? pSum[i-1] : 0);
        }

        int maxF = 0;
        // try every “turning distance” d until rem = k−2d becomes negative
        for (int d = 0; d <= k/2; d++) {
            int rem = k - 2*d;
            // ——— Case 1: go left d steps, then right rem steps ———
            {
                int L = start - d;
                int R = start + rem;
                int l = int(lower_bound(pos.begin(), pos.end(), L) - pos.begin());
                int r = int(upper_bound(pos.begin(), pos.end(), R) - pos.begin()) - 1;
                if (l <= r) {
                    int total = pSum[r] - (l > 0 ? pSum[l-1] : 0);
                    maxF = max(maxF, total);
                }
            }
            // ——— Case 2: go right d steps, then left rem steps ———
            {
                int L = start - rem;
                int R = start + d;
                int l = int(lower_bound(pos.begin(), pos.end(), L) - pos.begin());
                int r = int(upper_bound(pos.begin(), pos.end(), R) - pos.begin()) - 1;
                if (l <= r) {
                    int total = pSum[r] - (l > 0 ? pSum[l-1] : 0);
                    maxF = max(maxF, total);
                }
            }
        }

        return maxF;
    }
};
