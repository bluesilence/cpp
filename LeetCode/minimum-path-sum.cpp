class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
            
        const int m = grid.size();
        const int n = grid[0].size();
        
        vector<vector<int> > sums(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sums[i][j] = grid[i][j];
            }
        }
        
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i < m-1 && j < n-1) {
                    sums[i][j] += min(sums[i+1][j], sums[i][j+1]);
                } else if (i < m-1) {
                    sums[i][j] += sums[i+1][j];
                } else if (j < n-1) {
                    sums[i][j] += sums[i][j+1];
                }
            }
        }
        
        return sums[0][0];
    }
};
