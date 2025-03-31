class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> pairSum;

        //for k, we will have k - 1 pairs

        for(int i = 0; i < weights.size() - 1; i++){
            pairSum.push_back(weights[i] + weights[i + 1]);
        }

        sort(pairSum.begin(), pairSum.end());

        long long minSum = 0;
        long long maxSum =0 ;

        for(int i = 0; i < k - 1; i++){
            minSum += pairSum[i];
        }

        int n = pairSum.size();

        for(int i = 0; i < k - 1; i++){
            maxSum += pairSum[n - i - 1];
        }

        return maxSum - minSum;
    }
};