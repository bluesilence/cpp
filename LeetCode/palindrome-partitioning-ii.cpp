class Solution {
public:
    int minCut(string s) {
        //Scan the string, find min number of palindromes at the whole page
        //Use dp[i][j] to represent the min number of palindromes at position (i, j)
        //Then dp[i][i] = 1, dp[i][j] = min (dp[i][k] + dp[k][j]), i < k < j
        //To simplify this, scan i from right to left, let n = s.size(), use dp[i] to represent dp[i][n]
        //If substring (i, j) is a palindrome, then dp[i] = min (dp[i], dp[j+1] + 1), i <= j < n
        //Define isPalindrome[i][j] == true if substring (i, j) is a palindrome
        //Then isPalindrome[i][i] == true, isPalindrome[i][j] = isPalindrome[i+1][j-1] && (s[i] == s[j])
        if (s.size() < 2)
            return 0;
        
        const int n = s.size();
        vector<int> dp(n + 1, 0);
        
        //Initialization
        for (int i = n; i >= 0; i--) {
            dp[i] = n - i;
        }
        
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        //Condition i == j can be merged. Below is the same logic as L34~50
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                //s[i...j] forms a palindrome, including the case when i == j
                if (s[i] == s[j] && (j - i < 2 || isPalindrome[i+1][j-1])) {
                    isPalindrome[i][j] = true;
                    dp[i] = min(dp[i], 1 + dp[j+1]);
                }
            }
        }
        
        /*
        for (int i = 0; i < n; i++) {
            isPalindrome[i][i] = true;
        }
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                //s[i...j] forms a palindrome
                if (s[i] == s[j] && (j - i < 2 || isPalindrome[i+1][j-1])) {
                    isPalindrome[i][j] = true;
                    dp[i] = min(dp[i], 1 + dp[j+1]);
                } else {    //s[i...j] is not a palindrome
                    dp[i] = min(dp[i], 1 + dp[i+1]);
                }
            }
        }
        */
        
        return dp[0] - 1;   //minCut == minPalindromes - 1
    }
};
