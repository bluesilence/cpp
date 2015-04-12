class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        if (board.size() != board[0].size() || board.size() <= 0 || board[0].size() <= 0)
            return;
        
        solveSudokuCore(board);
    }

private:
    bool solveSudokuCore(vector<vector<char> > &board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if ('.' == board[row][col]) {
                    for (int i = 1; i <= 9; i++) {
                        board[row][col] = '0' + i;
                        
                        if (isValid(board, row, col)) {
                            if (solveSudokuCore(board)) {
                                return true;
                            }
                        }
                        
                        board[row][col] = '.';
                    }
                    
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isValid(vector<vector<char> > &board, const int row, const int col) {
        //Check row
        for (int i = 0; i < 9; i++) {
            if (i != col && board[row][i] == board[row][col])
                return false;
        }
        
        //Check col
        for (int i = 0; i < 9; i++) {
            if (i != row && board[i][col] == board[row][col])
                return false;
        }
        
        //Check block
        const int blockRow = row / 3;
        const int blockCol = col / 3;
        for (int i = blockRow*3; i < blockRow*3 + 3; i++) {
            for (int j = blockCol*3; j < blockCol*3 + 3; j++) {
                if (i != row && j != col && board[i][j] == board[row][col])
                    return false;
            }
        }
        
        return true;
    }
};
