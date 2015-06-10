class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        //The matrix should be n width and n height, so the area is n^2
        vector<vector<int> > matrix;
        
        if (n < 1)
            return matrix;
        
        for (int i = 0; i < n; i++) {
            vector<int> row(n, 0);
            matrix.push_back(row);
        }
        
        int circle = (n + 1) / 2;
        int startingNum = 1;
        for (int i = 0; i < circle; i++) {
            startingNum = fillLeftToRight(matrix, i, startingNum);
            startingNum = fillTopToBottom(matrix, i, startingNum);
            startingNum = fillRightToLeft(matrix, i, startingNum);
            startingNum = fillBottomToTop(matrix, i, startingNum);
        }
        
        return matrix;
    }

private:
    int fillLeftToRight(vector<vector<int> > &matrix, int circle, int startingNum) {
        for (int col = circle; col < matrix[0].size() - circle; col++) {
            matrix[circle][col] = startingNum++;
        }
        
        return startingNum;
    }
    
    int fillTopToBottom(vector<vector<int> > &matrix, int circle, int startingNum) {
        for (int row = circle + 1; row < matrix.size() - circle; row++) {
            matrix[row][matrix[0].size() - 1 - circle] = startingNum++;
        }
        
        return startingNum;
    }
    
    int fillRightToLeft(vector<vector<int> > &matrix, int circle, int startingNum) {
        for (int col = matrix[0].size() - 2 - circle; col >= circle; col--) {
            matrix[matrix.size() - 1 - circle][col] = startingNum++;
        }
        
        return startingNum;
    }
    
    int fillBottomToTop(vector<vector<int> > &matrix, int circle, int startingNum) {
        for (int row = matrix.size() - 2 - circle; row > circle; row--) {
            matrix[row][circle] = startingNum++;
        }
        
        return startingNum;
    }
};
