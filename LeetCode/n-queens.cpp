class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > results;
        if (n < 1)
            return results;
        
        vector<int> oneSolution(n, -1);
        
        //Initialize each row, queen id starts from 0
        for (int i = 0; i < n; i++) {
            oneSolution[i] = i;
        }
        
        permute(results, oneSolution, n, 0);
        
        return results;
    }
    
private:
    void permute(vector<vector<string> > &results, vector<int> &oneSolution, int n, int index) {
        if (index >= n) {
            if (isValid(oneSolution, n))
                results.push_back(print(oneSolution));
                
            return;
        }
        
        for (int i = index; i < n; i++) {
            swap(oneSolution, i, index);
            permute(results, oneSolution, n, index + 1);
            swap(oneSolution, i, index);
        }
    }
    
    bool isValid(vector<int> &solution, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {   //Check diagonal
                if (j - i == solution[j] - solution[i] || i - j == solution[j] - solution[i])
                    return false;
            }
        }
        
        return true;
    }
    
    void swap(vector<int> &solution, int col1, int col2) {
        if (col2 == col1 || col1 < 0 || col2 < 0 || col1 >= solution.size() || col2 >= solution.size())
            return;
            
        char tmp = solution[col1];
        solution[col1] = solution[col2];
        solution[col2] = tmp;
    }
    
    vector<string> print(vector<int> solution) {
        vector<string> results;
        for (int i = 0; i < solution.size(); i++) {
            string result = "";
            int col = solution[i];  //The column of Queen in this row
            for (int j = 0; j < solution.size(); j++) { //Print one row
                if (j == col) {
                    result += 'Q';
                } else {
                    result += '.';
                }
            }
            
            results.push_back(result);
        }
        
        return results;
    }
};
