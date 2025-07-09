class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    void solve(vector<vector<char>>& board) {
        // start from boundary 0s nd mark as 'can nver be surrounded'
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));
        //trav 1st nd last row
        for(int j = 0; j < m; j++){

            //first row
            if(!ans[0][j] && board[0][j] == 'O'){
                dfs(0, j, ans, board);
            }

            // last row
            if(!ans[n-1][j] && board[n-1][j] == 'O'){
                dfs(n - 1, j, ans, board);
            }

        }

        // first nd last col
        for(int i = 0; i < n; i++){
            if(!ans[i][0] && board[i][0] == 'O'){
                dfs(i, 0, ans, board);
            }

            if(!ans[i][m-1] && board[i][m-1] == 'O'){
                dfs(i, m-1, ans, board);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!ans[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(int i, int j, vector<vector<int>>& ans, vector<vector<char>>& board){
        ans[i][j] = 1;
        
        int n = board.size();
        int m = board[0].size();
        // check in all 4 directions
        for(int d = 0; d < 4; d++){
            int nrow = i + dx[d];
            int ncol = j + dy[d];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !ans[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow, ncol, ans, board);
            }
        }


    }
};