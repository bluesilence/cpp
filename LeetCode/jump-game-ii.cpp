class Solution {
public:
    int jump(vector<int>& nums) {
        int currentReachablePosition = 0;
        int currentMaxReachablePosition = 0;
        int minJumps = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (currentReachablePosition < i && currentMaxReachablePosition >= i) {
                minJumps++;
                currentReachablePosition = currentMaxReachablePosition;
            }
            
            currentMaxReachablePosition = max(currentMaxReachablePosition, nums[i] + i);
        }
        
        return minJumps;
    }
};
