class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        //Like binary search, use start, end and mid
        //For 2D search, use startRow, startCol, endRow, endCol, midRow and midCol
        if (matrix.empty() || matrix[0].empty())
            return false;
        
        const int height = matrix.size();
        const int width = matrix[0].size();
        
        //Determine the row
        int startRow = 0, endRow = height - 1;
        int midRow;
        while (startRow < endRow) {
            midRow = (startRow + endRow) / 2;
            if (matrix[midRow][width-1] < target)
                startRow = midRow + 1;
            else if (matrix[midRow][0] > target)
                endRow = midRow - 1;
            else
                startRow = endRow = midRow;
        }
        
        if (endRow < startRow)
            return false;
            
        //Determine the col
        int startCol = 0, endCol = width - 1;
        int midCol;
        while (startCol < endCol) {
            midCol = (startCol + endCol) / 2;
            if (matrix[startRow][midCol] < target)
                startCol = midCol + 1;
            else if (matrix[startRow][midCol] > target)
                endCol = midCol - 1;
            else
                startCol = endCol = midCol;
        }
        
        if (startCol < width && endCol >= 0 && matrix[startRow][startCol] == target)
			      return true;
		    else
			      return false;
    }
};
