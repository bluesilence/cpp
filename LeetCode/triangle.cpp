class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        //Similar to pascal's triangle
        //For the first/last element in a row, there is only 1 possible path: from previous row's first/last element
        //For the other elements, minPath[i] = min(minPath[i-1], minPath[i]), where minPath records the previous row's dp result
        if (triangle.empty() || triangle[0].empty())
            return 0;
            
        vector<int> minPaths;
        minPaths.push_back(triangle[0][0]);
        
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = i; j >= 0; j--) {
                if (j == i) {
                    minPaths.push_back(minPaths[j-1] + triangle[i][j]);
                } else if (j == 0) {
                    minPaths[j] += triangle[i][j];
                } else {
                    minPaths[j] = min(minPaths[j-1], minPaths[j]) + triangle[i][j];
                }
            }
        }
        
        int minTotal = numeric_limits<int>::max();
        
        for (int i = 0; i < minPaths.size(); i++) {
            if (minPaths[i] < minTotal) {
                minTotal = minPaths[i];
            }
        }
        
        return minTotal;
    }
};
