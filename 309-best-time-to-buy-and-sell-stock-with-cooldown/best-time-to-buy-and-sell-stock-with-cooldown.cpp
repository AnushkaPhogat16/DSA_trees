class Solution {
public:

    int f(int ind, int buy, int n, vector<int>& prices, vector<vector<int>>& dp){
        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }

        if(ind == n){
            return 0;
        }

        // can be bought if buy = 1
        // if bought then next day cant buy until sold
        if(buy == 1){
            return dp[ind][buy] = 
            max( -prices[ind] + f(ind + 1, 0, n, prices, dp) , f(ind + 1, 1, n, prices, dp) );
        }else if(buy == 2){
            return dp[ind][buy] = f(ind + 1, 1, n, prices, dp);
        }

        // if sold then nex day cant buy
        return dp[ind][buy] =
        max( prices[ind] + f(ind + 1, 2, n, prices, dp), f(ind + 1, 0, n, prices, dp));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(4, -1));

        return f(0, 1, n, prices, dp);

    }
};