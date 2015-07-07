class Solution {
public:
    int totalNQueens(int n) {
        if (n <= 0)
            return 0;
        
        vector<int> rowOfQueens(n, 0);
        
        return countSolutions(rowOfQueens, n, n - 1);
    }
    
private:
    int countSolutions(vector<int> &board, const int n, int index) {
        long long count = 0;
        
        for (int i = 0; i < n; i++) {
            board[index] = i;
            if (isValid(board, n, index)) {
                if (index > 0) {
                    count += countSolutions(board, n, index - 1);
                } else {
                    count += 1;
                }
            }
        }
        
        return count > INT_MAX ? INT_MAX : count;
    }
    
    bool isValid(vector<int> &board, const int n, int index) {
        if (board.size() < n || index < 0 || index >= n)
            return false;
        
        for (int i = index + 1; i < n; i++) {
            if (board[i] == board[index]
                || board[index] - board[i] == index - i
                || board[index] - board[i] == i - index)
                return false;
        }
        
        return true;
    }
};
