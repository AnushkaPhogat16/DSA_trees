class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int i = s.size() - 1;

        while (i >= 0) {
            // 1) skip any spaces
            while (i >= 0 && s[i] == ' ') i--;
            if (i < 0) break;

            // 2) mark end of the current word
            int j = i;

            // 3) find start of the word
            while (i >= 0 && s[i] != ' ') i--;

            // 4) append a separator if this isn’t the first word
            if (!ans.empty()) 
                ans += ' ';

            // 5) append the word s[i+1 .. j]
            ans.append(s, i + 1, j - i);
        }

        return ans;
    }
};
