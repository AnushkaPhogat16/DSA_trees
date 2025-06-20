class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currSubset;
        helper(nums, currSubset, ans, 0);
        return ans;
    }

private:
    void helper(vector<int>& nums, vector<int>& currSubset, vector<vector<int>>& ans, int index) {
        if (index == nums.size()) {
            ans.push_back(currSubset);
            return;
        }

        // Include current element
        currSubset.push_back(nums[index]);
        helper(nums, currSubset, ans, index + 1);

        // Exclude current element (backtrack)
        currSubset.pop_back();
        helper(nums, currSubset, ans, index + 1);
    }
};
