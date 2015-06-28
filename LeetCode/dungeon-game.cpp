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
        
        vector<vector<int>> hp(M + 1, vector<int>(N + 1, INT_MAX));
        
        hp[M][N-1] = 1;
        hp[M-1][N] = 1;
        
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                int need = min(hp[i+1][j], hp[i][j+1]) - dungeon[i][j];
                hp[i][j] = need <= 0 ? 1 : need;
            }
        }
        
        return hp[0][0];
    }
};
