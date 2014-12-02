class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > results;
        vector<int> combination;
        
        combineCore(n, k, results, combination, 0, 1);
        return results;
    }
    
private:
    void combineCore(int n, int k, vector<vector<int> > &results, vector<int> &combination, int index, int start) {
        if (index == k) {
            results.push_back(combination);
        } else {
            for (int i = start; i <= n; i++) {
                combination.push_back(i);
                combineCore(n, k, results, combination, index + 1, i + 1);
                combination.pop_back();
            }
        }
    }
};
