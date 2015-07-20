class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int M = matrix.size();
        
        if (M == 0)
            return;
        
        const int N = matrix[0].size();
        
        if (N == 0)
            return;
        
        bool firstRowHas0 = false;
        bool firstColHas0 = false;
        
        //Since the first row and first col will be used to store the indices of non-first rows/cols that have 0
        //We need to check whether they have 0s originally and set them to all 0s if true
        for (int i = 0; i < N; i++) {
            if (matrix[0][i] == 0) {
                firstRowHas0 = true;
                break;
            }
        }
        
        for (int i = 0; i < M; i++) {
            if (matrix[i][0] == 0) {
                firstColHas0 = true;
                break;
            }
        }
        
        //Start from second row/col
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                //This works because whateaver matrix[i][0] and matrix[0][j] are, they'll be set to 0s since matrix[i][j] is 0
                if (matrix[i][j] == 0) {    
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        //Start from second row since the first row is where the zero col indices are stored
        for (int i = 1; i < M; i++) {
            if (matrix[i][0] == 0) {
                clearRow(matrix, i);
            }
        }
        
        //Start from second col since the first col is where the zero row indices are stored
        for (int i = 1; i < N; i++) {
            if (matrix[0][i] == 0) {
                clearCol(matrix, i);
            }
        }
        
        if (firstRowHas0) {
            clearRow(matrix, 0);
        }
        
        if (firstColHas0) {
            clearCol(matrix, 0);
        }
    }

private:
    void clearRow(vector<vector<int>>& matrix, int row) {
        if (matrix.size() <= row || row < 0 || matrix[0].size() == 0)
            return;
        
        const int N = matrix[0].size();
        for (int i = 0; i < N; i++) {
            matrix[row][i] = 0;
        }
    }
    
    void clearCol(vector<vector<int>>& matrix, int col) {
        if (matrix.size() == 0 || col < 0 || matrix[0].size() <= col)
            return;
        
        const int M = matrix.size();
        for (int i = 0; i < M; i++) {
            matrix[i][col] = 0;
        }
    }
};
