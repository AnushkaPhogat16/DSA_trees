class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (!(isRow(board, i)) || !(isCol(board, i))) {
                return false;
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!(isBoard(board, i, j))) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool isRow(vector<vector<char>>& board, int row) {
        unordered_set<char> done;
        for (int j = 0; j < 9; j++) {
            char current = board[row][j];
            if (current != '.' && !done.insert(current).second) {
                return false;
            }
        }

        return true;
    }

    bool isCol(vector<vector<char>>& board, int col) {
        unordered_set<char> done;
        for (int i = 0; i < 9; i++) {
            char current = board[i][col];
            if (current != '.' && !done.insert(current).second) {
                return false;
            }
        }

        return true;
    }

    bool isBoard(vector<vector<char>>& board, int srow, int scol) {
        unordered_set<char> seen;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                char current = board[srow + i][scol + j];
                if (current != '.' && !seen.insert(current).second) {
                    return false;
                }
            }
        }

        return true;
    }
};
