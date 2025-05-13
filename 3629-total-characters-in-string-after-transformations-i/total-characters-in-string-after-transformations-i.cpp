class Solution {
public:
    const int MOD = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<int> mapp(26, 0);

        // Initialize the frequency map
        for (char &ch : s) {
            mapp[ch - 'a']++;
        }

        while (t > 0) {
            vector<int> temp(26, 0);

            for (int i = 0; i < 26; i++) {
                char letter = i + 'a';
                int freq = mapp[i];

                if (letter != 'z') {
                    temp[(letter + 1) - 'a'] = (temp[(letter + 1) - 'a'] + freq) % MOD;
                } else {
                    temp[0] = (temp[0] + freq) % MOD;
                    temp[1] = (temp[1] + freq) % MOD;
                }
            }
            mapp = move(temp);
            t--;
        }

        // Calculate the total length
        long long ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = (ans + mapp[i]) % MOD;
        }

        return ans;
    }
};
