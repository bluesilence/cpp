class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > results;
        if (S.empty())
            return results;
        
        vector<int> result;
        sort(S.begin(), S.end());
        subsetsCore(results, result, S, 0);
        
        return results;
    }

private:
    void subsetsCore(vector<vector<int> > &results, vector<int> &result, vector<int> &S, int begin) {
        if (begin == S.size()) {
            results.push_back(result);
        } else {
            result.push_back(S[begin]);
            subsetsCore(results, result, S, begin+1);
            result.pop_back();
            subsetsCore(results, result, S, begin+1);
        }
    }
};
