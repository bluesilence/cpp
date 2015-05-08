class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        
        int start = 0;
        int end = length - 1;
        
        while (start <= end) {
            while (end >= start && nums[end] == val)
                end--;
            
            if (end >= start) {
                //The '=' is necessary for case: ([2], 3)
                while (start <= end && nums[start] != val)
                    start++;
                    
                if (start < end && nums[start] == val) {
                    nums[start] = nums[end];
                    end--;
                    start++;
                }
            }
        }
        
        return ++end;
    }
};
