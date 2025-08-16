class Solution {
public:
    vector<char> v{'a', 'e', 'i', 'o', 'u'};
    const int MOD = 1e9+7;
    vector<vector<long long>> dp;

    int countVowelPermutation(int n) {
        dp.assign(n+1, vector<long long>(6, -1)); 
        return solve(0, n, '#');
    }

    int solve(int i, int l, char prev){
        if(i == l) return 1;

        int idx = getIndex(prev);
        if(dp[i][idx] != -1) return dp[i][idx];

        long long ans = 0;

        if(prev == '#'){
            for(char ch : v){
                ans = (ans + solve(i+1, l, ch)) % MOD;
            }
        } else if(prev == 'a'){
            ans = (ans + solve(i+1, l, 'e')) % MOD;
        } else if(prev == 'e'){
            ans = (ans + solve(i+1, l, 'a')) % MOD;
            ans = (ans + solve(i+1, l, 'i')) % MOD;
        } else if(prev == 'i'){
            for(char ch : v){
                if(ch == 'i') continue;
                ans = (ans + solve(i+1, l, ch)) % MOD;
            }
        } else if(prev == 'o'){
            ans = (ans + solve(i+1, l, 'i')) % MOD;
            ans = (ans + solve(i+1, l, 'u')) % MOD;
        } else { // 'u'
            ans = (ans + solve(i+1, l, 'a')) % MOD;
        }

        return dp[i][idx] = ans;
    }

    int getIndex(char c){
        if(c == 'a') return 0;
        if(c == 'e') return 1;
        if(c == 'i') return 2;
        if(c == 'o') return 3;
        if(c == 'u') return 4;
        return 5; // '#'
    }
};
