class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        
        if (n <= 0)
            return results;
        
        vector<int> rowOfQueens(n, 0);
        
        findSolutions(results, rowOfQueens, n, 0);
        
        return results;
    }

private:
    void findSolutions(vector<vector<string>> &results, vector<int> &board, const int N, int index) {
        if (board.size() < N || N < 1 || index < 0 || index > N)
            return;
        
        if (index == N) {
            collectResult(results, board, N);
        } else {
            for (int i = 0; i < N; i++) {
                board[index] = i;
                if (isValid(board, N, index)) {
                    findSolutions(results, board, N, index + 1);
                }
            }
        }
    }
    
    bool isValid(vector<int> &board, const int N, int index) {
        if (board.size() < N || N < 1 || index < 0 || index >= N)
            return false;
        
        for (int i = 0; i < index; i++) {
            if (board[i] == board[index] || board[index] - board[i] == index - i || board[index] - board[i] == i - index)
                return false;
        }
        
        return true;
    }
    
    void collectResult(vector<vector<string>> &results, vector<int> &board, const int N) {
        if (board.size() < N)
            return;
        
        vector<string> result(N, string(N, '.'));
        
        for (int i = 0; i < N; i++) {
            result[board[i]][i] = 'Q';
        }
        
        results.push_back(result);
    }
};
