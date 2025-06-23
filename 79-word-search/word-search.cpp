class Solution {
public:
    int m, n;
    vector<vector<int>> direcs{{1,0},{-1,0},{0,1},{0,-1}};

    bool dfs(vector<vector<char>>& board,
             int i, int j, int idx,
             const string& word)
    {
        if (idx == (int)word.size()) 
            return true;

        if (i<0 || j<0 || i>=m || j>=n || board[i][j]=='$')
            return false;
        if (board[i][j] != word[idx]) 
            return false;

        char tmp = board[i][j];
        board[i][j] = '$';
        for (auto &d : direcs) {
            if (dfs(board, i+d[0], j+d[1], idx+1, word))
                return true;
        }
        board[i][j] = tmp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board.empty() ? 0 : board[0].size();
        if (m==0 || n==0) return false;

        // —————————————————————————————
        // 1) Global frequency prune (256‐size arrays)
        vector<int> freqB(256,0), freqW(256,0);
        for (auto &row : board)
            for (char c : row)
                freqB[(unsigned char)c]++;
        for (char c : word)
            freqW[(unsigned char)c]++;
        // if any needed char is more than available, fail early
        for (int c = 0; c < 256; c++) {
            if (freqW[c] > freqB[c])
                return false;
        }

        // —————————————————————————————
        // 2) Rarity heuristic: search from the rarer end
        char f = word.front(), b = word.back();
        if (freqB[(unsigned char)b] < freqB[(unsigned char)f]) {
            reverse(word.begin(), word.end());
        }
        char startChar = word.front();

        // —————————————————————————————
        // 3) DFS only from startChar cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == startChar &&
                    dfs(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
};
