class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));

        return solve(0, 1, prices, dp);
    }
    
    int solve(int ind, int canBuy, vector<int>& prices, vector<vector<int>>& dp){

        if(ind == prices.size()){
            return 0;
        }

        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];

        if(canBuy == 1){
            int buy = -prices[ind] + solve(ind + 1, 0, prices, dp);
            int notBought = solve(ind + 1, 1, prices, dp);

            return dp[ind][canBuy] = max(buy, notBought);
        }else{
            int sell = prices[ind] + solve(ind + 1, 1, prices, dp);
            int notSold = solve(ind + 1, 0, prices, dp);

            return dp[ind][canBuy] = max(sell, notSold);
        }
    }
};