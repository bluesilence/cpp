class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        const int M = matrix.size();
        const int N = matrix[0].size();
        
        //Start from top-right corner
        int row = 0;
        int col = N - 1;
        
        while (row < M && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) { //The min of the column > target, so the entire column > target
                col--;
            } else {    //The max of the row < target, so the entire row < target
                row++;
            }
        }
        
        return false;
    }
};
