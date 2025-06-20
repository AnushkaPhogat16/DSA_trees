class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        int i = 0;
        vector<int> currSubset = {};

        helper(nums,currSubset, ans, n, i);

        return ans;
    }

    void helper(vector<int>& nums, vector<int> currSubset, vector<vector<int>>& ans, int n, int index){
        
        if(index == n){
            ans.push_back(currSubset);
            return;
        }

        // at each index we can either take or not
        currSubset.push_back(nums[index]);
        helper(nums, currSubset, ans, n, index + 1);

        currSubset.pop_back();
        helper(nums, currSubset, ans, n, index + 1);

    }
};