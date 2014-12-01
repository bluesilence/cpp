class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > results;
        vector<int> permutation;
        std::sort(S.begin(), S.end());
        subsetsCore(S, permutation, results, 0);
        
        return results;
    }
    
private:
    void subsetsCore(vector<int> &S, vector<int> &perm, vector<vector<int> > &results, int index) {
        if (index == S.size()) {
            if (results.empty() || results.end() == std::find(results.begin(), results.end(), perm))
                results.push_back(perm);
        } else {
            perm.push_back(S[index]);
            subsetsCore(S, perm, results, index + 1);
            perm.pop_back();
            subsetsCore(S, perm, results, index + 1);
        }
    }
};
