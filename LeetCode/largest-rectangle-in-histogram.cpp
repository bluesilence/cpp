class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        const int N = height.size();
        
        int maxArea = 0;
        stack<int> ascendingHistogramIndices;
        height.push_back(0);    //sentinel
        
        for (int i = 0; i <= N; i++) {
            if (i > 0) {
                while (!ascendingHistogramIndices.empty() && height[i] < height[ascendingHistogramIndices.top()]) {
                    int lastHistogramIndex = ascendingHistogramIndices.top();
                    ascendingHistogramIndices.pop();
                    
                    maxArea = max(maxArea, height[lastHistogramIndex] * (ascendingHistogramIndices.empty() ? i : (i - ascendingHistogramIndices.top() - 1)));
                }
            }
            
            if (i < N) {
                ascendingHistogramIndices.push(i);
            }
        }
        
        return maxArea;
    }
};
