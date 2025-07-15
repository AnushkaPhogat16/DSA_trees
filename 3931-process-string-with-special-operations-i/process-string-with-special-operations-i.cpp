class Solution {
public:
    string processStr(string s) {
        vector<char> res;

        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                res.push_back(s[i]);
            }else if(s[i] == '*'){
                if(res.size() >= 1) res.pop_back();
            }else if(s[i] == '#'){
                vector<char> temp = res;
                res.insert(res.end(), temp.begin(), temp.end());
                
            }else if(s[i] == '%'){
                reverse(res.begin(), res.end());
            }
        }

        return string(res.begin(), res.end());
    }
};