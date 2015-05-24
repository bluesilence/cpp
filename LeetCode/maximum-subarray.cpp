class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int globalMax = 0;
        int tempMax = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            tempMax += nums[i];
            
            if (tempMax < 0) {
                tempMax = 0;
            } else if (tempMax > globalMax) {
                globalMax = tempMax;
            }
        }
        
        if (globalMax == 0) {   //All the elements are negative
            globalMax = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] > globalMax)
                    globalMax = nums[i];
            }
        }
        
        return globalMax;
    }
};
