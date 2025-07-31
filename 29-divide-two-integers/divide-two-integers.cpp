class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;

        bool sign = (dividend >= 0) == (divisor >= 0);

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long q = 0;

        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            q += 1LL << cnt;
            n -= d << cnt;
        }

        q = sign ? q : -q;

        // Clamp to INT range
        if (q > INT_MAX) return INT_MAX;
        if (q < INT_MIN) return INT_MIN;

        return q;
    }
};
