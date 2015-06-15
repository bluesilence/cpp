class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() < 2 || k < 0)
            return false;
        
        map<int, int> numIndices;
        
        for (int i = 0; i < nums.size(); i++) {
            if (numIndices.find(nums[i]) == numIndices.end()) {
                numIndices[nums[i]] = i;
            } else {
                int j = numIndices[nums[i]];
                if (i - j <= k) {
                    return true;
                } else {    //If i - j > k, the following i - j also > k, so no need to record j. Replace it with i.
                    numIndices[nums[i]] = i;
                }
            }
        }
        
        return false;
    }
};
