class Solution {
public:
    int trap(vector<int>& height) {
        //The height of water trapped at each x unit is determined by min(leftSummit, rightSummit) - currentElevation
        //Left/Right summit is the highest elevation from the left/right of the map to currentElevation
        const int n = height.size();
        
        if (n < 1)
            return 0;
            
        vector<int> leftSummit(n, 0);
        vector<int> rightSummit(n, 0);
        
        leftSummit[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftSummit[i] = max(leftSummit[i-1], height[i]);
        }
        
        rightSummit[n-1] = height[n-1];
        for (int i = n - 2; i >= 0; i--) {
            rightSummit[i] = max(rightSummit[i+1], height[i]);
        }
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max(0, min(leftSummit[i], rightSummit[i]) - height[i]);
        }
        
        return sum;
    }
};
