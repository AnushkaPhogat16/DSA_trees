class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> forces(n, 0);

        int force = 0;
        // Left to right for 'R'
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'R') {
                force = n;  // maximum force
            } else if (dominoes[i] == 'L') {
                force = 0;
            } else {
                force = max(force - 1, 0);
            }
            forces[i] += force;
        }

        force = 0;
        // Right to left for 'L'
        for (int i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'L') {
                force = n;
            } else if (dominoes[i] == 'R') {
                force = 0;
            } else {
                force = max(force - 1, 0);
            }
            forces[i] -= force;
        }

        string result(n, '.');
        for (int i = 0; i < n; ++i) {
            if (forces[i] > 0) {
                result[i] = 'R';
            } else if (forces[i] < 0) {
                result[i] = 'L';
            }
        }

        return result;
    }
};
