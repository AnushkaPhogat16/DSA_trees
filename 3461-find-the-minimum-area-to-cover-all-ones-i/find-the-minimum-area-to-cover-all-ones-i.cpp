class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int firstRow = m, lastRow = -1;
        int firstCol = n, lastCol = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    firstRow = min(firstRow, i);
                    lastRow  = max(lastRow, i);
                    firstCol = min(firstCol, j);
                    lastCol  = max(lastCol, j);
                }
            }
        }

        if (lastRow == -1) return 0; // no '1' in grid

        return (lastRow - firstRow + 1) * (lastCol - firstCol + 1);
    }
};
