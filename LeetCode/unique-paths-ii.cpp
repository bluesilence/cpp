class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        
        if (m < 1 || n < 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        
        vector<vector<int> > pathCounts(m, vector<int>(n, 0));
        
        pathCounts[m-1][n-1] = 1;
        
        for (int i = m-2; i >= 0; i--) {    //Last column
            if (obstacleGrid[i][n-1] == 0)
                pathCounts[i][n-1] = 1;
            else
                break;  //All the following grids are blocked
        }
        
        for (int i = n-2; i >= 0; i--) {    //Last row
            if (obstacleGrid[m-1][i] == 0)
                pathCounts[m-1][i] = 1;
            else
                break;  //All the following grids are blocked
        }
        
        for (int i = m-2; i >= 0; i--) {
            for (int j = n-2; j >= 0; j--) {
                if (obstacleGrid[i][j] == 0)
                    pathCounts[i][j] = pathCounts[i+1][j] + pathCounts[i][j+1];
                else
                    pathCounts[i][j] = 0;
            }
        }
        
        return pathCounts[0][0];
    }
};
