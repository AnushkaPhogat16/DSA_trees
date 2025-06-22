#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& result) {
        result.push_back(temp);

        for(int j = i; j < nums.size(); ++j) {
            if(j > i && nums[j] == nums[j - 1]) continue; // Skip duplicates
            temp.push_back(nums[j]);
            solve(j + 1, nums, temp, result);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        
        sort(nums.begin(), nums.end());

        solve(0, nums, temp, result);

        return result;
    }
};
