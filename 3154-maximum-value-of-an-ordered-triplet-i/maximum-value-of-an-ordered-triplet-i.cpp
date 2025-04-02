class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int n = nums.size();
        long long maxVal = 0;

        int maxLeft = nums[0];
        vector<int> suffMax(n, 0);
        suffMax[n - 1] = nums[n - 1];

        for(int k = n - 2; k >= 0; k--){
            suffMax[k] = max(nums[k], suffMax[k + 1]);
        }

        for(int j = 1; j < n - 1; j++){
            if(nums[j] < maxLeft){
                long long eq = (long long)(maxLeft - nums[j]) * suffMax[j + 1];
                maxVal = max(maxVal, eq);
            }

            maxLeft = max(maxLeft, nums[j]);
        }

        return maxVal;
    }
};