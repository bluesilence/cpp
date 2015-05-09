class Solution {
public:
    int mySqrt(int x) {
        int begin = 0;
        int end = x/2 + 1; //sqrt of x <= half of x
        while(begin <= end) {
            long mid = (begin + end) / 2;
            long long sq = mid * mid;
            
            if(sq == x)
                return mid;
            else if (sq < x)
                begin = mid + 1;
            else 
                end = mid - 1;            
       }
       
       //Because "begin = mid + 1", when the loop ends, begin tends to be > end
       return end;
    }
};
