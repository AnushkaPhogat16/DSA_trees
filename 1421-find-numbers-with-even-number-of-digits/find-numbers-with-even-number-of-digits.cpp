class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i];
            int dig = 0;

            while(curr > 0){
                curr = curr/10;
                dig++;
            }

            if(dig % 2 == 0) ans++;
        }

        return ans;
    }
};

