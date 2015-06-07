class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //Binary search
        int begin = 0;
        int end = nums.size() - 1;
        int mid = 0;
        
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        if (nums[mid] < target) {   //target should be inserted in the position after mid
            return mid + 1;
        } else {
            return mid; //begin == mid, end < begin, target should be inserted at begin
        }
        
        return mid;
    }
};
