class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
    
        const int N = nums.size();
        
        int minLen = numeric_limits<int>::max();
        int sum = nums[0];
        int slow = 0;
        int fast = 0;
        
        while (fast < N) {
            if (sum >= s) {
                int tmpLen = fast - slow + 1;
                if (tmpLen < minLen) {
                    minLen = tmpLen;
                }
                
                sum -= nums[slow];
                slow++;
            } else {
                fast++;
                sum += nums[fast];
            }
        }
        
        if (minLen == numeric_limits<int>::max()) {
            minLen = 0;
        }
        
        return minLen;
    }
};
