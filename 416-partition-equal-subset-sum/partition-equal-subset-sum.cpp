class Solution {
public:
    int t[201][10001];
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;
        int target = total / 2;

        int n = nums.size();

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        //base case
        for(int i = 0; i < n; i++) dp[i][0] = true;
        if(nums[0] <= target) dp[0][nums[0]] = true;

        for(int ind = 1; ind < n; ind++){
            for(int t = 1; t <= target; t++){
                bool notTake = dp[ind-1][t];
                bool take = false;
                if(nums[ind] <= t){
                    take = dp[ind-1][t-nums[ind]];
                }
                dp[ind][t] = take || notTake;
            }
        }

        return dp[n-1][target];

    }
};