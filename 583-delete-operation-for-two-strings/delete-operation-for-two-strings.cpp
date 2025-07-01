class Solution {
public:
    int t[501][501];
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        int i = n-1;
        int j = m-1;

        memset(t, -1, sizeof(t));

        int commonChars = solve(i, j, word1, word2);

        return n + m - 2*commonChars;


    } 

    int solve(int i, int j, string& w1, string& w2){
        if(i < 0 || j < 0){
            return 0;
        }

        if(t[i][j] != -1) return t[i][j];

        if(w1[i] == w2[j]){
            return t[i][j] = 1 + solve(i - 1, j - 1, w1, w2);
        }

        return t[i][j] = max(solve(i, j - 1, w1, w2), solve(i-1, j, w1, w2));
    }
};