class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};

        sort(nums.begin(), nums.end()); 

        vector<int> dp(n, 1); 
        vector<int> prevInd(n, -1); 

        int maxL = 1;  
        int lastChosenIndForMaxL = 0; 

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    prevInd[i] = j;
                }
            }
            if(dp[i] > maxL){
                maxL = dp[i];
                lastChosenIndForMaxL = i;
            }
        }

        vector<int> result;
        while(lastChosenIndForMaxL != -1){
            result.push_back(nums[lastChosenIndForMaxL]);
            lastChosenIndForMaxL = prevInd[lastChosenIndForMaxL];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
