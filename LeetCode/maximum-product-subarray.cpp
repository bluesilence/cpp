class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();
        
        if (N == 0)
            return 0;
        
        long long maxLocal = nums[0];
        long long minLocal = nums[0];
        long long maxGlobal = nums[0];
        
        for (int i = 1; i < N; i++) {
            long long previousMaxLocal = maxLocal;
            
            maxLocal = max(max(nums[i] * maxLocal, (long long)nums[i]), nums[i] * minLocal);
            minLocal = min(min(nums[i] * minLocal, (long long)nums[i]), nums[i] * previousMaxLocal);
            
            maxGlobal = max(maxGlobal, maxLocal);
        }
        
        return maxGlobal;
    }
};
