class Solution {
public:
    int t[201][10001];
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;
        int target = total / 2;
        memset(t, -1, sizeof(t));
        return f(nums.size() - 1, target, nums);
    }

    bool f(int ind, int tgt, vector<int>& nums){
        if(tgt == 0) return true;
        if(ind  == 0) return nums[0] == tgt;

        if(t[ind][tgt] != -1) return t[ind][tgt];

        bool notTake = f(ind - 1, tgt, nums);
        bool take = false;
        if(nums[ind] <= tgt){
            take = f(ind-1, tgt-nums[ind], nums);
        }

        return t[ind][tgt] = take || notTake;
    }
};