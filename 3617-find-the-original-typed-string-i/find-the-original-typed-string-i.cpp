class Solution {
public:
    int possibleStringCount(string word) {
        if (word.empty()) return 0; 

        int ans = 0;
        char prev = word[0];

        for (int i = 1; i < word.length(); i++) {
            if (word[i] == prev) {
                ans++;
            } else {
                prev = word[i];
            }
        }

        return ans + 1;
    }
};
