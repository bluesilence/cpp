class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Since there can be 2 transactions, define 2 vectors leftProfits & rightProfits
        //leftProfits[i]: the maxProfit of 1 transaction made before day i(inclusive)
        //rightProfits[i]: the maxProfit of 1 transaction made after day i(inclusive)
        //At day i, we can sell stock then buy again
        const int N = prices.size();
        if (N < 2)
            return 0;
        
        vector<int> leftProfits(N, 0);
        vector<int> rightProfits(N, 0);
        
        int minPrice = prices[0];
        
        for (int i = 1; i < N; i++) {
            leftProfits[i] = max(leftProfits[i-1], prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        
        int maxPrice = prices[N-1];
        
        for (int i = N-2; i >= 0; i--) {
            rightProfits[i] = max(rightProfits[i+1], maxPrice - prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }
        
        int profit = 0;
        for (int i = 0; i < N; i++) {
            int tmpProfit = rightProfits[i] + leftProfits[i];
            profit = max(tmpProfit, profit);
        }
        
        return profit;
    }
};
