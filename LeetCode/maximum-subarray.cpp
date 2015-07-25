class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int N = nums.size();
        if (N < 1)
            return 0;
        
        int globalMax = INT_MIN;
        int localMax = 0;
        
        for (int i = 0; i < N; i++) {
            if (localMax < 0) {
                localMax = nums[i];
            } else {
                localMax += nums[i];
            }
            
            globalMax = max(globalMax, localMax);
        }
        
        return globalMax;
    }
};
