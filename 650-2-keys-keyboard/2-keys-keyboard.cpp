class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;

        int res = 0;

        for (int i = 2; i <= n; i++) {
            while (n % i == 0) {
                res += i;
                n /= i;
            }
        }
        
        return res;
    }
};