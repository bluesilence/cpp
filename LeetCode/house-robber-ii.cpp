class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        if (nums.size() == 1)
            return nums[0];
            
        return max(robInRange(nums, 0, nums.size() - 2), robInRange(nums, 1, nums.size() - 1));
    }
        
private:
    int robInRange(vector<int>& nums, const int start, const int end) {
        if (start < 0 || end >= nums.size() || end < start)
            return 0;
        
        if (start == end)
            return nums[start];
            
        const int N = end - start + 1;
        vector<int> dp(N, 0);
        
        dp[0] = nums[start];
        for (int i = 1; i < N; i++) {
            if (i > 1) {
                dp[i] = max(dp[i-2] + nums[start + i], dp[i-1]);
            } else {
                dp[i] = max(dp[i-1], nums[start + i]);
            }
        }
        
        return dp[N-1];
    }
};
