class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int firstRow = -1, lastRow = -1;
        int firstCol = -1, lastCol = -1;

        // first row
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    firstRow = i;
                    goto foundFirstRow;
                }
            }
        }
        foundFirstRow:;

        // first col
        for(int j = 0; j < grid[0].size(); j++){
            for(int i = 0; i < grid.size(); i++){
                if(grid[i][j] == 1){
                    firstCol = j;
                    goto foundFirstCol;
                }
            }
        }
        foundFirstCol:;

        // last row
        for(int i = grid.size()-1; i >= 0; i--){
            for(int j = grid[0].size()-1; j >= 0; j--){
                if(grid[i][j] == 1){
                    lastRow = i;
                    goto foundLastRow;
                }
            }
        }
        foundLastRow:;

        // last col
        for(int j = grid[0].size()-1; j >= 0; j--){
            for(int i = grid.size()-1; i >= 0; i--){
                if(grid[i][j] == 1){
                    lastCol = j;
                    goto foundLastCol;
                }
            }
        }
        foundLastCol:;

        return (lastRow - firstRow + 1) * (lastCol - firstCol + 1);
    }
};
