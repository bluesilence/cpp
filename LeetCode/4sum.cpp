class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        const int size = nums.size();
        if (size < 4)
            return results;
        
        sort(nums.begin(), nums.end());
        
        vector<int> result(4);
        set<string> uniqueResults;
        long long sum = target;
        
        for (int i = 0; i + 3 < size; i++) {
            result[0] = nums[i];
            for (int j = i + 1; j + 2 < size; j++) {
                result[1] = nums[j];
                int begin = j + 1;
                int end = size - 1;
                sum = target - result[0] - result[1];
                while (begin < end) {
                    long long tmpSum = nums[begin] + nums[end];
                    if (tmpSum == sum) {
                        string s;
                        s += nums[i];
                        s += nums[j];
                        s += nums[begin];
                        s += nums[end];
                        if (uniqueResults.find(s) == uniqueResults.end()) {
                            uniqueResults.insert(s);
                            result[2] = nums[begin];
                            result[3] = nums[end];
                            results.push_back(result);
                        }
                        
                        begin++;
                        end--;
                    } else if (tmpSum < sum) {
                        begin++;
                    } else {
                        end--;
                    }
                }
            }
        }
        
        return results;
    }
};
