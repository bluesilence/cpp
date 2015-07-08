class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //Best solution:
        //https://leetcode.com/discuss/20829/c-dp-solution
        //Define hp[i][j] to represent minimum needed HP at block (i, j)
        //Needed hp at [i][j] is min(hp[i+1][j], hp[i][j+1]) - dungeon[i][j]
        //If needed hp < 0, hp[i][j] = 1
        //Else, hp[i][j] = needed hp
        const int M = dungeon.size();
        const int N = dungeon[0].size();
        
        if (M < 1 || N < 1)
            return 1;
        
        vector<vector<int>> neededHP(M + 1, vector<int>(N + 1, INT_MAX));
        
        neededHP[M][N-1] = 1;
        neededHP[M-1][N] = 1;
        
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                neededHP[i][j] = min(neededHP[i+1][j], neededHP[i][j+1]) - dungeon[i][j];
                neededHP[i][j] = neededHP[i][j] <= 0 ? 1 : neededHP[i][j];
            }
        }
        
        return neededHP[0][0];
    }
};
