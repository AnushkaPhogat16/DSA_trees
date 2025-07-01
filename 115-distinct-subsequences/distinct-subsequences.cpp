class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<unsigned long long> prev(m + 1, 0), curr(m + 1, 0);

        prev[0] = 1;  

        for (int i = 1; i <= n; i++) {
            curr[0] = 1;  
            for (int j = m; j >= 1; j--) {  
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j - 1] + prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return static_cast<int>(prev[m]);
    }
};
