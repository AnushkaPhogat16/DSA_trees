class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        int left = 0;
        int right = 0;

        long long lenn = 1;
        long long sum = nums[right];

        while (right < nums.size()) {
            if (sum * lenn < k) {
                ans += right - left + 1;
                right++;
                if (right < nums.size()) {
                    sum += nums[right];
                    lenn++;
                }
            } else {
                sum -= nums[left];
                left++;
                lenn--;
            }
        }

        return ans;
    }
};
