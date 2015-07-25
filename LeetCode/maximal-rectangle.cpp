class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        
        const int H = matrix.size();
        const int W = matrix[0].size();
        
        //leftBegin[i] stands for the leftmost index for the consecutive '1's before i (including i)
        vector<int> leftBegin(W, 0);
        
        //rightEnd[i] stands for the rightmost index for the consecutive '1's after i (including i)
        vector<int> rightEnd(W, W - 1);
        
        //height[i] stands for the max height of consecutive '1's above i (including i)
        vector<int> height(W, 0);
        
        int maxArea = 0;
        
        for (int i = 0; i < H; i++) {
            //Narrow down the 
            int currentLeft = 0;
            int currentRight = W - 1;
            
            for (int j = 0; j < W; j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            
            for (int j = 0; j < W; j++) {
                if (matrix[i][j] == '1') {
                    leftBegin[j] = max(leftBegin[j], currentLeft);
                } else {    //If matrix[i][j] == '0', the leftBegin should be minimum so as to not affect the range of '1's
                    leftBegin[j] = 0;
                    currentLeft = j + 1;
                }
            }
            
            for (int j = W - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    rightEnd[j] = min(rightEnd[j], currentRight);
                } else {    //If matrix[i][j] == '0', the rightEnd should be maximum so as to not affect the range of '1's
                    rightEnd[j] = W - 1;
                    currentRight = j - 1;
                }
            }
            
            for (int j = 0; j < W; j++) {
                maxArea = max(maxArea, (rightEnd[j] - leftBegin[j] + 1) * height[j]);
            }
        }
        
        return maxArea;
    }
};
