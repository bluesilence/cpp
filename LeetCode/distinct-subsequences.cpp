class Solution {
public:
    int numDistinct(string s, string t) {
        //DP. Define a matrix dp[i][j] to store the count of possible ways that t[0...j-1] is a subsequence of s[0...i-1]
        //dp[i][j] = dp[i-1][j] + (s[i-1] == t[j-1] ? dp[i-1][j-1] : 0)
        const int M = s.size();
        const int N = t.size();
        
        if (M < N)
            return 0;
        
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        
        //Empty string is a subsequence of s[0...i-1]
        for (int i = 0; i <= M; i++) {
            dp[i][0] = 1;
        }
        
        for (int j = 1; j <= N; j++) {
            for (int i = 1; i <= M; i++) {
                dp[i][j] = dp[i-1][j] + (s[i-1] == t[j-1] ? dp[i-1][j-1] : 0);
            }
        }
        
        return dp[M][N];
    }
};
