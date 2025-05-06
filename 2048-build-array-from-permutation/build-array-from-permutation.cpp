class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> sol;
        int count=0;
        for(int i:nums){
            
            sol.push_back(nums[nums[count]]);
            count++;
        }

        return sol;

    }
};