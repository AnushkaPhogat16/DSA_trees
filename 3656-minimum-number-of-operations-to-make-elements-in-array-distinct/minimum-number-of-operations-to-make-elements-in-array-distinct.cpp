class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        
        while (true) {
            unordered_set<int> unique(nums.begin(), nums.end());
            if (unique.size() == nums.size()) {
                return operations;
            }
            nums.erase(nums.begin(), nums.begin() + min(3, (int)nums.size()));
            operations++;
        }
        
        return operations;
    }
};
