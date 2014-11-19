class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        if(m < 1) return ;
        int n = matrix.front().size();
        
        //found first zero
        int row = -1 ,  col = -1;
        for(int i = 0 ; i < m ; i ++) {
            for(int j = 0 ; j < n ; j++) {
                if(matrix[i][j] == 0) {
                    row = i;
                    col = j;
                    break;
                }
            }
            
            if(row != -1) break;
        }
        
        if(row == -1) return;
        
        //row , col to record if has zero
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(matrix[i][j] == 0) {
                    matrix[row][j] = 0;
                    matrix[i][col] = 0;
                }
            }
        }
        
        //fill col
        for(int i = 0 ; i < n ; i++) {
            if(i != col && matrix[row][i] == 0) {
                //fill
                for(int j = 0 ; j < m ; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        
        //fill row
        for(int i = 0 ; i < m ; i++) {
            if(i != row && matrix[i][col] == 0) {
                //fill
                for(int j = 0 ; j < n ; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        //fill first 0 row
        for(int i = 0 ; i < n ; i++) matrix[row][i] = 0;
        
        //fill first 0 col
        for(int i = 0 ; i < m ; i++) matrix[i][col] = 0;
    }
};