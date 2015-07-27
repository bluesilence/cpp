class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty())
            return;
        
        const int H = board.size();
        const int W = board[0].size();
        
        if (H < 3 || W < 3)
            return;
        
        queue<int> q;
        
        for (int i = 0; i < H; i++) {
            if (board[i][0] == 'O') {
                floodFillMarkUnsurrounded(board, q, i, 0);
            }
            
            if (board[i][W-1] == 'O') {
                floodFillMarkUnsurrounded(board, q, i, W - 1);
            }
        }
        
        for (int i = 0; i < W; i++) {
            if (board[0][i] == 'O') {
                floodFillMarkUnsurrounded(board, q, 0, i);
            }
            
            if (board[H-1][i] == 'O') {
                floodFillMarkUnsurrounded(board, q, H - 1, i);
            }
        }
        
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                board[i][j] = board[i][j] == 'Z' ? 'O' : 'X';
            }
        }
    }

private:
    void checkAndMark(vector<vector<char>>& board, queue<int>& q, int row, int col) {
        if (row >= board.size() || row < 0 || col >= board[0].size() || col < 0 || board[row][col] != 'O')
            return;
            
        board[row][col] = 'Z';
        q.push(row * board[0].size() + col);
    }
    
    void floodFillMarkUnsurrounded(vector<vector<char>>& board, queue<int>& q, int startRow, int startCol) {
        checkAndMark(board, q, startRow, startCol);
        
        while (!q.empty()) {
            int pos = q.front();
            q.pop();
            
            int row = pos / board.size();
            int col = pos - row * board[0].size();
            
            checkAndMark(board, q, row - 1, col);
            checkAndMark(board, q, row + 1, col);
            checkAndMark(board, q, row, col - 1);
            checkAndMark(board, q, row, col + 1);
        }
    }
};
