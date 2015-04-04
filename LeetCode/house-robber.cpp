class Solution {
public:
    int rob(vector<int> &num) {
        int n = num.size();
        if (0 == n)
            return 0;
        
        if (1 == n)
            return num[0];
            
        //dp_robbed[i]: the max profit when coming to house[i] and house[i] is not robbed
        vector<int> dp_robbed(n, 0);
        //dp_notRobbed[i]: the max profit when coming to house[i] and house[i] is robbed
        vector<int> dp_notRobbed(n, 0);
        
        dp_robbed[0] = num[0];
        dp_robbed[1] = num[1];
        dp_notRobbed[1] = dp_robbed[0];
        
        for (int i = 2; i < n; i++) {
            dp_robbed[i] = max(dp_robbed[i-2], dp_notRobbed[i-1]) + num[i];
            dp_notRobbed[i] = max(dp_notRobbed[i-1], dp_robbed[i-1]);
        }
        
        return max(dp_robbed[n-1], dp_notRobbed[n-1]);
    }
};
