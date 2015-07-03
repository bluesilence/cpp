class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty())
            return 0;
        
        const int N = ratings.size();
        
        vector<int> candies(N, 1);
        
        //Give more candies to children rating higher than their left neighbor
        for (int i = 1; i < N; i++) {
            if (ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        }
        
        //Give more candies to children rating higher than their right neighbor, subject to candies assigned based on their left neighbor
        for (int i = N-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1])
                candies[i] = max(candies[i], candies[i+1] + 1);
        }
        
        int result = 0;
        for (int i = 0; i < N; i++) {
            result += candies[i];
        }
        
        return result;
    }
};
