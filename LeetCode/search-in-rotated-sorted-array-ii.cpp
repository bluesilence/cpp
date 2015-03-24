class Solution {
public:
    bool search(int A[], int n, int target) {
        if (!A || n < 1)
            return false;
           
        int front = 0, end = n-1;
        int mid;
        while (front <= end) {
            mid = (front + end) / 2;
            if (target == A[mid]) {
                return true;
            } else if (A[front] < A[mid]) {
                if (target >= A[front] && target < A[mid])  //target exists in A[front, mid-1]
                    end = mid - 1;
                else   //target exists in A[mid+1, end]
                    front = mid + 1;
            } else if (A[front] > A[mid]) {
                if (target > A[mid] && target <= A[end])  //target exists in A[mid+1, end]
                    front = mid + 1;
                else    //target exists in A[front, mid-1]
                    end = mid - 1;
            } else {    //A[front] == A[mid], cannot determine the order
                front++;
            }
        }
        
        return false;
    }
};
