class Solution {
public:

    bool canSplit(vector<int>& nums, int k, long long mid){
        long long currSum = 0;
        int count = 1; //atleast 1 group
        for(int num : nums){
            if(currSum + num > mid){
                count++;
                currSum = num;
                if(count > k) return false;
            }else{
                currSum += num;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        while(low < high){
            long long mid = low + (high - low)/2;

            if(canSplit(nums, k, mid)){
                high = mid;
            }else{
                low = mid + 1;
            }
        }

        return int(low);

    }
};