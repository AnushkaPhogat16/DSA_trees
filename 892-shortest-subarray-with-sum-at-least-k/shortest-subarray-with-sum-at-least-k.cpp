#include <vector>
#include <deque>
#include <climits>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        // prefix sums: P[0] = 0, P[i] = sum of first i elements (nums[0..i-1])
        vector<long long> P(n + 1, 0);
        for (int i = 0; i < n; ++i) P[i + 1] = P[i] + nums[i];

        deque<int> dq;               // will store indices of P[], with increasing P[] values
        long long best = (long long)INT_MAX + 1LL; // use large sentinel

        for (int j = 0; j <= n; ++j) {
            // 1) If current prefix minus smallest prefix in deque >= k, we found valid subarray(s)
            while (!dq.empty() && P[j] - P[dq.front()] >= k) {
                best = min(best, (long long)j - dq.front());
                dq.pop_front(); // pop because it cannot give shorter subarray for future j
            }

            // 2) Maintain monotonicity: remove indices with prefix >= current prefix
            //    because current index j is later and has smaller or equal prefix, so it's better.
            while (!dq.empty() && P[j] <= P[dq.back()]) dq.pop_back();

            // 3) Add current index as a candidate start
            dq.push_back(j);
        }

        return (best <= n) ? (int)best : -1;
    }
};
