class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int n = nums.size();
        long long maxVal = 0;

        long long bestDif = INT_MIN;
        int maxi = nums[0];

        for(int k = 2; k < n; k++){
            bestDif = max(bestDif, (long long)(maxi - nums[k - 1] ));
            maxVal = max(maxVal , (long long)(bestDif * nums[k]));
            maxi = max(maxi, nums[k - 1]);

        }

        return maxVal;
    }
};