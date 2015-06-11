class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        if (height.empty())
            return 0;
        
        //sentinal
        height.push_back(0);
        
        int maxArea = 0;
        int tmpArea = 0;
        
        stack<int> beginIndices;
        
        for (int i = 0; i <= height.size(); i++) {
            if (beginIndices.empty() || height[i] >= height[beginIndices.top()]) {
                beginIndices.push(i);
            } else {
                while (!beginIndices.empty() && height[i] < height[beginIndices.top()]) {   //Otherwise, beginIndices.top() and i can form another ascending sequence
                    int beginIndex = beginIndices.top();
                    beginIndices.pop();
                    int w = beginIndices.empty() ? i : (i - beginIndices.top() - 1);
                    
                    tmpArea = w * height[beginIndex];
                    maxArea = max(maxArea, tmpArea);
                }
                
                beginIndices.push(i);
            }
        }
        
        height.pop_back();
        
        return maxArea;
    }
};
