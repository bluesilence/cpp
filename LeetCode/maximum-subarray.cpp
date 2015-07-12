class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int N = nums.size();
        if (N < 1)
            return 0;
            
        int globalMax = nums[0];
        int localMax = max(nums[0], 0);
        for (int i = 1; i < N; i++) {
            localMax += nums[i];    //Make sure when all nums are negative, globalMax won't be assigned to be 0
            globalMax = max(globalMax, localMax);
            localMax = max(localMax, 0);
        }
        
        return globalMax;
    }
};
