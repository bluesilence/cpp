class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        if (n < 1 || k < 1 || k > n)
            return results;
        
        vector<int> result;
        int i = 1;
        combineCore(results, result, n, i, k);
        
        return results;
    }

private:
    void combineCore(vector<vector<int>> &results, vector<int> &result, int n, int i, int count) {
        if (n - i + 1 < count)  //Remaining numbers are not enough
            return;
        
        if (count == 0) {
            results.push_back(result);
            return;
        }
        
        result.push_back(i);
        combineCore(results, result, n, i + 1, count - 1);
        result.pop_back();
        combineCore(results, result, n, i + 1, count);
    }
    
};
