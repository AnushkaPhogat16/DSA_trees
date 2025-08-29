class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> diag; // key = (i-j), value = diagonal elements
        unordered_map<int, int> idx;          // index tracker for each diagonal

        // Step 1: Collect diagonals
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diag[i - j].push_back(grid[i][j]);
            }
        }

        // Step 2: Sort diagonals based on rule
        for (auto &it : diag) {
            if (it.first >= 0) {
                // bottom-left (including main diagonal) → sort descending
                sort(it.second.begin(), it.second.end(), greater<int>());
            } else {
                // top-right → sort ascending
                sort(it.second.begin(), it.second.end());
            }
            idx[it.first] = 0; // initialize index
        }

        // Step 3: Refill matrix in correct order
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int key = i - j;
                grid[i][j] = diag[key][idx[key]++];
            }
        }

        return grid;
    }
};
