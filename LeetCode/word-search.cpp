class Solution {
public:
    //Use DFS
    bool exist(vector<vector<char> > &board, string word) {
        if (word.empty() || board.empty() || board[0].empty())
            return false;
        
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
        
        const char firstChar = word[0];
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == firstChar) {
                    visited[i][j] = true;
                    if (dfs(board, word, visited, i, j, 1)) {
                        return true;
                    }
                    
                    visited[i][j] = false;
                }
            }
        }
        
        return false;
    }

private:
    bool dfs(vector<vector<char> > &board, string &word, vector<vector<bool> > &visited, int row, int col, int nextCharIndex) {
        if (nextCharIndex == word.size()) {
            return true;
        }
        
        bool success = false;
        if (!success && row + 1 < board.size() && !visited[row+1][col] && word[nextCharIndex] == board[row+1][col]) {
            visited[row+1][col] = true;
            success = dfs(board, word, visited, row + 1, col, nextCharIndex + 1);
            visited[row+1][col] = false;
        }
        
        if (!success && row - 1 >= 0 && !visited[row-1][col] && word[nextCharIndex] == board[row-1][col]) {
            visited[row-1][col] = true;
            success = dfs(board, word, visited, row - 1, col, nextCharIndex + 1);
            visited[row-1][col] = false;
        }
        
        if (!success && col + 1 < board[0].size() && !visited[row][col+1] && word[nextCharIndex] == board[row][col+1]) {
            visited[row][col+1] = true;
            success = dfs(board, word, visited, row, col + 1, nextCharIndex + 1);
            visited[row][col+1] = false;
        }
        
        if (!success && col - 1 >= 0 && !visited[row][col-1] && word[nextCharIndex] == board[row][col-1]) {
            visited[row][col-1] = true;
            success = dfs(board, word, visited, row, col - 1, nextCharIndex + 1);
            visited[row][col-1] = false;
        }
        
        return success;
    }
};
