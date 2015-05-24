class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //Similar to quick sort, search for a partition then recursively call with a smaller k
        int ascendingK = nums.size() - k;   //ascendingK starts from 0
        return findKthSmallest(nums, 0, nums.size() - 1, ascendingK);
    }

private:
    int findKthSmallest(vector<int> &nums, int begin, int end, int k) {
        int partition = getPartition(nums, begin, end);
        if (k == partition - begin)
            return nums[partition];
        else if (k < partition - begin)
            return findKthSmallest(nums, begin, partition - 1, k);
        else
            return findKthSmallest(nums, partition + 1, end, k - (partition - begin + 1));
    }
    
    int getPartition(vector<int> &nums, int begin, int end) {
        if (begin < 0)
            throw "Begin must be >= 0";
        else if (end >= nums.size())
            throw "End must be <= nums.size()";
        
        while (begin < end) {
            while (begin < end && nums[begin] <= nums[end])
                begin++;
            
            if (begin < end) {
                swap(nums, begin, end);
                end--;
            }
            
            while (end > begin && nums[end] >= nums[begin])
                end--;
            
            if (end > begin) {
                swap(nums, begin, end);
                begin++;
            }
        }
        
        return begin;
    }
    
    void swap(vector<int> &nums, int index1, int index2) {
        nums[index1] = nums[index1] ^ nums[index2];
        nums[index2] = nums[index2] ^ nums[index1];
        nums[index1] = nums[index2] ^ nums[index1];
    }
};
