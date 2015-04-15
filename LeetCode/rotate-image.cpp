class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        const int n = matrix.size();
        for (int i = 0; i < n/2; i++) { //Rotate from outer circle to inner circle
            for (int j = i; j < n-1-i; j++) {   //Replace 4 elements of 4 directions at one time
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }
    }
};
