class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> closesInRHStoL(n);   // nearest 'L' to the right
        vector<int> closestInLHStoR(n);  // nearest 'R' to the left

        // L to R: Track closest 'R'
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') {
                closestInLHStoR[i] = i;
            } else if (dominoes[i] == '.') {
                closestInLHStoR[i] = i > 0 ? closestInLHStoR[i - 1] : -1;
            } else {
                closestInLHStoR[i] = -1;
            }
        }

        // R to L: Track closest 'L'
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                closesInRHStoL[i] = i;
            } else if (dominoes[i] == '.') {
                closesInRHStoL[i] = i < n - 1 ? closesInRHStoL[i + 1] : -1;
            } else {
                closesInRHStoL[i] = -1;
            }
        }

        string result(n, '.');
        for (int i = 0; i < n; i++) {
            if (dominoes[i] != '.') {
                result[i] = dominoes[i];
                continue;
            }

            int distFromL = closesInRHStoL[i] == -1 ? INT_MAX : abs(closesInRHStoL[i] - i);
            int distFromR = closestInLHStoR[i] == -1 ? INT_MAX : abs(closestInLHStoR[i] - i);

            if (distFromL == distFromR) {
                result[i] = '.';
            } else if (distFromL < distFromR) {
                result[i] = 'L';
            } else {
                result[i] = 'R';
            }
        }

        return result;
    }
};
