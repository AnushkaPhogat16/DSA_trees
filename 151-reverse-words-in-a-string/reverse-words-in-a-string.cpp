class Solution {
public:
    string reverseWords(string s) {
        stack<char> word;
        bool atStart = true;
        string ans = "";

        for(int i = s.size() - 1; i >= -1; i--){
            // end‐of‐string or end‐of‐word?
            if (i == -1 || (s[i] == ' ' && !atStart)) {
                if (!word.empty()) {
                    // only add a space if this isn't the first word
                    if (!ans.empty()) 
                        ans += ' ';

                    // dump the reversed word
                    while (!word.empty()) {
                        ans += word.top();
                        word.pop();
                    }
                }
                atStart = true;
            }
            // accumulate letters into the stack
            else if (s[i] != ' ') {
                word.push(s[i]);
                atStart = false;
            }
        }

        return ans;
    }
};
