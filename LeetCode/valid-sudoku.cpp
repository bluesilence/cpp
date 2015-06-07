class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return false;
        
        const int height = board.size();
        const int width = board[0].size();
        
        //numbers start from 1, not 0
        vector<bool> occurred(height + 1, false);
        
        //Check rows
        for (int i = 0; i < height; i++) {
            fill(occurred.begin(), occurred.end(), false);
            for (int j = 0; j < width; j++) {
                if (board[i][j] != '.') {
                    int digit = board[i][j] - '0';
                    if (occurred[digit] == true) {
                        return false;
                    } else {
                        occurred[digit] = true;
                    }
                }
            }
        }
        
        //Check cols
        for (int j = 0; j < width; j++) {
            fill(occurred.begin(), occurred.end(), false);
            for (int i = 0; i < height; i++) {
                if (board[i][j] != '.') {
                    int digit = board[i][j] - '0';
                    if (occurred[digit] == true) {
                        return false;
                    } else {
                        occurred[digit] = true;
                    }
                }
            }
        }
        
        //Check blocks
        for (int i = 0; i < 9; i++) {
            fill(occurred.begin(), occurred.end(), false);
            int rowBegin = 3 * (i / 3);
            int rowEnd = rowBegin + 2;
            int colBegin = 3 * (i % 3);
            int colEnd = colBegin + 2;
            
            for (int i = rowBegin; i <= rowEnd; i++) {
                for (int j = colBegin; j <= colEnd; j++) {
                    if (board[i][j] != '.') {
                        int digit = board[i][j] - '0';
                        if (occurred[digit] == true) {
                            return false;
                        } else {
                            occurred[digit] = true;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
