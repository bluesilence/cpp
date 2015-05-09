class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        
        permuteCore<int>(results, nums, 0);
        
        return results;
    }

private:
    template<class T>
    void permuteCore(vector<vector<T>> &results, vector<T> &nums, unsigned int start) {
        if (start == nums.size()) {
            results.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            swap(nums, i, start);
            permuteCore(results, nums, start+1);
            swap(nums, i, start);
        }
    }

    template<class T>
    void swap(vector<T> &nums, unsigned int i, unsigned int j) {
        T tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
