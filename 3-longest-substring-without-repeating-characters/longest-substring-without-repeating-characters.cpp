class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lseen(256, -1);
        int ans = 0;
        int l = 0;
        
        for(int r = 0; r < s.size(); r++){
            if(lseen[s[r]] >= l){
                l = lseen[s[r]]+1;
            }

            lseen[s[r]] = r;

            ans = max(ans, r - l + 1);
        }

        return ans;


    }
};