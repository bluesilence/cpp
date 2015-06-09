class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachableIndex = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            maxReachableIndex = max(maxReachableIndex, i + nums[i]);
            
            if (maxReachableIndex >= nums.size() - 1) {
                return true;
            } else if (maxReachableIndex <= i) {
                return false;
            }
        }
        
        return false;
    }
};
