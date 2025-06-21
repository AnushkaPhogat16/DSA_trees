class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // sort for duplicate handling
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0, target, candidates, curr, ans);
        return ans;
    }

    void helper(int index, int target, vector<int>& candidates, vector<int>& curr, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);
            helper(i + 1, target - candidates[i], candidates, curr, ans);  // i + 1 because each number used once
            curr.pop_back();
        }
    }
};
