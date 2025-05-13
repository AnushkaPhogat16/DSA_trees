class Solution {
public:
    const long long MOD = 1e9 + 7;
    int f1(string s, int t){
        vector<int> freq(26,0);
        int n = s.size();
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }
        while(t--){
            int last = freq[25];
            for(int i=25; i>0; i--){
                freq[i] = freq[i-1];
            }
            freq[1] = (freq[1] + last)%MOD;
            freq[0] = last;
        }
        int sum = 0;
        for(int i=0; i<26; i++){
            sum = (sum + freq[i])%MOD;
        }
        return sum;
    }
    int f(int ch, int t){
        if(t < (26 - ch)) return 1;
        // 26 - ch gives the number of transformations for doubling
        return (f(0, t-26 + ch)%MOD + f(1, t-26 + ch)%MOD)%MOD;
    }
    int lengthAfterTransformations(string s, int t) {
        // int val = 0;
        // vector<int> freq(26, 0);
        // vector<int> dp(26, -1);
        // int n = s.size();
        // for(int i=0; i<n; i++){
        //     freq[s[i] - 'a']++;
        // }
        // for(int i=0; i<26; i++){
        //     if(dp[i] == -1){
        //         dp[i] = f(i, t)%MOD;
        //     }
        //     val = (val + (dp[i]*freq[i])%MOD)%MOD;
        // }
        return f1(s, t);
    }
};