class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;

        // Count net difference (basket1 - basket2)
        for (int val : basket1) freq[val]++;
        for (int val : basket2) freq[val]--;

        vector<int> excess;
        int global_min = INT_MAX;

        for (auto& [val, count] : freq) {
            if (count % 2 != 0) return -1;  // Impossible to pair
            int times = abs(count) / 2;
            for (int i = 0; i < times; ++i) excess.push_back(val);
            global_min = min(global_min, val);
        }

        // Only need to process half, as each swap resolves two items
        sort(excess.begin(), excess.end());
        int n = excess.size() / 2;
        long long cost = 0;
        for (int i = 0; i < n; ++i) {
            cost += min((long long)excess[i], 2LL * global_min);
        }

        return cost;
    }
};
