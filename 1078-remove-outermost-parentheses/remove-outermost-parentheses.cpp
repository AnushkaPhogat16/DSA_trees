class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;

        for (char c : s) {
            if (c == '(') {
                if (depth > 0) ans += c;  // skip the outermost '('
                depth++;
            } else {
                depth--;
                if (depth > 0) ans += c;  // skip the outermost ')'
            }
        }

        return ans;
    }
};
