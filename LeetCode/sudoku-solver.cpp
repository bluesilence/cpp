class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty() || board.size() != board[0].size())
            return;
        
        solveSudokuCore(board);
    }

private:
    bool solveSudokuCore(vector<vector<char>> &board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (int num = 1; num <= 9; num++) {
                        board[i][j] = num + '0';
                        
                        if (isValid(board, i, j)) {
                            if (solveSudokuCore(board))
                                return true;
                        }
                    }
                    
                    board[i][j] = '.';  //Cancel this step
                    
                    return false;   //No possible fill for board[i][j]
                }
            }
        }
        
        //All positions are filled
        return true;
    }
    
    bool isValid(vector<vector<char>> &board, const int i, const int j) {
        if (i < 0 || i > board.size() || j < 0 || j > board[0].size())
            return false;
        
        const int height = board.size();
        const int width = board[0].size();
        
        for (int row = 0; row < height; row++) {
            if (i != row && board[row][j] == board[i][j])
                return false;
        }
        
        for (int col = 0; col < width; col++) {
            if (j != col && board[i][col] == board[i][j])
                return false;
        }
        
        //block number starts from 0
        int blockRow = i / 3;
        int blockCol = j / 3;
        
        int blockRowBegin = 3 * blockRow;
        int blockColBegin = 3 * blockCol;
        
        for (int row = blockRowBegin; row < blockRowBegin + 3; row++) {
            for (int col = blockColBegin; col < blockColBegin + 3; col++) {
                if (i != row && j != col && board[row][col] == board[i][j])
                    return false;
            }
        }
        
        return true;
    }
};
