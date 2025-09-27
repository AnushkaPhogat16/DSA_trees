class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxf = 0;
        int ans = 0;

        unordered_map<int, int> f;

        for(int r = 0; r < s.size(); r++){
            f[s[r]]++;
            //max f in window
            maxf = max(maxf, f[s[r]]);

            int rep = r - l + 1 - maxf;
            while(rep > k){
                f[s[l]]--;
                l++;

                rep = r - l + 1 - maxf;
            }

            ans = max(ans, r - l + 1);


        }

        return ans;


    }
};