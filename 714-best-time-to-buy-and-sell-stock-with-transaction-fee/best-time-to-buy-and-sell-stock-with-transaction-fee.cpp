class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> next(2,0);

        next[0] = next[1] = 0;

        for(int ind = n-1; ind >= 0; ind--){
            vector<int> curr(2, 0);
            for(int canBuy = 0; canBuy <=1; canBuy++){
                long profit = 0;
                if(canBuy == 1){
                    profit = max( (-prices[ind] + next[0]), next[1] );
                }else{
                    profit = max( (prices[ind] -fee + next[1]), next[0] );
                }
                curr[canBuy] = profit;
            }
            next = curr;
        }

        return (next[1]);
    }
};