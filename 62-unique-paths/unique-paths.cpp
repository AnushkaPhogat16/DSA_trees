class Solution {
public:
    int t[101][101];
    int uniquePaths(int m, int n) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, m , n);
    }

    int solve(int ind1, int ind2, int m, int n){
        if(ind1 == m - 1 && ind2 == n - 1){
            return 1;
        }

        if(ind1 >= m || ind2 >= n){
            return 0;
        }

        if(t[ind1][ind2] != -1) return t[ind1][ind2];

        return t[ind1][ind2] = (solve(ind1 + 1, ind2, m , n) + solve(ind1, ind2+1, m, n));
    }
};