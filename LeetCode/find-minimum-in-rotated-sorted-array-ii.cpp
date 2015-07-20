class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            throw "Input is empty";
        
        if (nums.size() == 1)
            return nums[0];
            
        int begin = 0;
        int end = nums.size() - 1;
        int mid = 0;
        
        while (begin < end) {
            if (nums[begin] < nums[end]) {  //Already sorted. Coverred cases when nums[mid] == nums[end] && nums[mid] > nums[begin]
                return nums[begin];
            }
            
            mid = begin + (end - begin) / 2;    //(begin + end) may overflow
            
            if (nums[mid] == nums[begin] && nums[mid] == nums[end]) {   //No clue which part is sorted, move 1 step forward
                begin++;
            } else if (nums[mid] == nums[begin] && nums[mid] > nums[end] || nums[mid] > nums[begin]) { //Left part is sorted
                begin = mid + 1;    //mid must be in the left part, while the min must exist in the right part
            } else if (nums[mid] == nums[end] && nums[mid] < nums[begin] || nums[mid] < nums[end]) {    //Right part is sorted
                end = mid;  //min must exist before or equal to mid
            }
        }
        
        return nums[begin];
    }
};
