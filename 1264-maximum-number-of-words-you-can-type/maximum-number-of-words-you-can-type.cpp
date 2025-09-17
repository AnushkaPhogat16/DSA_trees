class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // Step 1: Store broken letters in a boolean array
        bool broken[26] = {false};
        for (char c : brokenLetters) {
            broken[c - 'a'] = true;
        }

        // Step 2: Traverse text word by word
        int ans = 0;
        bool valid = true;

        for (char c : text) {
            if (c == ' ') {
                if (valid) ans++;  // word completed
                valid = true;      // reset for next word
            } 
            else if (broken[c - 'a']) {
                valid = false;     // mark word as invalid
            }
        }

        // Step 3: Handle the last word (no trailing space)
        if (valid) ans++;

        return ans;
    }
};
