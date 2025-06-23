class Solution {
public:
    vector<vector<string>> result;
    int N;
    unordered_set<int> cols, diag1, diag2;

    void solve(vector<string>& board, int row) {
        if (row == N) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < N; ++col) {
            if (cols.count(col) || diag1.count(row - col) || diag2.count(row + col))
                continue;

            // Place queen
            board[row][col] = 'Q';
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            solve(board, row + 1);

            // Backtrack
            board[row][col] = '.';
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(n, string(n, '.'));
        solve(board, 0);
        return result;
    }
};
