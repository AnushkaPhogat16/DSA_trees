class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }

    bool isSafe(vector<vector<char>>& board, int row, int col, char digit){
        //horizontal
        for(int j = 0; j < 9; j++){
            if(board[row][j] == digit) return false;
        }
        //vertically
        for(int i = 0; i < 9; i++){
            if(board[i][col] == digit) return false;
        }

        // check in grid
        int srow = (row/3)*3;
        int scol = (col/3)*3;

        for(int i = srow; i <= srow + 2; i++){
            for(int j = scol; j <= scol + 2; j++){
                if(board[i][j] == digit) return false;
            }
        }

        return true;
          
    }

    bool helper(vector<vector<char>>& board, int row, int col){

        if(row == 9){
            return true;
        }

        int nextRow = row;
        int nextCol = col + 1;
        if(nextCol == 9){
            nextRow = row + 1;
            nextCol = 0;
        }

        if(board[row][col] != '.'){
            return helper(board, nextRow, nextCol);
        }

        for(char i = '1'; i<= '9'; i++){
            if(isSafe(board, row, col, i)){
                board[row][col] = i;
                if(helper(board, nextRow, nextCol)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }

        return false;
    }
};