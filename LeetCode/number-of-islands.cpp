class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        //Start from each land on the grid to DFS
        //Mark each visited land as visited
        //Count the connected sub graph on the grid
        int count = 0;
        if (grid.empty() || grid[0].empty())
            return count;
            
        const int width = grid.size();
        const int height = grid[0].size();
        
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if ('1' == grid[i][j]) {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
    
private:
    void dfs(vector<vector<char>> &grid, int row, int col) {
        if (row >= grid.size() || col >= grid[0].size() || grid[row][col] != '1')
            return;
        
        grid[row][col] = '2';
        if (row+1 < grid.size() && grid[row+1][col] == '1')
            dfs(grid, row+1, col);
        
        if (row > 0 && grid[row-1][col] == '1')
            dfs(grid, row-1, col);
            
        if (col+1 < grid[0].size() && grid[row][col+1] == '1')
            dfs(grid, row, col+1);
            
        if (col > 0 && grid[row][col-1] == '1')
            dfs(grid, row, col-1);
    }
};
