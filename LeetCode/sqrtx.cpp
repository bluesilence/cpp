class Solution {
public:
    int sqrt(int x) {
        if (x <= 1)
            return x;
            
        //Binary search
        int start = 0;
        int end = x;
        int mid;
        
        while ((end - start) > 1) { //If (end-start) == 1, then mid = start, the loop will be infinite
            mid = (start + end) / 2;
            if (mid == x/mid)
                return mid;
            else if (mid < x/mid)
                start = mid;
            else
                end = mid;
        }
        
        return start;
    }
};
