class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty())
            return 0;

        int max = 0;
        int start = prices[0];
        int last = prices[0];
        int n = prices.size();
        for(int i = 1; i < n; i++) {
            //Sum profits in each ascending profit range
            if(prices[i] >= last) {
                last = prices[i];
                if(i == n - 1)  // end
                    max += (last - start);
            } else {
                max += (last - start);
                start = prices[i];
                last = prices[i];
            }
        }
        
        return max;
    }
};
