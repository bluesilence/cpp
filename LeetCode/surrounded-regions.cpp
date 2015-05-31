class Solution {
public:
    void solve(vector<vector<char>> &board) {
        //For each 'O' in the edges of the board, the adjacent 'O's it could reach is the 'O's not surrounded by 'X's at last
        if (board.empty())
            return;
        
        height = board.size();
        width = board[0].size();
        
        if (height < 3 || width < 3)
            return;
        
        //Clear last queue
        while (!q.empty()) {
            q.pop();
        }
        
        //Mark regions that are not surrounded starting from 'O's at the first/last row
        for (int i = 0; i < width; i++) {
            BFSCheckAndMarkSurroundedRegionStartedFrom(0, i, board);
            BFSCheckAndMarkSurroundedRegionStartedFrom(height - 1, i, board);
        }
        
        //Mark regions that are not surrounded starting from 'O's at the first/last column
        for (int i = 0; i < height; i++) {
            BFSCheckAndMarkSurroundedRegionStartedFrom(i, 0, board);
            BFSCheckAndMarkSurroundedRegionStartedFrom(i, width - 1, board);
        }
        
        //Flip all 'O's except those that are not surrounded
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                board[i][j] = board[i][j] == 'Z' ? 'O' : 'X';
            }
        }
    }

private:
    queue<int> q;
    int height;
    int width;
    
    //Mark surrounded region with 'Z'
    void checkAndMark(int x, int y, vector<vector<char>> &board) {
        if (x >= 0 && x < height && y >= 0 && y < width && board[x][y] == 'O') {
            board[x][y] = 'Z';
            q.push(x * width + y);
        }    
    }
    
    void BFSCheckAndMarkSurroundedRegionStartedFrom(int xIndex, int yIndex, vector<vector<char>> &board) {
        checkAndMark(xIndex, yIndex, board);
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            
            int px = p / width;
            int py = p % width;
            
            //Check all 4 adjacent positions
            checkAndMark(px - 1, py, board);
            checkAndMark(px + 1, py, board);
            checkAndMark(px, py - 1, board);
            checkAndMark(px, py + 1, board);
        }
    }
};
