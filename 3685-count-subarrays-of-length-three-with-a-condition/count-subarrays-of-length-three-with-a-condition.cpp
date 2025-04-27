class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for (int i = 0; i + 2 < n; i++) {
            cnt += (nums[i] + nums[i + 2] == (long double)nums[i + 1] / 2);
        }
        return cnt;
    }
};