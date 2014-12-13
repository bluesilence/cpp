class Solution {
public:
    int minDistance(string word1, string word2) {
        //The 0th row/col is boundary
        int row = word1.length() + 1;
        int col = word2.length() + 1;
        
        vector<vector<int> > f(row, vector<int>(col));

        //Initialize boundaries
        for (int i = 0; i < row; i++)
            f[i][0] = i;

        for (int i = 0; i < col; i++)
            f[0][i] = i;

        for (int i = 1; i < row; i++)
            for (int j = 1; j < col; j++){
                if (word1[i - 1] == word2[j - 1])
                    f[i][j] = f[i - 1][j - 1];
                else    //Replace
                    f[i][j] = f[i - 1][j - 1] + 1;
                
                //Find min in Replace, Delete and Insert
                f[i][j] = min(f[i][j], min(f[i - 1][j] + 1, f[i][j - 1] + 1));
            }

        return f[row - 1][col - 1];
    }
};
