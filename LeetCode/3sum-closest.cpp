class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3)
            throw "Size of nums must be >= 3.";
        
        int minDiff = numeric_limits<int>::max();
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i + 2 < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            
            target -= nums[i];
            
            while (j < k) {
                int sum = nums[j] + nums[k];
                int diff = target - sum;
                
                if (abs(diff) < abs(minDiff)) {
                    minDiff = diff;
                }
                
                if (diff > 0) {
                    j++;
                } else if (diff < 0) {
                    k--;
                } else {    //Get global minimum
                    return nums[i] + target;
                }
            }
            
            target += nums[i];
        }
        
        return target - minDiff;
    }
};
