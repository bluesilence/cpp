class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        
        int startRow = 0, endRow = matrix.size() - 1;
        int startCol = 0, endCol = matrix[0].size() - 1;
        int midRow;
        int midCol;
        
        while (startRow < endRow) {
            midRow = (startRow + endRow) / 2;
            if (matrix[midRow][startCol] > target) {
                endRow = midRow - 1;
            } else if (matrix[midRow][endCol] < target) {
                startRow = midRow + 1;
            } else {
                startRow = midRow;  //Found target row
                break;
            }
        }
        
        while (startCol < endCol) {
            midCol = (startCol + endCol) / 2;
            if (matrix[startRow][midCol] > target) {
                endCol = midCol - 1;
            } else if (matrix[startRow][midCol] < target) {
                startCol = midCol + 1;
            } else {
                startCol = midCol;  //Found target col
                break;
            }
        }
        
        if (matrix[startRow][startCol] == target)
            return true;
        else
            return false;
    }
};
