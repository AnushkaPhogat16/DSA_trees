class Solution {
public:
    int t[201][201];
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int ind = 0;
        int row = 0;
        memset(t, -1, sizeof(t));
        return solve(ind, row, rows, triangle);
    }

    int solve(int ind, int row, int totalRows, vector<vector<int>>& tri){
        if(row == totalRows-1){
            return tri[row][ind];
        }

        if(row >= totalRows) return INT_MAX;

        if(t[row][ind] != -1) return t[row][ind];

        int down = solve(ind, row + 1, totalRows, tri);
        int dright = solve(ind + 1, row + 1, totalRows, tri);

        return t[row][ind] = tri[row][ind] + min(down, dright);
    }
};