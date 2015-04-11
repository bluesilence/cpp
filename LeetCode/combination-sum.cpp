class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > results;
        
        if (candidates.empty())
            return results;
        
        vector<int> result;
        //Combination's numbers must appear in ascending order
        sort(candidates.begin(), candidates.end());
        combinationCore(candidates, results, result, target, 0);
        
        return results;
    }

private:
    void combinationCore(vector<int> &candidates, vector<vector<int> > &results, vector<int> &result, int target, int index) {
        for (int i = index; i < candidates.size() && candidates[i] <= target; i++) {
            result.push_back(candidates[i]);
            if (target == candidates[i]) {   //Found 1 combination
                results.push_back(result);
                result.pop_back();
                return; //Stop further recursion to avoid duplicate combinations
            } else {
                combinationCore(candidates, results, result, target - candidates[i], i); //Use candidate i
                result.pop_back();
            }
        }
    }
};
