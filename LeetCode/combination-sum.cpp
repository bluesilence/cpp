class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > results;
        if (candidates.empty())
            return results;
        
        //Sort so that duplicate elements will appear in adjacent
        sort(candidates.begin(), candidates.end());
        
        vector<int> result;
        
        combinationCore(results, result, candidates, target, 0);
        
        return results;
    }

private:
   void combinationCore(vector<vector<int> > &results, vector<int> &result, vector<int> &candidates, int target, int index) {
       for (int i = index; i < candidates.size() && candidates[i] <= target; i++) {
           result.push_back(candidates[i]);
           if (target == candidates[i]) {
               results.push_back(result);
               result.pop_back();
               return;  //Avoid duplicate results
           } else {
               combinationCore(results, result, candidates, target - candidates[i], i);
           }
           
           result.pop_back();
       }
   }
};
