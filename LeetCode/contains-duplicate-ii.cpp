class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() < 2 || k < 0)
            return false;
        
        //Record the latest (k+1) numbers
        unordered_set<int> kNums;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                kNums.erase(nums[i - k - 1]);
            }
            
            if (kNums.find(nums[i]) != kNums.end()) {
                return true;
            }
            
            kNums.insert(nums[i]);
        }
        
        return false;
    }
};
