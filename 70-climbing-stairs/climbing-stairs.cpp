class Solution {
public:
    int t[46];
    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }

    int solve(int n){
        if(n == 0) return t[0] = 1;
        if(n == 1) return t[1] = 1;
        if(n == 2) return t[2] = 2;

        if(t[n] != -1) return t[n];

        return  t[n] = solve(n - 1) + solve(n-2);
    }
};