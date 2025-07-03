class Solution {
public:
    int n;
    vector<vector<int>> dp;

    static bool myFunction(string &word1, string& word2){
        return word1.length() < word2.length();
    }

    bool isPred(string &prev, string &curr){
        int M = prev.length();
        int N = curr.length();
        if(M >= N || N - M != 1) return false;

        int i = 0, j = 0;
        while(i < M && j < N){
            if(prev[i] == curr[j]) i++;
            j++;
        }
        return i == M;
    }

    int lis(vector<string>& words, int prevInd, int ind) {
        if(ind == n) return 0;
        if(dp[prevInd+1][ind] != -1) return dp[prevInd+1][ind];

        int taken = 0;
        if(prevInd == -1 || isPred(words[prevInd], words[ind])){
            taken = 1 + lis(words, ind, ind+1);
        }
        int notTaken = lis(words, prevInd, ind+1);

        return dp[prevInd+1][ind] = max(taken, notTaken);
    }

    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(begin(words), end(words), myFunction);
        dp = vector<vector<int>>(n+1, vector<int>(n, -1));
        return lis(words, -1, 0);
    }
};
