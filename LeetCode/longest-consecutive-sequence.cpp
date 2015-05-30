class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int maxLen = 1;
        int tmpLen = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                continue;   //Skip duplicate elements
            } else if (abs(nums[i] - nums[i-1]) == 1) {
                tmpLen++;
                if (tmpLen > maxLen)
                    maxLen = tmpLen;
            } else {
                tmpLen = 1;
            }
        }
        
        return maxLen;
    }
};
