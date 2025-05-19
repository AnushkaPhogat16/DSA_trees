class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == 0) return 0;

        if(divisor == -1) return -dividend;
        if(divisor == 1) return dividend;

        bool isNegative = (dividend < 0) ^ (divisor < 0);

        //convert to positive
        //use long to prevent overflow

        long long absDividend = abs((long long) dividend);
        long long absDivisor = abs((long long) divisor);
        int quotient = 0;

        //bitwise division
        while(absDividend >= absDivisor){
            absDividend = absDividend - absDivisor;
            quotient++;
        }

        return isNegative ? -quotient : quotient;
        
    }
};