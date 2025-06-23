class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> curr;
        solve(1, k, n, curr, result);
        return result;
    }

    void solve(int num, int k, int n, vector<int>& curr, vector<vector<int>>& result) {
        if (k == 0 && n == 0) {
            result.push_back(curr);
            return;
        }

        if (num > 9 || k < 0 || n < 0) return;

        //Take the current number
        curr.push_back(num);
        solve(num + 1, k - 1, n - num, curr, result);
        curr.pop_back();

        // Don't take the current number
        solve(num + 1, k, n, curr, result);
    }
};
