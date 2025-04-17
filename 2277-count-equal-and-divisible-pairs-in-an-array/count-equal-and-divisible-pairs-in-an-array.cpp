class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> numIndices;
        int ans = 0;

        // Step 1: Collect indices for each number
        for (int i = 0; i < nums.size(); i++) {
            numIndices[nums[i]].push_back(i);
        }

        // Step 2: For each number, check pairs of indices
        for (auto& [num, indices] : numIndices) {
            int sz = indices.size();
            for (int i = 0; i < sz; i++) {
                for (int j = i + 1; j < sz; j++) {
                    if ((indices[i] * indices[j]) % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
