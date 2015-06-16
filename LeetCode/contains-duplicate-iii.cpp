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
            
            //Is there any number in the set which >= nums[i] - t?
	    auto iter = latestNums.lower_bound(nums[i] - t);
	    //The iter from set is internally sorted, so just need to check the first number
	    //If this number > nums[i] + t, then there is no number that drops into [num[i]-t, nums[i]+t];
	    if (iter != latestNums.end() && *iter <= nums[i] + t) {
		return true;
	    }
            
            latestNums.insert(nums[i]);
        }
        
        return false;
    }
};
