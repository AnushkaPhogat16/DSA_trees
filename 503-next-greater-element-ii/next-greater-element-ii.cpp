class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size() , -1);
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j <= i + nums.size() - 1; j++){
                int index = (j % nums.size());
                if(nums[index] > nums[i]){
                    ans[i] = nums[index];
                    break;
                }
            }
        }

        return ans;
    }
};

// 0 1 2 3 4 | 5 6 7 8 9 
      
//       at 2
//       start at 2 + 1 = 3 -> go till 2 + 4 = 6

// so i am going to i + n - 1 always
// at 4 we go from 5 to 8

