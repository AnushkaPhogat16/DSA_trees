class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int l = 0, r = 0;
        int ans = r - l + 1;



        unordered_map<char, int> f;
        f[s[0]]++;

        
        while(r < s.size()-1){
            r++;
            f[s[r]]++;
            while(f[s[r]] > 1){
                f[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
        
    }
};