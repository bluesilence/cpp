class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> results;
        
        if (numRows < 1) {
            return results;
        }
            
        vector<int> currentRow;
        
        for (int i = 1; i <= numRows; i++) {
            for (int j = 0; j < i; j++) {
                if (j == 0 || j == i - 1) { //First or last number of a row
                    currentRow.push_back(1);
                } else {
                    currentRow.push_back(results[i-2][j-1] + results[i-2][j]);
                }
            }
            
            results.push_back(currentRow);
            
            currentRow.clear();
        }
        
        return results;
    }
};
