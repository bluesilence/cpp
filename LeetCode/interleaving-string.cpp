class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        //DP. define f[i][j]: if s3(0, i+j-1) interleaved by s1(0, i-1) and s2(0, j-1)?  
        //(1)then the transform equation is below:   
        //if s1[i] == s3[i+j], f[i][j] = f[i][j] || f[i-1][j]  
        //if s2[j] == s3[i+j], f[i][j] = f[i][j] || f[i][j-1]  
        //(2)Initialize as below :  
        //f[0][0] = true,  
        //f[i][0] = f[i-1][0] && (s1[i-1] == s3[i-1]);  
        //f[0][j] = f[0][j-1] && (s2[j-1] == s3[j-1]);
        
        const int m = s1.size();
        const int n = s2.size();
        const int k = s3.size();
        
        if (m + n != k)
            return false;
        
        if (k == 0)
            return true;
        
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        dp[0][0] = true;
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i-1][0] && s3[i-1] == s1[i-1];
        }
        
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j-1] && s3[j-1] == s2[j-1];
        }
        
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i > 0 && s1[i-1] == s3[i+j-1]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j];  //Note: index of s starts from 0, while index of dp starts from 1
                }
                
                if (j > 0 && s2[j-1] == s3[i+j-1]) {
                    dp[i][j] = dp[i][j] || dp[i][j-1];
                }
            }
        }
        
        return dp[m][n];
    }
};
