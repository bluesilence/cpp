class Solution {
public:
    int candy(vector<int> &ratings) {
        //Similar to trap water question
        //First, give each child 1 candy
        //Second, scan the children line
        //If a child has higher rating value than at least one of the neighbors, give the child one more candy.
        if (ratings.empty())
            return 0;
        
        int n = ratings.size();
        vector<int> candies(ratings.size(), 1);
        
        //Scan left to right, ensure that every child with higher rating than left has more candies than the left neighbor
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1])
                candies[i] = max(candies[i], candies[i - 1] + 1);
        }
        
        //Scan right to left, ensure that every child with higher rating than right has more candies than the right neighbor
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i], candies[i + 1] + 1);
        }
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += candies[i];
        }
        
        return result;
    }
};
