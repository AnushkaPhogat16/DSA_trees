class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == 0) return 0;

        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert to positive and use long long to prevent overflow
        long long absDividend = abs((long long) dividend);
        long long absDivisor = abs((long long) divisor);

        long long quotient = 0;

        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor, multiple = 1;

            // Left shift until tempDivisor exceeds absDividend
            while ((tempDivisor << 1) <= absDividend) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            // Subtract the largest shifted divisor
            absDividend -= tempDivisor;
            quotient += multiple;
        }

        return isNegative ? -quotient : quotient;
    }
};
