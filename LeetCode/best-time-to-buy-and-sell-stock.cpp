class Solution {
public:
    int maxProfit(vector<int> &prices) {
        //Find the maximum difference between 2 prices
        //The smaller price forward, the bigger price backward
        //If there is no > 0 difference, better avoid transaction and return 0 as max profit
        int profit = 0;
        if (prices.size() > 1) {
            int end = prices.size() - 1;
            vector<int> mins(prices.size(), 0);
            vector<int> maxs(prices.size(), 0);
            mins[0] = prices[0];
            maxs[end] = prices[end];
            
            for (int i = 1; i <= end; i++) {
                if (prices[i] < mins[i-1])
                    mins[i] = prices[i];
                else
                    mins[i] = mins[i-1];
            }
            
            for (int j = end - 1; j >= 0; j--) {
                if (prices[j] > maxs[j+1])
                    maxs[j] = prices[j];
                else
                    maxs[j] = maxs[j+1];
            }
            
            for (int i = 0; i <= end; i++) {
                if (maxs[i] - mins[i] > profit)
                    profit = maxs[i] - mins[i];
            }
        }
        
        return profit;
    }
};
