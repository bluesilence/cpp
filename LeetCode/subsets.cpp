class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > results;
        
        if (S.empty())
            return results;
        
        vector<int> result;
        
        // The answer enforce an order, so need to sort S first
        sort(S.begin(), S.end());
        selectSubset(S, results, result, 0);
        
        return results;
    }

private:
    void selectSubset(vector<int> &S, vector<vector<int> >& results, vector<int> &result, int index) {
        if (index == S.size()) {
            results.push_back(result);
        } else {
            selectSubset(S, results, result, index + 1);
            result.push_back(S[index]);
            selectSubset(S, results, result, index + 1);
            result.pop_back();
        }
    }
};
