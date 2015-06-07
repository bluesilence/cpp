class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        
        if (candidates.empty())
            return results;
        
        vector<int> result;
        
        //The requirement is that the elements in a combination must be in non-descending order
        sort(candidates.begin(), candidates.end());
        
        combinationCore(results, result, candidates, target, 0);
        
        return results;
    }

private:
    void combinationCore(vector<vector<int>> &results, vector<int> &result, vector<int> &candidates, int target, int index) {
        int i = index;
        while (i < candidates.size() && candidates[i] <= target) {    //Since candidates are sorted, target must be >= candidates[i] to form a combination
            //Select candidates[i]
            result.push_back(candidates[i]);
            
            if (candidates[i] == target) {
                results.push_back(result);
                result.pop_back();
                
                return; //Found 1 candidate == target, skip the following checks since the combinations will be duplicate
            } else {
                combinationCore(results, result, candidates, target - candidates[i], i + 1);
                result.pop_back();
                //Below is not needed, because L37 has moved i to next distinct number, and L33 has poped up candidates[i]
                //combinationCore(results, result, candidates, target, index + 1);
                
                i = moveToNextDistinctNumber(candidates, i);
                if (i < 0)  //No more distinct numbers
                    break;
            }
        }
    }
    
    int moveToNextDistinctNumber(vector<int> &candidates, int i) {
        if (i < 0) {
            return 0;
        } else if (i >= candidates.size()) {
            return -1;
        } else {
            int pre = candidates[i];
            int j = i + 1;
            while (j < candidates.size() && candidates[j] == pre) {
                j++;
            }
            
            if (j < candidates.size())
                return j;
            else
                return -1;
        }
    }
};
