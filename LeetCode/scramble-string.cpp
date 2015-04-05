class Solution {
public:
    bool isScramble(string s1, string s2) {
        //DP solution:
        //Define dp[i][j][k] means the substrings(length k) at index i in s1 and index j in s2 are 2 scrambled substrings.
        //Split s1 and s2 at every possible length
        //Loop for len <- 2 to s1.size()
        //Loop for s1Begin <- 0 to s1.size() - 1
        //Loop for s2Begin <- 0 to s2.size() - 1
        //s1End = s1Begin + len - 1, s2End = s2Begin + len - 1
        //Loop for s1Mid <- (s1Begin + 1) to s1End
        //Size of left substring is s1Mid - s1Begin
        //s2Mid = s2Begin + leftSize
        //bool leftMatchLeft = dp[s1Begin][s2Begin][leftSize] && dp[s1Mid][s2Mid][len - leftSize]
        //s2Mid = s2End - leftSize + 1
        //bool leftMatchRight = dp[s1Begin][s2Mid][leftSize] && dp[s1Mid][s2Begin][len - leftSize]
        //dp[s1Begin][s2Begin][len] = dp[s1Begin][s2Begin][len] || leftMatchLeft || leftMatchRight
        //Final result is dp[0][0][s1.size()];
        
        //This solution is recursive way:
        
        if (s1.size() != s2.size())
            return false;
        
        const int n = s1.size();
        if (0 == n || s1 == s2)
            return true;
        
        //Check if the frequencies of characters are the same
        int A[26] = {0};  
        for(int i = 0; i < n; i++)  
            ++A[s1[i] -'a'];  
  
        for(int j = 0; j < n; j++)  
            --A[s2[j] -'a'];  
  
        for(int k = 0; k < 26; k++)  
            if(A[k] != 0)
                return false;
            
        bool result = false;
        for(int len = 1 ; len < n; len++) {
            result = isScramble(s1.substr(0, len), s2.substr(0, len)) && isScramble(s1.substr(len), s2.substr(len));
            if(result)
                return true;
                
            result = isScramble(s1.substr(0, len), s2.substr(n-len, len)) && isScramble(s1.substr(len), s2.substr(0, n-len));
            if(result)
                return true;
        }
        
        return false;
    }
};
