class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));

        return solve(0, 1, prices, dp, fee);
    }
    
    int solve(int ind, int canBuy, vector<int>& prices, vector<vector<int>>& dp, int fee){

        if(ind == prices.size()){
            return 0;
        }

        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];

        if(canBuy == 1){
            int buy = -prices[ind] + solve(ind + 1, 0, prices, dp, fee);
            int notBought = solve(ind + 1, 1, prices, dp, fee);

            return dp[ind][canBuy] = max(buy, notBought);
        }else{
            int sell = prices[ind] -fee + solve(ind + 1, 1, prices, dp, fee);
            int notSold = solve(ind + 1, 0, prices, dp, fee);

            return dp[ind][canBuy] = max(sell, notSold);
        }
    }
};