class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        int prev2 = 0;
        int prev1 = nums[0];
        int curr = 0;

        for(int i = 2; i <= n; i++) {
            curr = max(prev1, prev2 + nums[i - 1]);

            int t = prev1;
            prev1 = curr;
            prev2 = t;
        }

        return curr;
    }
};
