class Solution {
public:
    int t[101][101];
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minSum = INT_MAX;
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> prev(cols, 0);

        for(int i = 0; i < cols; i++){
            prev[i] = matrix[0][i];                     
        }

        for(int i = 1; i < rows; i++){
            vector<int> curr(cols,0);
            for(int j = 0; j < cols; j++){
                int up = prev[j];
                int dl = (j > 0) ? prev[j-1] : INT_MAX;
                int dr = (j < cols - 1) ? prev[j+1] : INT_MAX;

                curr[j] = matrix[i][j] + min(up, min(dl, dr));
                
            }
            prev = curr;
        }    

        for(int j = 0; j < cols; j++){
            minSum = min(minSum, prev[j]);
        }            

        return minSum;

    }


};