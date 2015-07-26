class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        const int N = N1 + N2;
        
        //k starts from 1
        if (N & 0x01) {
            return findKthSmallest(nums1, nums2, 1 + N / 2);
        } else {
            return (findKthSmallest(nums1, nums2, N / 2) + findKthSmallest(nums1, nums2, 1 + N / 2)) / 2;
        }
    }

private:
    double findKthSmallest(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.size() > nums2.size())
            return findKthSmallest(nums2, nums1, k);
        
        return findKthSmallest(nums1, nums2, 0, 0, k);
    }
    
    double findKthSmallest(vector<int>& nums1, vector<int>& nums2, int begin1, int begin2, int k) {
        if (begin1 == nums1.size()) {
            return nums2[begin2 + k - 1];
        }
        
        if (begin2 == nums2.size()) {
            return nums1[begin1 + k - 1];
        }
        
        if (k == 1) {
            return min(nums1[begin1], nums2[begin2]);
        }
        
        int len1 = min((int)nums1.size() - begin1, k / 2);
        int len2 = k - len1;
        
        if (nums1[begin1 + len1 - 1] < nums2[begin2 + len2 - 1]) {
            return findKthSmallest(nums1, nums2, begin1 + len1, begin2, k - len1);
        } else if (nums1[begin1 + len1 - 1] > nums2[begin2 + len2 - 1]) {
            return findKthSmallest(nums1, nums2, begin1, begin2 + len2, k - len2);
        } else {
            return nums1[begin1 + len1 - 1];
        }
    }
};
