class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26] = {0};
        int maxV = 0, maxC = 0;

        for(char ch : s) {
            int idx = ch - 'a';
            int f = ++freq[idx];

            if(idx == 0 || idx == 4 || idx == 8 || idx == 14 || idx == 20) {
                maxV = max(maxV, f); // vowel
            } else {
                maxC = max(maxC, f); // consonant
            }
        }

        return maxV + maxC;
    }
};
