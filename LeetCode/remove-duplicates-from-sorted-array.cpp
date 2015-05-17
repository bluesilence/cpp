class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        
        int pSlow = 0;
        int pFast = 1;
        while (pFast < nums.size()) {
            if (nums[pFast] != nums[pSlow]) {
                nums[++pSlow] = nums[pFast];
            }
            
            pFast++;
        }
        
        return ++pSlow;
    }
};
