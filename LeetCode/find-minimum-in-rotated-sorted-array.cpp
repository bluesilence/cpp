class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            throw "EmptyArray";
        
        int begin = 0;
        int end = nums.size() - 1;
        int mid = 0;
        
        while (begin < end) {   //NO "=" here, otherwise the loop cannot terminate because of L16
            mid = (begin + end) / 2;
            if (nums[mid] >= nums[begin] && nums[mid] > nums[end]) {  //mid falls in the left (greater) half; need to move right
                begin = mid + 1;    //"+ 1" here, since minimum cannot be in the left half
            } else {    //mid falls in the right (less) half; need to move left
                end = mid;  //NO "- 1" here, since mid is within the less half and the minimal number should be included in the range
            }
        }
        
        //Return begin/end both works, while mid doens't work, the reason is that mid is not updated after L12
        return nums[begin];
    }
};
