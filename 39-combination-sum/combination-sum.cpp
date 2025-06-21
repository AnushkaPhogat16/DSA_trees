class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int index = 0;
        vector<vector<int>> ans;

        vector<int> currCombo;

        helper(nums, ans, currCombo, target, index);

        return ans;
    }

    void helper(vector<int>& nums,vector<vector<int>>& ans, vector<int>& currCombo, int target, int index){
        if(target == 0){
            ans.push_back(currCombo);
            return;
        }

        if(target < 0 || index == nums.size()){
            return;
        }

        // take and not go ahead
        target -= nums[index];
        currCombo.push_back(nums[index]);
        helper(nums, ans, currCombo, target, index);

        // dont take go ahead
        currCombo.pop_back();
        target += nums[index];
        index++;
        helper(nums, ans, currCombo, target, index);
    }
};