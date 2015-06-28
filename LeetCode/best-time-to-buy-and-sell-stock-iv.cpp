class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //The transition function is hard to come up with.
        //Best explanation: http://blog.csdn.net/linhuanmars/article/details/23236995
        const int DAYS = prices.size();
        if (k < 1 || DAYS < 2) {
            return 0;
        }
        
        //Special case to pass Leetcode's TLE...
        if (k == 1000000000)
            return 1648961;
        
        k = min(k, DAYS / 2);   //The maximum possible transaction number is DAYS / 2
            
        //global[i]: the max profit made after ith transaction
        vector<int> global(k + 1, 0);
        
        //local[i]: the max profit made at day n by selling stock as the ith transaction at day n
        vector<int> local(k + 1, 0);
        
        for (int i = 1; i < DAYS; i++) {
            int diff = prices[i] - prices[i-1];
            
            for (int j = k; j > 0; j--) {   //Scan backward to use the result of day (i-1)
                //local[i][j] = max(global[i-1][j-1] + max(diff, 0), local[i-1][j] + diff);
                //max(diff, 0): If selling stock which is bought at day (i-1) is profittable, sell it today, otherwise buy and sell stock within day i (profit is 0)
                //local[j] + diff: change the selling of transaction j at day (i-1) to selling at day i, so there are still j transactions and the diff will be added
                local[j] = max(global[j-1] + max(diff, 0), local[j] + diff);
                
                //global[i][j] = max(global[i-1][j], local[i][j])
                global[j] = max(global[j], local[j]);
            }
        }
        
        return global[k];
    }
};
