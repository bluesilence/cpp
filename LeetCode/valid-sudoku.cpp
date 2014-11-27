class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<int> counts(9, 0);
        
        for (int i = 0; i < 9; i++) {
            counts.assign(9, 0);
            
            //Validate row
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (ch != '.') {
                    if (counts[ch - '1'] > 0)
                        return false;
                    else
                        counts[ch - '1']++;
                }
            }
        }
        
        for (int j = 0; j < board[0].size(); j++) {
            counts.assign(9, 0);
            
            //Validate column
            for (int i = 0; i < board.size(); i++) {
                char ch = board[i][j];
                if (ch != '.') {
                    counts[ch - '1']++;
                    if (counts[ch - '1'] > 1)
                        return false;
                }
            }
        }
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                counts.assign(9, 0);
                
                int row, col;
                for (int k = 0; k < 9; k++) {
                    row = k / 3 + 3 * i;
                    col = k % 3 + 3 * j;
                    
                    //Validate cubicle
                    char ch = board[row][col];
                    if (ch != '.') {
                        counts[ch - '1']++;
                        if (counts[ch - '1'] > 1)
                            return false;
                    }
                }
            }
        }
        
        return true;
    }
};
