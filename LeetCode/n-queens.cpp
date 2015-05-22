class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        if (n < 1)
            throw "Queens' number must be positive integer.";
            
        vector<vector<string> > results;
        
        //Each element's index stands for queen in one column, each element's value stands for queen's row
        vector<int> positions(n, 0);
        
        vector<string> result(n);
        
        permutation(results, result, positions, n, 0);
        
        return results;
    }

private:
    void permutation(vector<vector<string> > &results, vector<string> &result, vector<int> &positions, const int n, int queenCol) {
        if (queenCol == n) {    //Find one solution
            fillResult(positions, result);
            results.push_back(result);
        } else {
            for (int i = 0; i < n; i++) {
                positions[queenCol] = i;
                
                if (isValid(queenCol, positions)) {
                    permutation(results, result, positions, n, queenCol + 1);
                }
            }
        }
    }
    
    //Check if 1 queen is valid against queens in columns before her, which are already permuted
    bool isValid(int col, vector<int> &positions) {
        if (col < 0 || col >= positions.size())
            return false;
            
        //Check diagonals
        for (int i = 0; i < col; i++) {
            if (positions[i] == positions[col] || abs(positions[i] - positions[col]) == (col - i))
                return false;
        }
        
        return true;
    }
    
    void fillResult(vector<int> &positions, vector<string> &result) {
        std::fill(result.begin(), result.end(), string(result.size(), '.'));    //Initialization
            
        int row, col;
        
        for (int i = 0; i < positions.size(); i++) {
            row = positions[i];
            col = i;
            result[row][col] = 'Q';
        }
    }
};
