class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() < 2)
            return false;
        
        vector<int> ordered = nums;
        sort(ordered.begin(), ordered.end());
        
        int pre = ordered[0];
        
        for (int i = 1; i < ordered.size(); i++) {
            if (ordered[i] == pre) {
                return true;
            } else {
                pre = ordered[i];
            }
        }
        
        return false;
    }
};
