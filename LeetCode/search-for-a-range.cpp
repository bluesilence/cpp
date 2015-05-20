class Solution {
public:
    vector<int> searchRange(vector<int> A, int target) {
        vector<int> results(2, -1);
        
        if (A.empty())
            return results;
            
        int startPos = findLeftMost(A, target);
        int endPos = findRightMost(A, target);
        
        results[0] = startPos;
        results[1] = endPos;
        
        return results;
    }

private:
    int findLeftMost(vector<int> &A, int target) {
        if (A.empty())
            return -1;
        
        int begin = 0, end = A.size() - 1;
        int mid;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (target > A[mid]) {
                begin = mid + 1;
            } else {    //When target == A[mid], move left
                end = mid - 1;
            }
        }
        
        if (A[begin] == target) //Using begin to compare with target, is because begin is the most accurate position (L27)
            return begin;
        else
            return -1;
    }
    
    int findRightMost(vector<int> &A, int target) {
        if (A.empty())
            return -1;
        
        int begin = 0, end = A.size() - 1;
        int mid;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (target < A[mid]) {
                end = mid - 1;
            } else {    //When target == A[mid], move right
                begin = mid + 1;
            }
        }
        
        if (A[end] == target) //Using end to compare with target, is because end is the most accurate position (L49)
            return end;
        else
            return -1;
    }
};
