class Solution {
public:
    int totalNQueens(int n) {
        if (n < 1)
            return 0;
        
        vector<int> oneSolution(n, -1);
        
        //Initialize each row, queen id starts from 0
        for (int i = 0; i < n; i++) {
            oneSolution[i] = i;
        }
        
        int totalCount = 0;
        
        permute(oneSolution, n, 0, totalCount);
        
        return totalCount;
    }
    
private:
    void permute(vector<int> &oneSolution, int n, int index, int &totalCount) {
        if (index >= n) {
            if (isValid(oneSolution, n))
                totalCount++;
                
            return;
        }
        
        for (int i = index; i < n; i++) {
            swap(oneSolution, i, index);
            permute(oneSolution, n, index + 1, totalCount);
            swap(oneSolution, i, index);
        }
    }
    
    bool isValid(vector<int> &solution, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {   //Check diagonal
                if (j - i == solution[j] - solution[i] || i - j == solution[j] - solution[i])
                    return false;
            }
        }
        
        return true;
    }
    
    void swap(vector<int> &solution, int col1, int col2) {
        if (col2 == col1 || col1 < 0 || col2 < 0 || col1 >= solution.size() || col2 >= solution.size())
            return;
            
        char tmp = solution[col1];
        solution[col1] = solution[col2];
        solution[col2] = tmp;
    }
};
