class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        unordered_map<char, char> match;
        unordered_map<char, char> match2;

        int j = 0;
        int k = 0;

        for(int i = 0; i < s.size(); i++){
            if(match.find(s[i]) != match.end()){
                if(t[j] != match[s[i]]){
                    return false;
                }
            }
            match[s[i]] = t[j];
            j++;
        }

        for(int i = 0; i < t.size(); i++){
            if(match2.find(t[i]) != match2.end()){
                if(s[k] != match2[t[i]]){
                    return false;
                }
            }
            match2[t[i]] = s[k];
            k++;
        }

        return true;
    }
};