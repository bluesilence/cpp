class Solution {
public:
    bool search(vector<int> A, int n) {
        if (A.empty())
            return false;
           
        int start = 0, end = A.size() - 1;
        int mid;
        
        while (start <= end) {
            mid = (start + end) / 2;
            if (n == A[mid]) {
                return true;
            }
            
            if (A[mid] > A[start]) {
                if (n >= A[start] && n < A[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else if (A[mid] < A[end]) {
                if (n > A[mid] && n <= A[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else if (A[mid] == A[start]) {
                start++;
            } else if (A[mid] == A[end]) {
                end--;
            } else {    //Input array is invalid
                break;
            }
        }
        
        return false;
    }
};
