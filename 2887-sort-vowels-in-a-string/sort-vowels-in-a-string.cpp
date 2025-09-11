#include <cctype>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        // All possible vowel characters
        string vowels = "AEIOUaeiou";
        vector<int> freq(256, 0); // frequency array for ASCII chars

        // Step 1: count vowel frequencies
        for(char c : s) {
            if(vowels.find(c) != string::npos) {
                freq[c]++;
            }
        }

        // Step 2: replace vowels in sorted order (lexicographic by ASCII)
        int idx = 0;
        for(int i = 0; i < s.size(); i++) {
            if(vowels.find(s[i]) != string::npos) {
                // find next smallest vowel
                while(idx < 256 && freq[idx] == 0) idx++;
                s[i] = (char)idx;
                freq[idx]--;
            }
        }
        return s;
    }
};
