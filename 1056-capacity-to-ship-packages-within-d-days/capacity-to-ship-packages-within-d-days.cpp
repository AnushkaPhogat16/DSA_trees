class Solution {
public:

    bool isPossible(vector<int>& nums, int days, int mid){
        int currSum = 0;
        int currDays = 1;

        for(int num : nums){
            if(currSum + num > mid){
                currSum = num;
                currDays++;

                if(currDays > days) return false;
            }else{
                currSum += num;
            }
            
        }
        return true;
    }

    int shipWithinDays(vector<int>& nums, int days) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low < high){
            int mid = low + (high - low)/2;

            if(isPossible(nums, days, mid)){
                high = mid;
            }else{
                low = mid+1;
            }

        }

        return low;
    }
};