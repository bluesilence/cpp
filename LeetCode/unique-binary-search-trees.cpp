class Solution {
public:
    int numTrees(int n) {
        int *dp = new int[n + 1];
        
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            dp[i] = -1;
        }
        
        int count = calcNum(dp, n);
        
        delete dp;
        
        return count;
    }
    
private:
    int calcNum(int *dp, int num) {
        if (dp[num] >= 0)   //Already calculated
            return dp[num];
        
        int count = 0;
        //The unique tree count related to one node depends on the product of counts of its all possible left and right subtrees
        for (int i = 0; i < num; i++) {
            count += calcNum(dp, i) * calcNum(dp, num - i - 1);
        }
        
        dp[num] = count;
        
        return count;
    }
};
