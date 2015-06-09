class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        
        if (matrix.size() != matrix[0].size())
            throw "The height and width of the matrix must be the same.";
        
        const int n = matrix.size();
        
        const int round = n / 2;
        
        for (int i = 0; i < round; i++) {
            int begin = i;
            int end = n - 1 - i;
            
            for (int j = begin; j < end; j++) {
                int topLeft = matrix[i][j];
                int topRight = matrix[j][end];
                int bottomRight = matrix[end][n-1-j];
                int bottomLeft = matrix[n-1-j][begin];
                
                matrix[j][end] = topLeft;
                matrix[end][n-1-j] = topRight;
                matrix[n-1-j][begin] = bottomRight;
                matrix[i][j] = bottomLeft;
            }
        }
    }
};
