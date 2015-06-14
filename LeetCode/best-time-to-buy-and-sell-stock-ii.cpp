class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        
        int profit = 0;
        
        int ascendingStart = 0;
        int ascendingEnd = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] > prices[ascendingEnd]) {
                ascendingEnd = i;
                if (i == prices.size() - 1) {
                    profit += prices[ascendingEnd] - prices[ascendingStart];
                }
            } else {
                profit += prices[ascendingEnd] - prices[ascendingStart];
                ascendingStart = i;
                ascendingEnd = ascendingStart;
            }
        }
        
        return profit;
    }
};
