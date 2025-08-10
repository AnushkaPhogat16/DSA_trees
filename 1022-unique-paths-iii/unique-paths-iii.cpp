class Solution {
public:
    int m, n, total;
    int ans = 0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int sx, sy;
        total = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != -1) total++;
                if(grid[i][j] == 1){
                    sx = i; sy = j;
                }
            }
        }


        dfs(grid, sx, sy, 1);
        return ans;
    }

    void dfs(vector<vector<int>>& grid, int x, int y, int count){
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == -1) return;

        if(grid[x][y] == 2){
            if(count == total) ans++;
            return;
        }

        int temp = grid[x][y];
        grid[x][y] = -1;

        dfs(grid, x+1, y, count+1);
        dfs(grid, x-1, y, count+1);
        dfs(grid, x, y+1, count+1);
        dfs(grid, x, y-1, count+1);
        
        grid[x][y] = temp; // unmark visited


    }
};