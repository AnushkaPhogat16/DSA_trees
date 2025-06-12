class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = INT_MIN;
        
        for(int i = 0; i < n; i++){
            if(i + 1 == n){
                maxDiff = max(maxDiff, abs(nums[i] - nums[0]) );
            }else{
                maxDiff = max(maxDiff , abs(nums[i] - nums[i+1]));
            }
        }

        return maxDiff;

        
    }
};

