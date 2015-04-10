class Solution {
public:
    int findLeftMost(int A[], int n, int target) {
        if(n == 0)
            return -1;
            
        int left = 0;
        int right = n-1;
        while (left <= right) {  //q1
            int mid = (left+right) / 2;
            if (A[mid] < target)    //q2
                left = mid+1;
            else
                right = mid-1;
        }
        
        if(A[left] == target) //q3
            return left;
            
        return -1;
    }
    
    int findRightMost(int A[], int n, int target) {
        if(n == 0)
            return -1;
            
        int left = 0;
        int right = n-1;
        while (left <= right) { //q1
            int mid = (left+right) / 2;
            if (A[mid] > target) //q2
                right = mid-1;
            else
                left = mid+1;
        }
        
        if(A[right] == target) //q3
            return right;
            
        return -1;
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        int startPos = findLeftMost(A, n, target);
        int endPos = findRightMost(A, n, target);
        
        vector<int> ans(2);
        ans[0] = startPos;
        ans[1] = endPos;
        
        return ans;
    }
};
