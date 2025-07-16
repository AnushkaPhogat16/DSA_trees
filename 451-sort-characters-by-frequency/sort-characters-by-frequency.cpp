class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for (char ch : s) freqMap[ch]++;

        // Bucket sort: bucket[i] holds all characters with frequency i
        int n = s.size();
        vector<vector<char>> buckets(n + 1);
        for (auto &[ch, freq] : freqMap) {
            buckets[freq].push_back(ch);
        }

        string res;
        for (int i = n; i > 0; --i) {
            for (char ch : buckets[i]) {
                res += string(i, ch);
            }
        }

        return res;
    }
};
