class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0;  // No pairs to consider, return 0

        vector<int> pairSum(n - 1);

        // Compute adjacent pair sums directly in the vector
        for (int i = 0; i < n - 1; i++) {
            pairSum[i] = weights[i] + weights[i + 1];
        }

        // Sort the entire array
        sort(pairSum.begin(), pairSum.end());

        long long minSum = 0, maxSum = 0;
        
        // Sum of k-1 smallest and k-1 largest elements
        for (int i = 0; i < k - 1; i++) {
            minSum += pairSum[i];
            maxSum += pairSum[n - 2 - i];  // n-2 because pairSum has size (n-1)
        }

        return maxSum - minSum;
    }
};
