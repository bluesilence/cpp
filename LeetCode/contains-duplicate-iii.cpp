class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2)
            return false;
        
        if (k < 0 || t < 0)
            return false;
            
		return containsNearbyAlmostDuplicateCore(nums, (long long)k, (long long)t);
	}

private:
	bool containsNearbyAlmostDuplicateCore(vector<int>& nums, long long k, long long t) {
        //Record the latest (k+1) numbers
        set<int> latestNums;
        latestNums.insert(nums[0]);
        
        for (int i = 1; i < nums.size(); i++) {
            if (i > k) {
                latestNums.erase(nums[i - k - 1]);
            }
            
			      if (k <= 2 * t) { //If t is int, 2 * t may overflow, so convert it to long long
				      for (auto iter = latestNums.begin(); iter != latestNums.end(); iter++) {
                    if (abs((long long)*iter - nums[i]) <= t) {
                        return true;
                    }
                }
            } else {
                for (int j = 0; j <= t; j++) {
                    if (latestNums.find(nums[i] + j) != latestNums.end() || latestNums.find(nums[i] - j) != latestNums.end()) {
                        return true;
                    }
                }
            }
            
            latestNums.insert(nums[i]);
        }
        
        return false;
    }
};
