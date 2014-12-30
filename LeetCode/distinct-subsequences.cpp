class Solution {
public:
    int numDistinct(string S, string T) {
        if (S.empty() || T.empty())
            return 0;
        
        //DP matrix
        vector<vector<int>> matrix(T.size() + 1, vector<int>(S.size() + 1, 0));
        
        //Every character in S has an opportunity of becoming the start of the subsequence
        for (int j = 0; j <= S.size(); j++) {
            matrix[0][j] = 1;
        }
        
        for (int i = 1; i <= T.size(); i++) {
            for (int j = 1; j <= S.size(); j++) {
                if (S[j - 1] == T[i - 1])
                    matrix[i][j] = matrix[i - 1][j - 1] + matrix[i][j - 1]; //Use S[j - 1] to match T[i - 1], or not use S[j - 1]
                else
                    matrix[i][j] = matrix[i][j - 1];//Cannot use S[j - 1] to match T[i - 1]
            }
        }
            
        return matrix[T.size()][S.size()];
    }
};
