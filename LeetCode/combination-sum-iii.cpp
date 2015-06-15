class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        
        if (n < 1 || k < 1)
            return results;
        
        vector<int> result;
        combinationCore(results, result, k, n);
        
		return results;
    }

private:
    void combinationCore(vector<vector<int>> &results, vector<int> &result, int k, int n) {
        if (result.size() == k) {
            if (n == 0) {
                results.push_back(result);
            }
        } else {
            int start = result.empty() ? 1 : result.back() + 1;
            for (int i = start; i <= 9 && i <= n; i++) {
                result.push_back(i);
                combinationCore(results, result, k, n - i);
                result.pop_back();
            }
        }
    }
};
