//The solution passes in VS, but fails in LeetCode...
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        
        const int height = matrix.size();
        const int width = matrix[0].size();
        
        vector<vector<int>> h(height, vector<int>(width, 0));
        
        int maxArea = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                h[i][j] = matrix[i][j] == '1'? 1 : 0;
                if (i > 0 && h[i][j] > 0) //Each col as a bar
                    h[i][j] += h[i-1][j];
                
                if (j == width - 1)
                    maxArea = max(maxArea, calculateMaxArea(h[i])); //Calculate max areas of bars based on row i
            }
        }
        
        return maxArea;
    }

private:
    int calculateMaxArea(vector<int> h) {
        stack<int> s;   //Store the index of each bar
        int maximum = 0;
        int i = 0;
        
        while (i <= h.size()) {
            if (s.empty() || i < h.size() && h[i] >= h[s.top()]) {  //Preserve ascending bars
                s.push(i++);
            } else {
				        int j = s.top();
                s.pop();
                int height = h[j];
                //Important: the width is determined by i and the top of stack after poping j, not (i - j)
                int width = s.empty() ? i : (i - s.top() - 1);
                maximum = max(maximum, height * width);
            }
        }
        
        return maximum;
    }
};
