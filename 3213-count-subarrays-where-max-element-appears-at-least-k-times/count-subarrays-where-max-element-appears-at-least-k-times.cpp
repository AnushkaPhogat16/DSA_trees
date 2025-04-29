class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        long long ans = 0;

        int maxEl = *max_element(nums.begin(), nums.end());
        int countOfMax = 0;

        

        while(end < nums.size()){
            if(nums[end] == maxEl) countOfMax++;

            while(countOfMax >= k){
                ans += nums.size() - end;

                if(nums[start] == maxEl) countOfMax--;

                start++;
            }   

            end++; 
        }

        return ans;
    }
};