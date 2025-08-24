class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0;
        int zs = 0;
        int ans = 0;

        while (r < nums.size()) {
            if (nums[r] == 0) zs++;

            while (zs > 1) {
                if (nums[l] == 0) zs--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++; 
        }

        return ans - 1; 
    }
};
