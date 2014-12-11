class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        int r = grid.size(), c = grid[0].size();
        
        //Initialization
        //the 0th row and 0th col are boundaries with value 0
        int **mins = new int*[r + 1];
        for (int i = 0; i <= r; i++) {
            mins[i] = new int[c + 1];
			memset(mins[i], 0, sizeof(int) * (c + 1));
        }
        
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                mins[i][j] += grid[i-1][j-1];
                
                if (i > 1 && j > 1 || i == 1 && j == 1)
                    mins[i][j] += min(mins[i-1][j], mins[i][j-1]);
                else if (1 == i && j > 1)
                    mins[i][j] += mins[i][j-1]; //Can only add from left
                else if (1 == j && i > 1)
                    mins[i][j] += mins[i-1][j]; //Can only add from top
            }
        }
        
        int sum = mins[r][c];
        
        //Clean-up
        for (int i = 0; i <= r; i++) {
            delete mins[i];
        }
        
        delete mins;
        
        return sum;
    }
};
