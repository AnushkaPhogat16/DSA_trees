class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        int n = words.size();
        int prevGroup = -1;

        for (int i = 0; i < n; i++) {
            if (groups[i] != prevGroup) {
                result.push_back(words[i]);
                prevGroup = groups[i];
            }
        }

        return result;
    }
};
