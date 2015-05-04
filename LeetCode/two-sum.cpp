class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> results;
        if (nums.size() < 2)
            return results;
        
        vector<int> numsCopy = nums;
        sort(numsCopy.begin(), numsCopy.end());
        
        int i = 0, j = numsCopy.size() - 1;
        int tmpSum;
        while (i < j) {
            tmpSum = numsCopy[i] + numsCopy[j];
            if (tmpSum == target)
                break;
            else if (tmpSum < target)
                i++;
            else
                j--;
        }
        
        if (tmpSum == target) {
            for (int k = 0; k < nums.size(); k++) {
                if (nums[k] == numsCopy[i] || nums[k] == numsCopy[j])
                    results.push_back(k+1);
            }
        }
        
        return results;
    }
};
