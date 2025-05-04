class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> mapp;
        int ans = 0;

        for (const auto& d : dominoes) {
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            int key = a * 10 + b;

            ans += mapp[key];  // count how many times we've seen this pair before
            mapp[key]++;
        }

        return ans;
    }
};
