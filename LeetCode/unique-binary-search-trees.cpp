class Solution {
public:
    int numTrees(int n) {
        if (n < 1)
            return 0;
        
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        
        return countUniques(dp, n);
    }
        
private:
    int countUniques(vector<int> &dp, int n) {
        if (dp[n] > -1) //Already calculated
            return dp[n];
            
        int count = 0;
        for (int i = 1; i <= n; i++) {
            count += countUniques(dp, i - 1) * countUniques(dp, n - i);
        }
        
        dp[n] = count;
        
        return count;
    }
};
