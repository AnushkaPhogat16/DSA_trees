class Solution {
public:
    int t[201][201];
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = INT_MIN;
        int rows = matrix.size();
        int cols = matrix[0].size();

        memset(t, -1, sizeof(t));

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                ans = max(ans, solve(i, j, matrix, -1));
            }
        }

        return ans;
    }

    int solve(int i, int j, vector<vector<int>>& matrix, int prevVal){
        int rows = matrix.size();
        int cols = matrix[0].size();

        // base cases
        if(i >= rows || j >= cols || i < 0|| j < 0) return 0;
        if(matrix[i][j] <= prevVal) return 0;

        if(t[i][j] != -1) return t[i][j];
        

        int up = solve(i-1, j, matrix, matrix[i][j]);
        int left = solve(i, j-1, matrix, matrix[i][j]);
        int down = solve(i+1, j, matrix, matrix[i][j]);
        int right = solve(i, j + 1, matrix, matrix[i][j]);

        return t[i][j] = 1 + max(up, max(left, max(down, right)));
    }
};