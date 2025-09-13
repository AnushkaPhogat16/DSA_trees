class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low < high){
            int mid = low + (high - low)/2;

            if(isCheck(piles, h, mid)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }

    bool isCheck(vector<int>& nums, int h, int mid){
        int currSum = 0;
        long long hours = 0;

        for(int num: nums){
  
            hours += (num + mid - 1) / mid;

            if(hours> h) return false;
        }
        return true;
    }
};