class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
            
        const int M = matrix.size();
        const int N = matrix[0].size();
        
        //dp[i][j]: the maximal length of side of square with the bottom-right corner sitting at matrix[i][j]
        //Add column 0 so that the (col-1) in L24 >= 0
        vector<vector<int>> dp = vector<vector<int>>(2, vector<int>(N + 1, 0));
        dp[0][0] = 0;
        
        int maxLen = 0;
        
        for (int row = 0; row < M; row++) {
            int dpRow = row & 0x01; //0 or 1
            
            for (int col = 1; col <= N; col++) {
                if (matrix[row][col-1] == '1') {
                    dp[dpRow][col] = min(dp[1-dpRow][col-1], min(dp[dpRow][col-1], dp[1-dpRow][col])) + 1;
                    maxLen = max(maxLen, dp[dpRow][col]);
                } else {
                    dp[dpRow][col] = 0;
                }
            }
        }
        
        return maxLen * maxLen;
    }
};
