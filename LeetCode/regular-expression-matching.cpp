class Solution {
public:
    bool isMatch(string s, string p) {
        const int SLEN = s.size();
        const int PLEN = p.size();
        
        //dp[i][j] stands for whether s[0...i-1] matches p[0...j-1]
        vector<vector<bool>> dp(SLEN + 1, vector<bool>(PLEN + 1, false));
        
        dp[0][0] = true;
        
        for (int i = 0; i <= SLEN; i++) {
            for (int j = 1; j <= PLEN; j++) {
                if (p[j-1] != '*') {
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (p[j-1] == '.' || s[i-1] == p[j-1]);
                } else {    //Assume the pattern is always valid so there is at least 1 char before '*', i.e. j >= 2
                    dp[i][j] = dp[i][j-2] || (i > 0 && dp[i-1][j] && (p[j-2] == '.' || s[i-1] == p[j-2]));
                }
            }
        }
        
        return dp[SLEN][PLEN];
    }
};
