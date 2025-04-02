class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxVal = 0;

        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                for(int z = j+1; z < nums.size(); z++){

                    long long curr = (long long)(nums[i] - nums[j]) * nums[z];

                    
                    maxVal = max(maxVal, curr );
                }
            }
        }

        return maxVal;
    }
};