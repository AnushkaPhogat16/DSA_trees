class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX;
        int prof = 0;
        for(int i = 0; i < prices.size(); i++){
            minVal = min(minVal, prices[i]);
            prof = max(prof, prices[i]- minVal);
        }

        return prof;
    }
};