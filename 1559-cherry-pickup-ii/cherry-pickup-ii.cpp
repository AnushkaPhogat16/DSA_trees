class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> next(cols, vector<int>(cols, 0));
        vector<vector<int>> curr(cols, vector<int>(cols, 0));

        // Base case: last row
        for (int j1 = 0; j1 < cols; j1++) {
            for (int j2 = 0; j2 < cols; j2++) {
                next[j1][j2] = (j1 == j2) ? grid[rows-1][j1] : grid[rows-1][j1] + grid[rows-1][j2];
            }
        }

        // Process from bottom-2 row up to top
        for (int i = rows-2; i >= 0; i--) {
            for (int j1 = 0; j1 < cols; j1++) {
                for (int j2 = 0; j2 < cols; j2++) {
                    int maxVal = INT_MIN;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;
                            if (nj1 >= 0 && nj1 < cols && nj2 >= 0 && nj2 < cols) {
                                maxVal = max(maxVal, next[nj1][nj2]);
                            }
                        }
                    }
                    int cherries = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                    curr[j1][j2] = cherries + (maxVal == INT_MIN ? 0 : maxVal);
                }
            }
            next = curr; // Move up one row
        }

        return next[0][cols-1];
    }
};
