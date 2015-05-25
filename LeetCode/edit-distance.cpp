class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() > word2.size())    //Keep word1 the shorter one can avoid duplicate code
            return minDistance(word2, word1);
            
        if (word1.empty())
            return word2.size();
        
        const int m = word1.size() + 1;
        const int n = word2.size() + 1;
        
        //dp[i][j] stands for the min Distance between word1[0...i-1] and word2[0...j-1]
        vector<vector<int> > dp(m, vector<int>(n, 0));
        
        for (int i = 0; i < am; i++) {
            dp[i][0] = i;
        }
        
        for (int j = 0; j < n; j++) {
            dp[0][j] = j;
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (word1[i-1] == word2[j-1]) { //Caution! The index of dp starts from 1, while the index of string starts from 0
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};
