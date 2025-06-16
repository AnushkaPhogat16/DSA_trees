class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        int maxDiff = 0;
        int minEl = nums[0];

        for(int i = 0; i < nums.size(); i++){
            minEl = min(minEl , nums[i]);
            maxDiff = max(maxDiff , (nums[i] - minEl));
        }



        return (maxDiff == 0) ? -1 : maxDiff;


    }
};