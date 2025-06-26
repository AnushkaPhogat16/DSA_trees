class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int prev1 = nums[0];
        int prev2 = 0;
        int currCase1 = 0;

        for(int i = 1; i < n - 1; i++){
            int take = nums[i] + prev2;
            int notTake = prev1;

            currCase1 = max(take, notTake);

            int t = prev1;
            prev1 = currCase1;
            prev2  = t;
        }

        prev1 = nums[1];
        prev2 = 0;
        int currCase2 = 0;

        for(int i = 2; i < n; i++){
            int take = nums[i] + prev2;
            int notTake = prev1;

            currCase2 = max(take, notTake);

            int t = prev1;
            prev1 = currCase2;
            prev2  = t;
        }



        return max(currCase1, currCase2);
    }
};