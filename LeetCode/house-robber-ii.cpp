class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        const int N = nums.size();
        vector<int> dp(N, 0);
        
        int maxMoney = 0;
        for (int i = 0; i < N; i++) {
            fill(dp.begin(), dp.end(), 0);
            dp[0] = nums[i];    //Rob from house i
            
            for (int j = i + 1; j < i + N; j++) {
                int dpIndex = (j - i) % N;
				        int houseIndex = j % N;
                
                if (dpIndex == N - 1) {  //Cannot rob last house since the first house has already been robbed and the two are neighbours
                    dp[dpIndex] = dp[dpIndex-1];
                } else {
                    if (dpIndex >= 2) {
                        dp[dpIndex] = max(dp[dpIndex-2] + nums[houseIndex], dp[dpIndex-1]);
                    } else {
                        dp[dpIndex] = max(nums[houseIndex], dp[dpIndex-1]);
                    }
                }
            }
            
            if (dp[N-1] > maxMoney) {
                maxMoney = dp[N-1];
            }
        }
        
        return maxMoney;
    }
};
