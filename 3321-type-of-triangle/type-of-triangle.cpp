class Solution {
public:
    string triangleType(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                if(nums[i] >= nums[1] + nums[2]) return "none";
            }else if(i == 1){
                if(nums[i] >= nums[0] + nums[2]) return "none";
            }else{
                if(nums[i] >= nums[0] + nums[1]) return "none";

            }
        }

        int same = 0;
        if(nums[0] == nums[1]) same++;
        if(nums[0] == nums[2]) same++;
        if(nums[1] == nums[2]) same++;

        if(same == 0) return "scalene";
        if(same==1) return "isosceles";
        
        return "equilateral";

        
    }
};