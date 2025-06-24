class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keyInds;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == key){
                keyInds.push_back(i);
            }
        }

        vector<int> result;

        // [2, 5]

        for(int i = 0; i < nums.size(); i++){
            int minDistFromKey = INT_MAX;
            for(int ind : keyInds){
                minDistFromKey = min(minDistFromKey, abs(i - ind));
            }
            if(minDistFromKey <= k){
                result.push_back(i);
            }
        }

        return result;

    }
};