class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //Similar to insertion sort
        //Fill the final array from large to small, so as to leave spaces to merge numbers
        int i1 = m - 1;
        int i2 = n - 1;
        int i = m + n - 1;
        
        while (i1 >= 0 && i2 >= 0) {
            if (nums1[i1] >= nums2[i2]) {
                nums1[i--] = nums1[i1--];
            } else {
                nums1[i--] = nums2[i2--];
            }
        }
        
        //If i1 >= 0, the numbers in nums1 before i1 are already sorted, no action needed
        //Merge the remainder of nums2
        while (i2 >= 0) {
            nums1[i--] = nums2[i2--]; 
        }
    }
};
