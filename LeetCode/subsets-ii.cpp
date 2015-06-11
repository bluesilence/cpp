class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> results;
        
        if (nums.empty())
            return results;
        
        //Sort so that results appear in non-descending order
        sort(nums.begin(), nums.end());
        
        vector<int> result;
        set<string> distinctResults;
        
        pickCore(results, result, distinctResults, nums, 0);
        
        return results;
    }

private:
    void pickCore(vector<vector<int>> &results, vector<int> &result, set<string> &distinctResults, vector<int> &nums, int start) {
        if (start == nums.size()) {
            string s = formString(result);
            if (distinctResults.find(s) == distinctResults.end()) {
                results.push_back(result);
                distinctResults.insert(s);
            }
        } else {
            result.push_back(nums[start]);
            pickCore(results, result, distinctResults, nums, start + 1);
            result.pop_back();
            pickCore(results, result, distinctResults, nums, start + 1);
        }
    }
    
    string formString(vector<int> &result) {
        string s = "";
        for (int i = 0; i < result.size(); i++) {
            s += result[i];
        }
        
        return s;
    }
};
