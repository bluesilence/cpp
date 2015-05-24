class Solution {
public:
    int totalNQueens(int n) {
        if (n < 1)
            return 0;
        
        vector<int> rowForQueens(n, -1);
        
        return countQueens(rowForQueens, n);
    }
    
private:
    int countQueens(vector<int> &rowForQueens, const int n, int col = 0) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (isValid(rowForQueens, col, i)) {
                rowForQueens[col] = i;
                if (col + 1 < n)
                    sum += countQueens(rowForQueens, n, col + 1);
                else
                    sum += 1;
            }
        }
        
        return sum;
    }
    
    bool isValid(vector<int> &rowForQueens, const int col, const int row) {
        for (int i = 0; i < col; i++) {
            if (row == rowForQueens[i] ||
                rowForQueens[i] - row == i - col ||
                rowForQueens[i] - row == col - i)
                return false;
        }
        
        return true;
    }
};
