class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        int mid;
        
        while (begin <= end) {
            mid = (begin + end) / 2;
            bool greaterThanLeft = (mid == 0) || (mid > 0 && nums[mid] > nums[mid-1]);
            bool greaterThanRight = (mid + 1 == nums.size()) || (mid + 1 < nums.size() && nums[mid] > nums[mid+1]);
            
            if (greaterThanLeft && greaterThanRight)
                return mid;
            else if (greaterThanLeft)
                begin = mid + 1;
            else
                end = mid - 1;
        }
        
        return mid;
    }
};
