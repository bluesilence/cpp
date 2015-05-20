class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() < 1)
            return -1;
            
        int start = 0, end = nums.size() - 1;
        int mid;
        
        //First determine an ordered sub array using mid, start and end, then check where target is located.
        while (start <= end) {
            mid = (start + end) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (nums[start] <= nums[mid]) {  //mid is in the left part
                if (target >= nums[start] && target < nums[mid]) {  //target is in [start, mid)
                    end = mid - 1;
                } else {    //target is in (mid, end]
                    start = mid + 1;
                }
            } else {    //mid is in the right part
                if (target > nums[mid] && target <= nums[end]) {   //target is in (mid, end]
                    start = mid + 1;
                } else {    //target is in [start, mid)
                    end = mid - 1;
                }
            }
        }
        
        return -1;
    }
};
