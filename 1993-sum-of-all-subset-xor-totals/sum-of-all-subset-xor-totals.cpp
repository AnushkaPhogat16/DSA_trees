class Solution {
public:

    void solve(vector<int>& nums, int i, vector<int>& currSubset, vector<vector<int>>& subsets){
        if(i == nums.size()){
            subsets.push_back(currSubset);
            return;
        }
        currSubset.push_back(nums[i]);
        solve(nums, i + 1, currSubset, subsets);
        currSubset.pop_back();
        solve(nums, i + 1, currSubset, subsets);

        return;
    }


    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> currSubset;

        solve(nums, 0, currSubset, subsets);

        int result = 0;
        for(auto subset : subsets){
            int xorn = 0;
            for(int &num : subset){
                xorn ^= num;
            }

            result+= xorn;
        }

        return result;

    }
};