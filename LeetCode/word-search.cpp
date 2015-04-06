class Solution {
public:
    //Use DFS
    bool exist(vector<vector<char> > &board, string word) {
        if (word.size() == 0)
            return false;
        
        const int width = board.size();
        const int height = board[0].size();
        
        const char firstChar = word[0];
        vector<vector<bool> > visited(width, vector<bool>(height, false));
        
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (board[i][j] == firstChar) {
                    visited[i][j] = true;
                    if (word.size() == 1 || dfs(board, word, visited, i, j, 1))
                        return true;
                    visited[i][j] = false;
                }
            }
        }
        
        return false;
    }

private:
    bool dfs(vector<vector<char> > &board, string word, vector<vector<bool> > &visited, int i, int j, int index) {
        if (index == word.size())
            return true;
        
        bool result = false;
        //Move up
        if (i > 0 && !visited[i-1][j] && board[i-1][j] == word[index]) {
            visited[i-1][j] = true;
            result = dfs(board, word, visited, i-1, j, index+1);
            visited[i-1][j] = false;
        }
        
        //Move left
        if (!result && j > 0 && !visited[i][j-1] && board[i][j-1] == word[index]) {
            visited[i][j-1] = true;
            result = dfs(board, word, visited, i, j-1, index+1);
            visited[i][j-1] = false;
        }
        
        //Move down
        if (!result && i+1 < board.size() && !visited[i+1][j] && board[i+1][j] == word[index]) {
            visited[i+1][j] = true;
            result = dfs(board, word, visited, i+1, j, index+1);
			      visited[i+1][j] = false;
        }
        
        //Move right
        if (!result && j+1 < board[0].size() && !visited[i][j+1] && board[i][j+1] == word[index]) {
            visited[i][j+1] = true;
            result = dfs(board, word, visited, i, j+1, index+1);
			      visited[i][j+1] = false;
        }
        
        return result;
    }
};
