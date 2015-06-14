class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Define 2 vectors, 1 for the lowest price before day i, 1 for the highest price after day i
        //The max profit is max(highest[i] - lowest[i])
        const int N = prices.size();
        
        if (N < 2)  //You cannot buy and sell at the same day
            return 0;
            
        vector<int> lowestPrices(N, 0);
        vector<int> highestPrices(N, 0);
        
        lowestPrices[0] = prices[0];
        highestPrices[N-1] = prices[N-1];
        
        for (int i = 1; i < N; i++) {
            lowestPrices[i] = min(lowestPrices[i-1], prices[i]);
        }
        
        for (int i = N-2; i >= 0; i--) {
            highestPrices[i] = max(highestPrices[i+1], prices[i]);
        }
        
        int maxProfit = 0;
        
        for (int i = 0; i < N; i++) {
            maxProfit = max(maxProfit, highestPrices[i] - lowestPrices[i]);
        }
        
        return maxProfit;
    }
};
