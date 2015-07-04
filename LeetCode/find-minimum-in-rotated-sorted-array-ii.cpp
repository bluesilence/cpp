class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        int mid;
        
        while (begin < end) {
            //The subsequence is already sorted
            if (nums[begin] < nums[end])    //Necessary; otherwise when nums[begin] == nums[mid], L23 will skip the minimum number
                return nums[begin];
                
            mid = (begin + end) / 2;
            
            if (nums[mid] > nums[begin]) {
                begin = mid + 1;
            } else if (nums[mid] < nums[end]) {
                end = mid;
            } else {
                begin++;
            }
        }
        
        return nums[begin];
    }
};
