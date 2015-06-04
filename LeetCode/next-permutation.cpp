class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2)
            return;
        
        //Find the lowest digit i which is smaller than the lower digit j adjacent to it
        //This means the digits after j are in descending order, so that nums[j...nums.size()-1] forms the largest permutation
        int i;
        for (i = nums.size() - 2; i >= 0 && nums[i] >= nums[i+1]; i--);
        
        if (i < 0) {    //No possible arrangement, nums are already in the largest permutation
            reverse(nums, 0, nums.size() - 1);
        } else {
            //Find the lowest digit k where nums[k] > nums[i]
            //so that (nums[k], nums[j], ... , num[i], ..., nums[nums.size()-1]) is larger than (nums[i], nums[j], ..., nums[k], ..., nums[nums.size()-1])
            //since the original (nums[j], ..., nums[k], ..., nums[nums.size()-1]) is in descending order
            //after swap nums[i] and nums[j], (nums[nums.size()-1], ..., nums[i], ... nums[j]) is the smallest permutation after nums[k].
            int k;
            for (k = nums.size() - 1; k > i && nums[k] <= nums[i]; k--);
            
            swap(nums, i, k);
            
            reverse(nums, i + 1, nums.size() - 1);
        }
    }

private:
    void swap(vector<int> &nums, int index1, int index2) {
        if (index1 < 0 || index2 < 0 || index1 >= nums.size() || index2 >= nums.size())
            return;
            
        int tmp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = tmp;
    }
    
    void reverse(vector<int> &nums, int begin, int end) {
        if (begin < 0 || end >= nums.size() || begin >= end)
            return;
        
        while (begin < end) {
            swap(nums, begin, end);
            begin++;
            end--;
        }
    }
};
