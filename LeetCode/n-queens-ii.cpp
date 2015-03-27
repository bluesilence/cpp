class Solution {
public:
    int totalNQueens(int n) {
        if (n < 1)
            return 0;
        
        vector<int> q(n, -1);
        
        return countQueens(q, n);
    }
    
    int countQueens(vector<int> &q, int n, int index = 0) {
        if (index == n)
            return 1;
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (isLegal(q, index, i)) { //Can put a Queen at row index, col i
                q[index] = i;
                sum += countQueens(q, n, index+1);
            }
        }
        
        return sum;
    }
    
private:
    bool isLegal(vector<int> &q, int n, int index) {
        for (int i = 0; i < n; i++)
            if (q[i] == index || q[i] - i == index - n || q[i] + i == index + n)
                return false;
        
      return true;
    }
};
