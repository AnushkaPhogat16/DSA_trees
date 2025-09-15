class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int pos = 0, neg = 0;  // lengths of subarrays ending here
        int maxLen = 0;

        for (int x : nums) {
            if (x > 0) {
                pos = pos + 1;
                neg = (neg > 0) ? neg + 1 : 0;
            } 
            else if (x < 0) {
                int newPos = (neg > 0) ? neg + 1 : 0;
                int newNeg = pos + 1;
                pos = newPos;
                neg = newNeg;
            } 
            else { // x == 0
                pos = 0;
                neg = 0;
            }

            maxLen = max(maxLen, pos);
        }

        return maxLen;
    }
};
