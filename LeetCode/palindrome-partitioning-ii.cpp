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
    int n = s.size();
      
    //The extra element dp[n] is to set a min boundary 0
		int* dp = new int[n + 1];
		
		//Each single character is a palindrome
		for(int i = n; i >= 0; i--)
			dp[i] = n - i;
			
		bool** isPalindrome = new bool*[n];
		
		for(int i = 0; i < n; i++)
		{
			isPalindrome[i] = new bool[n];
			memset(isPalindrome[i], false, sizeof(bool) * n);
		}
		
		for(int i = n-1; i >= 0; i--)
		{
		    for(int j = i; j < n; j++)
			{
				if(s[i] == s[j] && (j - i < 2 || isPalindrome[i+1][j-1]))
				{
					isPalindrome[i][j] = true;
					dp[i] = min(dp[i], dp[j+1] + 1);
				}
			}
		}
		
		int result = dp[0] - 1;
		
		delete dp;
		
		for(int i = 0; i < n; i++)
		{
		    delete isPalindrome[i];
		}
		
		delete isPalindrome;
		
		return result;
  }
};
