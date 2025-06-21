class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> curr;

        sort(nums.begin(), nums.end());
        solve(nums, target, curr, result, 0);
        return result;
    }

    void solve(vector<int>& nums, int target, vector<int>& curr, vector<vector<int>>& result, int index) {
        if (target < 0) return;
        if (target == 0) {
            result.push_back(curr);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1])
                continue;

            curr.push_back(nums[i]);
            solve(nums, target - nums[i], curr, result, i + 1);
            curr.pop_back();
        }
    }
};
