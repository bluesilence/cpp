class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        //Binary search
        if (n < 1)
            return 0;
        
        return binarySearch(A, n, target);
    }

private:
    int binarySearch(int A[], int n, int target) {
        int start = 0, end = n - 1;
        int mid = 0;
        while (start <= end) {
            mid = (start + end) / 2;
            if (A[mid] < target)
                start = mid + 1;
            else if (A[mid] > target)
                end = mid - 1;
            else
                return mid;
        }
        
        return start;
    }
};
