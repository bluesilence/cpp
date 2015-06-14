class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        
        const int height = matrix.size();
        const int width = matrix[0].size();
        
        vector<vector<int>> barHeights(height, vector<int>(width, 0));
        int maxArea = 0;
        
        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                barHeights[row][col] = matrix[row][col] - '0';
                if (row > 0 && barHeights[row][col] == 1) { //Can form a bar with previous rows
                    barHeights[row][col] += barHeights[row-1][col];
                }
            }
            
            maxArea = max(maxArea, calculateMaxArea(barHeights[row]));
        }
        
        return maxArea;
    }
    
private:
    int calculateMaxArea(vector<int> &heights) {
        int maxArea = 0;
        
        stack<int> indices;
        
        for (int i = 0; i < heights.size(); i++) {
            if (indices.empty() || heights[i] >= heights[indices.top()]) { //Continue ascending sequence
                indices.push(i);
            } else {
                //Pop previous indices until it can form ascending sequence with heights[i]
                while (!indices.empty() && heights[indices.top()] > heights[i]) {
                    int j = indices.top();
                    indices.pop();
                    int width = indices.empty() ? i : i - indices.top() - 1;
                    maxArea = max(maxArea, width * heights[j]);
                }

		indices.push(i);	//Form a new ascending sequence with heights[i]
            }
        }
        
        //For the last ascending sequence
        int i = heights.size();
        while (!indices.empty()) {
            int j = indices.top();
            indices.pop();
            int width = indices.empty() ? i : i - indices.top() - 1;
            maxArea = max(maxArea, width * heights[j]);
        }
        
        return maxArea;
    }
};
