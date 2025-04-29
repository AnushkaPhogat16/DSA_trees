class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        long long ans = 0;
        int maxEl = *max_element(nums.begin(), nums.end());  
        int n = nums.size();

        vector<int> maxIndices;

        for(int i = 0 ; i< n; i++){
            if(nums[i] == maxEl){
                maxIndices.push_back(i);
            }

            int size = maxIndices.size();

            if(size >= k){
                int last_k = maxIndices[size - k];
                ans += last_k + 1;
            }
        }    

        return ans;
    }
};