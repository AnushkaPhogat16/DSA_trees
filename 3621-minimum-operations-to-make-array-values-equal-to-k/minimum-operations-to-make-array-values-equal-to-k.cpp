class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end()); 
        if(nums[0]<k){return -1;}
        int operation = 0;
        for(int i=nums.size()-1;i>=1;--i){
            if(nums[i]!=nums[i-1]){
                ++operation;
            }
        }
        if(nums[0]>k){operation++;} 
        return operation;
    }
};