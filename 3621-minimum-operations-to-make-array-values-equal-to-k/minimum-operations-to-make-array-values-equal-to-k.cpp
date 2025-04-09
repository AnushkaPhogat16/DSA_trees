class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        //return the number of distinct integers in the array that are greater than k.
        unordered_set<int> avail;
        int minOp = 0;
        for(int i = 0; i < nums.size(); i++){
            avail.insert(nums[i]);
        }

        for(auto& el : avail){
            if(el > k) minOp++;
            if(el < k) return -1;
        }

       if (avail.size() == 1 && *avail.begin() == k){
            return 0;
        }

        return minOp;
        
    }
};