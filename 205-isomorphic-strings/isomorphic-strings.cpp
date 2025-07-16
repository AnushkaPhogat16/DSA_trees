class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        int lastS[256] = {0};
        int lastT[256] = {0};

        for(int i = 0; i < s.size(); i++){
            char cs = s[i], ct = t[i];

            if(lastS[cs] != lastT[ct]) return false;

            lastS[cs] = lastT[ct] = i + 1;
        }

        return true;
    }
};