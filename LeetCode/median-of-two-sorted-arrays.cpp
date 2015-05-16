class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int len1 = nums1.size();
        const int len2 = nums2.size();
        
        const int len = len1 + len2;
        //K starts from 1 to avoid negative array index (len/2 - 1)
        if (len & 0x01 == 1) {
            return findKth(nums1, 0, nums2, 0, len/2 + 1);
        } else {
            return (findKth(nums1, 0, nums2, 0, len/2) + findKth(nums1, 0, nums2, 0, len/2 + 1)) / 2;
        }
    }

private:
    double findKth(vector<int> &nums1, int begin1, vector<int> &nums2, int begin2, int k) {
        // The length of nums1 should be less than that of nums2
        if (nums1.size() > nums2.size())
            return findKth(nums2, begin2, nums1, begin1, k);
        
        if (begin1 == nums1.size())
            return nums2[begin2 + k - 1];
            
         if (begin2 == nums2.size())
            return nums1[begin1 + k - 1];
            
        if (k == 1)
            return min(nums1[begin1], nums2[begin2]);
        
        //The kth number of the merged vector must exist in the (1~kth numbers of nums1) plus the (1~kth numbers of nums2)
        //Use binary search, to locate the (k/2)th number, we know it must be in either nums1[1...k/2] or nums2[1...k/2]
        //If nums1[k/2] < nums2[k/2], in the merged vector of nums1[1...k/2] and nums2[1...k/2], the kth should exist in [nums1[k/2] + 1, nums2[k/2]], so we can exclude nums1[1...k/2]
        //set k <- k/2, recursively call findKth(nums1, begin1 + k/2, num2, begin2, k/2)
        //Else, discard nums2[1...k/2]
        //Once one of the vectors reaches its end, return the remaining kth element in the other vector
        int partition1 = min(k/2, int(nums1.size() - begin1));
        int partition2 = k - partition1;
        if (nums1[begin1 + partition1 - 1] < nums2[begin2 + partition2 - 1]) {
            return findKth(nums1, begin1 + partition1, nums2, begin2, k - partition1);
        } else if (nums1[begin1 + partition1 - 1] > nums2[begin2 + partition2 - 1]) {
            return findKth(nums1, begin1, nums2, begin2 + partition2, k - partition2);
        } else {
            return nums1[begin1 + partition1 - 1];
        }
    }
};
