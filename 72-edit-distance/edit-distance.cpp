class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // Base case for the first row (converting "" to word2[0..j-1])
        for (int j = 0; j <= m; j++) prev[j] = j;

        for (int i = 1; i <= n; i++) {
            curr[0] = i;  // Base case: converting word1[0..i-1] to ""
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = 1 + min({
                        prev[j],      // delete
                        curr[j - 1],  // insert
                        prev[j - 1]   // replace
                    });
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};
