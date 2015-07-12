class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> results;
        const int N = nums.size();
        
        if (N < 2) {
            return results;
        }
        
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        
        int begin = 0;
        int end = N - 1;
        
        while (begin < end) {
            long long sum = copy[begin] + copy[end];    //Watch out for overflows
            
            if (sum < target) {
                begin++;
            } else if (sum > target) {
                end--;
            } else {
                break;
            }
        }
        
        if (begin < end) {  //Found 1 pair
            for (int i = 0; i < N; i++) {
                if (nums[i] == copy[begin] || nums[i] == copy[end]) {
                    results.push_back(i + 1);
                }
            }
        }
        
        return results;
    }
};
