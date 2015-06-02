class Solution {
public:
    int maxArea(vector<int>& height) {
        //Scan from both ends. Set initial max area to be the rectangle formed by the first and the last lines
        //If there are larger area, the the lines inbetween must be higher, since the width is decreasing
        if (height.size() < 2)
            return 0;
        
        int begin = 0;
        int end = height.size() - 1;
        
        int lastBegin = begin;
        int lastEnd = end;
        
        int max = 0;
        int tmpArea = 0;
        
        while (begin < end) {
            tmpArea = min(height[lastBegin], height[lastEnd]) * (lastEnd - lastBegin);
            if (tmpArea > max) {
                max = tmpArea;
            }
                    
            if (height[begin] < height[end]) {
                while (begin < end && height[begin] <= height[lastBegin]) {
                    begin++;
                }
                
                lastBegin = begin;
            } else {
                while (begin < end && height[end] <= height[lastEnd]) {
                    end--;
                }
                
                lastEnd = end;
            }
        }
        
        return max;
    }
};
