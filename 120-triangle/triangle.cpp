class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int ind = 0;
        int row = 0;
        
        vector<int> bottRow(rows, 0);

        for(int i = 0; i < rows; i++){
            bottRow[i] = triangle[rows-1][i];
        }

        for (int row = rows - 2; row >= 0; row--) {
            vector<int> curr(rows, 0);
            for (int col = 0; col <= row; col++) {
                curr[col] = triangle[row][col] + min( bottRow[col], bottRow[col+1] );
            }

            bottRow = curr;
        }

        return bottRow[0];

    }
};